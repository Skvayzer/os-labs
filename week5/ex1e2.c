 
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct{
    int thread_num;
    char text[50];
    pthread_t thread_id;
} thread_info;

void* job(void* args){
//     int* t = (int*) args;
    thread_info* t = (thread_info*)args;

    printf("Hello from Thread...%d\n", *t);
    printf("%s", t->text);
    pthread_t x = pthread_self();
    printf("%lu\n",x);
    pthread_exit(0);
}

int main(){
    pthread_t thread_id;
//     int t = 10;
    thread_info t_info;


    for(int i=0;i<N;i++){
        t_info.thread_id = thread_id;
        t_info.thread_num = i;
        sprintf(t_info.text, "Thread %d is created\n", t_info.thread_num);

        pthread_create(&thread_id,NULL, &job, &t_info);
        pthread_join(thread_id, NULL);

    }

    printf("Hello from main thread....");
    unsigned long x = pthread_self();
    printf("%lu\n", x);

    exit(EXIT_SUCCESS);
    //return 0;

    //gcc -pthread ex1.c
}
