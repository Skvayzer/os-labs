#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define N 10

int buffer[N];
int position=0;
int bConsumerSleeping=0, bProducerSleeping=1;

void printBuffer(){
    printf("\nBuffer now: ");
    for(int i=0;i<N;i++){
        printf("%d ", buffer[i]);
        fflush(stdout);
    }
}
void* produce(void* args){
    while(1){
        if(bProducerSleeping){
            continue;
        }
        if(position>=N){
            bProducerSleeping = 1;
            bConsumerSleeping = 0;
            continue;
        }
        buffer[++position]=rand();
        printBuffer();
//         sleep(1);
    }
}

void* consume(void* args){
    while (1) {
        if(bConsumerSleeping){
            continue;
        }
        if(position<0){
            bProducerSleeping = 0;
            bConsumerSleeping = 1;
            continue;
        }
        buffer[position--] = 0;
        printBuffer();

//         sleep(1);
    }
}

int main(){
    pthread_t consumer, producer;

    pthread_create(&consumer, NULL, consume, NULL);
    pthread_create(&producer, NULL, consume, NULL);
    printBuffer();

    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);



}
