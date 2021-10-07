#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// i've got all zeros in si and so fields because the size of my swap partition is 0 :^)
// i should've made it while installing manjaro linux
// but i suppose at each iteration of for loop si should increase, because i allocate too much memory,
// and in the end of each iteration i free memory, which increases so (swap out) and
// si (swap in) goes back down to 0
int main(){
    for(int i=0;i<10;i++){
        int* a = malloc(10*1024*1024*sizeof(char));
        memset(a, 0, 10*1024*1024);
        sleep(1);
        free(a);
    }


    return 0;
}
