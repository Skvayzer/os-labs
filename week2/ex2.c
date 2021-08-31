#include <stdio.h>
#include <string.h>

int main(void){
	char s[1000];
	fgets(s, 1000, stdin);
	for(int i = strlen(s)-1;i>=0;i--){
		printf("%c",s[i]);	
	}
	printf("\n");	
}
