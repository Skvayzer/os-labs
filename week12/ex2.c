#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <linux/input-event-codes.h>

int main(void){
    char* dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";

    int fd = open(dev, O_RDONLY);
    if (fd < 0)
        exit(EXIT_FAILURE);
    struct input_event evt;
    while(1){
        ssize_t b = read(fd, &evt, sizeof(evt));
        if(evt.type == EV_KEY && evt.value != 2){
            if(evt.value){
                printf("PRESSED ");
            }else{
                printf("RELEASED ");

            }
            printf("%x (%d)\n", evt.code, evt.code);
            fflush(stdout);

        }
    }
    exit(EXIT_SUCCESS);
}
