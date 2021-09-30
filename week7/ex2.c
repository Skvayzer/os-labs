#include <stdio.h>
#include <stdlib.h>

int main(){
    int* arr;
    int N;
    printf("Print N: ");
    scanf("%d", &N);
    printf("\n");
    arr = malloc(N * sizeof(int));
    for(int i=0;i<N;i++){
        arr[i]=i;
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
}
