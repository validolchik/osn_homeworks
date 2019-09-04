#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

void swap(int *a, int *b){
	int n = *a;
	*a = *b;
	*b = n;
}

// algorithm retrieved from https://en.wikipedia.org/wiki/Quicksort
int partition(int *arr, int l, int h){
	int pivot = arr[l + (h-l)/2];
	while(1){
		while(arr[l] < pivot){
			l += 1;
		}

		while(arr[h] > pivot){
			h -= 1;
		}

		if(l >= h){
			return h;
		}

		swap(&(arr[h]), &(arr[l]));

		l += 1;
		h -= 1;
	}
	return 0;
}

// quick sort algorithm
void quicksort(int *arr, int l, int h){
	if(l < h){
		int p = partition(arr, l, h);
		quicksort(arr, l, p);
		quicksort(arr, p+1, h);
	}
}

int main(int argc, char const *argv[])
{	
	int *arr = (int *) malloc(SIZE * sizeof(int));
	
	// initializing elements of array
	for(int i = 0; i < SIZE; i++){
		arr[i] = SIZE - i;
	}

	// printing all elements before sorting
	for(int i = 0; i < SIZE; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	// sorting
	quicksort(arr, 0, SIZE);

	// printing after sorting
	for(int i = 0; i < SIZE; i++){
		printf("%d ", arr[i]);
	}

	return 0;
}