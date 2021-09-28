 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double avg(int* array, int size){
    double sum = 0;
    for(int i=0;i<size;i++){
        sum += array[i];
    }
    return sum/size;
}
void print(int** queue, int size){
    int wt[size];
    int tat[size];
    int ct = 0;
    int bursts = 0;

    for(int i=0;i<size;i++){
        printf("Process #%d\n", i+1);
        printf("Arrival time: %d\nBurst time: %d \n", queue[i][0], queue[i][1]);
        wt[i] = queue[0][0] + bursts - queue[i][0];
        bursts += queue[i][1];
        tat[i] = wt[i] + queue[i][1];
        ct = tat[i] + queue[i][0];
        printf("Waiting time: %d\nTurnaround time: %d\nCompletion time: %d\n\n\n", wt[i], tat[i], ct);
    }
    printf("Average waiting time: %lf\nAverage turnaround time: %lf\n", avg(wt, size), avg(tat, size));
}
int comp( const void *pa, const void *pb ) {
    const int *a = *(const int **)pa;
    const int *b = *(const int **)pb;
    return a[1] - b[1];
}
int main(){
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Write the number of processes, arrival and burst times into the file queue.txt like it's already done there\n");
    fp = fopen("queue.txt", "r");
    if (fp == NULL){
        printf("Write the number of processes, arrival and burst times into the file queue.txt like it's already done there\n");
        exit(EXIT_FAILURE);
    }
    int** queue;
    int size;
    int i = 0;
    int flag=1;

    while ((read = getline(&line, &len, fp)) != -1) {
        if(flag){
            size = atoi(line);
            queue = (int**) malloc(size * sizeof(int*));
            flag=0;
        }else{
            char* split = strtok(line, " ");
            queue[i] = (int*) malloc(2 * sizeof(int));
            int j=0;
            while(split != NULL && j<2){
                queue[i][j]=atoi(split);
                split = strtok(NULL, " ");
                j++;
            }
            i++;
        }

    }


    qsort(queue, size, sizeof queue[0], comp);
    print(queue, size);




    fclose(fp);
    if (line)
        free(line);


    return 0;
}
