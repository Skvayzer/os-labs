#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct process {
    int arrival_time;
    int burst_time;
    int completion_time;
    int running_time;
};

double avg(int* array, int size){
    double sum = 0;
    for(int i=0;i<size;i++){
        sum += array[i];
    }
    return sum/size;
}
void print(struct process* queue, int size){
    int wt[size];
    int tat[size];
    int ct = 0;
    int bursts = 0;

    for(int i=0;i<size;i++){
        printf("Process #%d\n", i+1);
        printf("Arrival time: %d\nBurst time: %d \n", queue[i].arrival_time, queue[i].burst_time);
        wt[i] = queue[0].arrival_time + bursts - queue[i].arrival_time;
        bursts += queue[i].burst_time;
        tat[i] = wt[i] + queue[i].burst_time;
        ct = tat[i] + queue[i].arrival_time;
        printf("Waiting time: %d\nTurnaround time: %d\nCompletion time: %d\n\n\n", wt[i], tat[i], ct);
    }
    printf("Average waiting time: %lf\nAverage turnaround time: %lf\n", avg(wt, size), avg(tat, size));
}
int comp( const struct process* a, const struct process* b ) {

    return a->arrival_time - b->arrival_time;
}
int main(){
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Write the number of queue, arrival and burst times into the file queue.txt like it's already done there\n");
    fp = fopen("queue.txt", "r");
    if (fp == NULL){
        printf("Write the number of queue, arrival and burst times into the file queue.txt like it's already done there\n");
        exit(EXIT_FAILURE);
    }
    struct process* queue;
    int size;
    int i = 0;
    int flag=1;
    int quantum;
    printf("Type the quantum: ");
    scanf("%d", &quantum);
    printf("\n");

    while ((read = getline(&line, &len, fp)) != -1) {

        if(flag){
            size = atoi(line);
            queue = (struct process*) malloc(size * sizeof(struct process));
            flag=0;
        }else{
            char* split = strtok(line, " ");
            int j=0;
            while(split != NULL && j<2){
                if(j==0)
                    queue[i].arrival_time=atoi(split);
                else
                    queue[i].burst_time=atoi(split);

                split = strtok(NULL, " ");
                j++;
            }
            i++;
        }

    }



    // Average waiting time (WT) strongly depends on average turnaround time (TAT)
    // Because WT = TAT - BT, where bt is constant and does not depends on algorithm
    // So, they both represent same metrics.
    //
    // First Come, First Served algorithm will have large average TAT and WT if long jobs come first
    // They will execute firstly, postponing fast jobs, avr TAT and WT large
    //
    // Shortest Job First algorithm will have large average TAT and WT if there are a lot of long jobs
    // They will execute at last, so avr TAT and WT will became large.
    //
    // Round Robin algorithm designed to maximize avr TAT and WT.
    // It have best avr TAT in theory, but takes time to switch between queue in practice

    qsort(queue, size, sizeof queue[0], (__compar_fn_t) comp);
    print(queue, size);


    int current_time = 0;
    int num_of_complete_queue = 0;
    int num_of_queue = size;
    while (num_of_complete_queue != num_of_queue) {
        for (int i = 0; i < num_of_queue; ++i) {
            struct process *p = &queue[i];
            if (p->completion_time != -1) {
                // process complete
                continue;
            }
            // Run process for the max of quantum
            if (quantum + p->running_time < p->burst_time) {
                // Will not be complete after quantum
                int time_to_run = quantum;
                current_time += time_to_run;
                p->running_time += time_to_run;
            } else {
                // Complete now
                int time_to_run = p->burst_time - p->running_time;
                current_time += time_to_run;
                p->running_time += time_to_run;
                p->completion_time = current_time;
                num_of_complete_queue++;
            }
            // Go to next process in queue
        }
        // No new queue, start queue from beginning
    }

    fclose(fp);
    if (line)
        free(line);



    return 0;
}
