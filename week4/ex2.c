#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define N 5

int main(){
    printf("forking %d\n", getpid());
    for(int i=0;i<N;i++){
        int n = fork();
        sleep(5);
    }
    return 0;
}


