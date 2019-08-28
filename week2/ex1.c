#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, char const *argv[])
{
	int a = INT_MAX;
	float f = FLT_MAX;
	double d = DBL_MAX;

	printf("Max value of integer = %d\n", a);
	printf("Max value of float = %f\n", f);
	printf("Max value of double = %f\n", d);

	printf("Size of integer is %d\n", sizeof(a));
	printf("Size of float is %d\n", sizeof(f));
	printf("Size of double is %d\n", sizeof(d));
	return 0;
}