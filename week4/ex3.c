#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>


int main(){
    while(true){
        char command[50];
        printf("The commands have to be 50 length maximum\n");
        fgets(command,50,stdin);
        system(command);
    }
    return 0;
}



