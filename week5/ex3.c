#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_BUFFER_SIZE 999999

int full = 0, empty = 1, state_cons = 0, state_prod = 1;
/* 
0 - sleeping
1 - active
*/
int buffer = 0;
int msec = 0, trigger = 5; 
/* in msec-s; 
set to 1000 to reach one second between outputs 
(but you will see that the buffer already full, that is not true)
set trigger from 5 to 25 to see how buffer
flling and then the fatal race cond
*/
clock_t before; // "timer"

void *produce(void *id){
	while(1){
		if(!full && state_prod){
			buffer += 1;
		}
		if(buffer == MAX_BUFFER_SIZE){
			full = 1;
		}
		if(full){
			state_prod = 0;
		}else{
			state_prod = 1;
		}

		// timer to print every "trigger" mseconds
		clock_t difference = clock() - before;
		msec = difference * 1000 / CLOCKS_PER_SEC;
		if(msec >= trigger){
			before = clock();
			printf("state_cons %d state_prod %d buffer %d\n", state_cons, state_prod, buffer);
		}
	}
}

void *consume(void *id){
	// printf("consume\n");
	while(1){
		if(!empty && state_cons){
			buffer -= 1;
		}
		if(buffer == 0){
			empty == 1;
		}
		if(empty){
			state_cons = 0;
		}else{
			state_cons = 1;
		}
	}
}

int main(int argc, char *argv[]){
	pthread_t consumer, producer;
	int status_1, status_2;
	before = clock();

	status_2 = pthread_create(&consumer, NULL, consume, (void *)2);
	status_1 = pthread_create(&producer, NULL, produce, (void *)1);
	// pthread_join(producer, NULL);
	while(1){
		;
	}

	exit(NULL);
}