#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
	int a = INT_MAX;
	float b = FLT_MAX;
	double c = DBL_MAX;
	printf("%d - integer of the size of %zu bytes\n", a, sizeof(a));
	printf("%f - float of the size of %zu bytes\n", b, sizeof(b));
	printf("%lf - double of the size of %zu bytes\n", c, sizeof(c));

}
