#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

#define NUMBER_OF_THREADS 10

void *print_hello_world(void *tid) {
	printf("Hello World. Greeting from thread %d\n", tid);
	pthread_exit(NULL);
}

int main() {
	printf("\n----------START PROGRAM-----------\n");
	pthread_t threads[NUMBER_OF_THREADS];

	for (int i = 0; i < NUMBER_OF_THREADS; ++i) {
		printf("Main here. Creating thread %d\n", i);
		int status = pthread_create(&threads[i], NULL, print_hello_world, (void *)i);

		if (status != 0) {
			printf("\nOops. pthread_Create returned error code %d\n", status);
			exit(-1);
		}

	}
	
	printf("\n----------END PROGRAM-----------\n");
	exit(NULL);
}
