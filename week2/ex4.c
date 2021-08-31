#include <stdio.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
};
int main(int argc, char *argv[]){
	int a, b;
    printf("Print two numbers to swap them:\n");
    scanf("%d",&a);
    scanf("%d",&b);

    swap(&a,&b);
    printf("These are your swapped numbers: %d %d \n", a, b);
}
