#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>
#include <stdio.h>

// the memory used increases because i don't free it hahaha
// but if i do it stays almost constant
int main(){
    for(int i=0;i<10;i++){
        struct rusage usage;
        int* a = malloc(10*1024*1024*sizeof(char));
        memset(a, 0, 10*1024*1024);
        getrusage(RUSAGE_SELF, &usage);
        printf("Memory usage: %ld kilobytes\n",
               usage.ru_maxrss);
        printf("SLEEP 1 SEC \n");
        sleep(1);
        //free(a);
    }


    return 0;
}

