//
// Created by valik on 28.08.2019.
//

#include <stdio.h>

void swap(int *a, int *b){
	int n = *a;
	*a = *b;
	*b = n;
}

int main(){
    int a, b;

    printf("Write first number: ");
    scanf("%d", &a);
    printf("Write second number: ");
    scanf("%d", &b);

	printf("Before swap: %d %d\n", a, b);

    swap(&a, &b);

    printf("After swap: %d %d\n", a, b);
    

    return 0;
}
