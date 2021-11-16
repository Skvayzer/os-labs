//
// Created by cosmos on 11/11/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int* readLine(char* line, int* m){
    char* lineCopy = strdup(line);
    char* split = strtok(line, " ");
    int j=0;
    if((*m) == 0){
        while(split != NULL){
            (*m)++;
            split = strtok(NULL, " ");
        }

    }
    int* lineData = malloc((*m) * sizeof(int));
    split = strtok(lineCopy, " ");
    while(split != NULL && j<(*m)){
        lineData[j] = atoi(split);
        split = strtok(NULL, " ");
        j++;
    }
    free(lineCopy);
    return lineData;
}
int main(){
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("input.txt", "r");
    if (fp == NULL){

        exit(EXIT_FAILURE);
    }
    int n=0, m=0;

//     printf("Type the number of processes and the number of types of resources: \n");
//     scanf("%d", &n);
//     scanf("%d", &m);

    printf("\n");

    int* exists;
    int* available;



    int counter = 0;
    int process_counter = 0;
    int flag = 1;



    while ((read = getline(&line, &len, fp)) != -1) {
        if(strlen(line)>1){
            flag = 1;
            switch(counter){
                case 0:
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    n++;
                    break;
            }

        }else{
            if(flag) {
                flag = 0;
                counter++;
            }

        }

    }
    flag = 1;
    counter = 0;
    fclose(fp);
    fp = fopen("input.txt", "r");

    int** request = malloc(n * sizeof(int*));
    int** current = malloc(n * sizeof(int*));
    int* terminated = malloc(n * sizeof(int));
    for(int i=0;i<n;i++) terminated[i]=0;

    while ((read = getline(&line, &len, fp)) != -1) {
        if(strlen(line)>1){
            flag = 1;
            switch(counter){
                case 0:
                    exists = readLine(line, &m);
                    break;
                case 1:
                    available = readLine(line, &m);
                    break;
                case 2:
                    current[process_counter] = readLine(line, &m);
                    process_counter++;
                    break;
                case 3:
                    request[process_counter] = readLine(line, &m);
                    process_counter++;
                    break;
            }
        }else{
            if(flag) {
                flag = 0;
                counter++;
                process_counter = 0;
            }

        }

    }

//    for(int i=0;i<m;i++){
//        printf("%d ", exists[i]);
//    }
//    printf("\n\n");
//    for(int i=0;i<m;i++){
//        printf("%d ", available[i]);
//    }
//    printf("\n\n");
//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++){
//            printf("%d ", current[i][j]);
//
//        }
//        printf("\n");
//    }
//    printf("\n\n");
//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++){
//            printf("%d ", request[i][j]);
//
//        }
//        printf("\n");
//    }
//    printf("\n\n");

    printf("n: %d, m: %d \n", n, m);
    int deadlock = 0;
    for(int k=0;k<n;k++){
        int isAnyTerminated = 0;
        for(int i = 0; i<n; i++){
            if(terminated[i]) continue;
            flag = 1;
            for(int j=0;j<m;j++){
                if(available[j] < request[i][j]){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                for(int j=0;j<m;j++){
                    available[j] = available[j] + current[i][j];
                }
                terminated[i] = 1;
                isAnyTerminated = 1;
                break;
            }
        }
        if(!isAnyTerminated) {
            deadlock = 1;
            break;
        }
    }

    if(deadlock){
        printf("DEADLOCK!\nIndexes of the deadlocked processes:\n");
        for(int i=0;i<n;i++){
            if(!terminated[i]){
                printf("%d ", i);
            }
        }
    }else{
        printf("No deadlock's detected, everything's fine :^)\n");
    }
    printf("\n");

    fclose(fp);
    if (line)
        free(line);



    return 0;
}

