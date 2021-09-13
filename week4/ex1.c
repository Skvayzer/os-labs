#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
    printf("forking\n");
    int n = fork();
    if(n==0)
        printf("Hello from child [%d - %d]\n", getpid(),n);
    else
        printf("Hello from parent [%d - %d]\n", getpid(),n);
    return 0;
}
