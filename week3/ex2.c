#include<stdio.h>

void swap(int *a, int *b){
	int n = *a;
	*a = *b;
	*b = n;
}

void bubble_sort(int *arr, int argc){
	// printf("Bubble sort\n");
	for(int i = 0; i < argc; i++){
		for(int y = 0; y < argc-1; y++){
			if(arr[y+1] < arr[y]){
				// printf("%d %d\n", arr[y+1], arr[y]);
				swap(&(arr[y+1]), &(arr[y]));
				// printf("%d %d\n", arr[y+1], arr[y]);
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	int arr[10]; // init  array of integers of size 10

	for(int i = 0; i < 10; i++){
		arr[i] = 10 - i; // init each element of array
	}

	for(int i = 0; i < 10; i++){
		printf("%d ", arr[i]); // print before sort
	}
	printf("\n");

	bubble_sort(arr, 10); // call of the sort function

	for(int i = 0; i < 10; i++){
		printf("%d ", arr[i]); // print after sorting
	}
	
	return 0;
}