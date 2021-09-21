#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10

char s[N];
int position;
int bConsumerSleeping, bProducerSleeping;

void* produce(void* args){
    while(1){
        if(bProducerSleeping){
            continue;
        }
        if(position==N){
            bProducerSleeping = 1;
            bConsumerSleeping = 0;
            continue;
        }
        buffer[position++]=i;

    }
}

void* consume(void* args){

}

int main(){
    pthread_t consumer, producer;

    //create consumer
    //create producer
    //create(..,NULL);



}
