#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <string.h>

int main(){
    while(true){
        char command[50];
        printf("Write a command (maximum length: 50)\n");
        fgets(command,50,stdin);
        if(strlen(command)>1){
            int splits=0;
        for(int i=0; i<strlen(command);i++){
            switch(command[i]){
                case ' ':
                case '\n':
                case '\t':
                    splits++;
                    break;
            }
        }
        char* token = strtok(command, " \n\t");

        char** args = malloc((splits + 2) * sizeof(char*));
        int i=0;
        while( token != NULL ){
            args[i]= malloc((strlen(token) + 1)*sizeof(char));
            strcpy(args[i], token);
//             printf( " %s\n", token );
            token = strtok( NULL, " \n\t" );
            i++;
        }
        args[splits]="\0";



        char* binary = malloc((5 + strlen(args[0]))*sizeof(char));
        strcat(binary, "/bin/");
        strcat(binary,args[0]);
        free(args[0]);
        args[0]=malloc((strlen(binary) + 1)*sizeof(char));
        strcpy(args[0],binary);
//         printf("%s\n",binary);


//         for(int i=0;i<splits;i++){
//             printf("%s\n",args[i]);
//         }

        if(fork()==0)
            execve(args[0],args, NULL);
        for(int i=0;i<splits;i++){
            free(args[i]);
        }
        free(args);
        }

    }

    return 0;
}




