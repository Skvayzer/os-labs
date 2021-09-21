#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10

int buffer[N];
int position=0;
int bConsumerSleeping, bProducerSleeping;

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
        buffer[position++]=rand();

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
    }
}

int main(){
    pthread_t consumer, producer;

    pthread_create(&consumer, NULL, consume, NULL);
    pthread_create(&producer, NULL, consume, NULL);

    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);



}
