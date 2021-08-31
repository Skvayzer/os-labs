#include <stdio.h>

int main(int argc, char *argv[]){
	int n;
	int stars=1;
    if (argc != 2) {
        printf("Please, add a number as a command line parameter\n");
        return 1;
    }
    sscanf(argv[1], "%d", &n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			printf(" ");
		}
		 for(int j=0;j<stars;j++){
                        printf("*");
                }
		 for(int j=0;j<n-i;j++){
                        printf(" ");
                }
        printf("\n");
		stars=stars+2;

		
	}
}
