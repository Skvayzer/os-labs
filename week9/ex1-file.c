#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct Page{
    int num;
    int clock_cycle;
};

struct Frame{
    struct Page page;
    unsigned char counter;

};


void aging_algorithm(struct Frame* frames, int space_size, struct Page page, int* R_bits){
    int lowest=1<<8;
    int lowest_index=-1;
    int min_page_number = frames[0].page.num;
    for(int i=0;i<space_size;i++){
        if(frames[i].counter<lowest || (frames[i].counter==lowest && min_page_number > frames[i].page.num)){
            lowest = frames[i].counter;
            min_page_number = frames[i].page.num;
            lowest_index=i;
        }
    }
    frames[lowest_index].page = page;
    frames[lowest_index].counter = 0;
    R_bits[lowest_index]=1;

}


int main(){
    int n, m;
    int hits=0;

    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;


    printf("Write the name of the input file\n");
    char file_name[100];
    scanf("%s", &file_name);
    fp = fopen(file_name, "r");
    if (fp == NULL){
        printf("File not found\n");
        exit(EXIT_FAILURE);
    }
    struct Frame* frames;
    struct Page* queue;


    int* R_bits = (int*) malloc(n * sizeof(int));
    int fillness=0;
    int tick=0;
    int i=0;
    while ((read = getline(&line, &len, fp)) != -1) {
        int num, clock_cycle;

        if(i==0){
            char* split = strtok(line, " ");
            n = atoi(split);
            split = strtok(NULL, " ");
            m = atoi(split);
            frames = (struct Frame*) malloc(n * sizeof(struct Frame));
            queue = (struct Page*) malloc(m * sizeof(struct Page));
            i++;
            continue;
        }else{
            char* split = strtok(line, " ");
            queue[i-1].clock_cycle = atoi(split);
            split = strtok(NULL, " ");
            queue[i-1].num = atoi(split);
        }

        i++;
    }
    for(i=0;i<m;i++){
//        printf("ADDING PAGE %d\n", queue[i].num);

        int flag=1;
        int tick_changed=0;
        if(tick!=queue[i].clock_cycle){
            tick = queue[i].clock_cycle;
            tick_changed=1;
            for(int k=0;k<n;k++){
                frames[k].counter = R_bits[k] << 7 | frames[k].counter >> 1;
                R_bits[k]=0;
            }
        }
//        printf("page: %d \n", queue[i].num);

        for(int j = 0;j<n;j++){
//            printf("page in frame: %d counter: %d\n", frames[j].page.num, frames[j].counter);

            if(frames[j].page.num == queue[i].num){
                (hits)++;
                flag=0;
//                printf("frame %d counter %d page %d \n", j, frames[j].counter, queue[i].num);
                R_bits[j]=1;
                printf("1\n");

            }
        }

        if(flag){
            printf("0\n");
            if(fillness < n){
//                printf("frame %d counter %d\n", fillness, frames[fillness].counter);
                frames[fillness].page=queue[i];
                frames[fillness].counter=0;
                R_bits[fillness]=1;

                fillness++;
//            printf("0\n");
//                continue;
            }else{
                flag=1;
                aging_algorithm(frames, n, queue[i], R_bits);
//            printf("0\n");
            }
        }

//        for(int j=0; j<n;j++){
//            printf("FRAMES: frame %d counter %d page %d \n", j+1, frames[j].counter, frames[j].page.num);
//        }

    }


    printf("%Lf\n", (long double) hits/(m-hits));

    return 0;
}
