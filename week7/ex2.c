#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int n;

	printf("Write n: \n");
	scanf("%d", &n);

	int *array = malloc(n * sizeof(int));

	for (int i = 0; i < n; ++i)
	{
		array[i] = i;
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d \n", array[i]);
	}

	free(array);
	return 0;
}