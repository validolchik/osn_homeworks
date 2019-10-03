#include <stdio.h>
#include <stdlib.h>

int *realloc_(int* array, int new_size, int old_size){
	int *new_array = malloc(new_size*sizeof(int));
	if(array == NULL || old_size == 0) return new_array;
	if(new_size == 0){
		free(array);
		return NULL;
	}
	if(new_size > old_size){
		for(int i = 0; i < old_size; i++){
			new_array[i] = array[i];
		}
	}else{
		for(int i = 0; i < new_size; i++){
			new_array[i] = array[i];
		}
	}
	return new_array;
}

int main(int argc, char const *argv[])
{
	int n;

	printf("Write n: \n");
	scanf("%d", &n);

	int *arr = realloc_(NULL, n, 0);

	for (int i = 0; i < n; ++i)
	{
		arr[i] = i;
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d \n", arr[i]);
	}

	int n1;
	printf("Write n1: \n");
	scanf("%d", &n1);

	arr = realloc_(arr, n1, n);
	for (int i = 0; i < n1; ++i)
	{
		printf("%d \n", arr[i]);
	}

	int n2;
	printf("Write n2: \n");
	scanf("%d", &n2);

	arr = realloc_(arr, n2, n1);
	for (int i = 0; i < n2; ++i)
	{
		printf("%d \n", arr[i]);
	}

	arr = realloc_(arr, 0, n2);

	return 0;
}