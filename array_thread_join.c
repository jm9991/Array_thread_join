// CPP Program to find sum of array 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 

// size of array 20
#define size 20 

// maximum number of threads 
#define MAX_THREAD 2 

float a[] = { 1.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; 
float sum[2] = { 0 }; 
float part = 0; 

//The thread will execute in this function
void* runner(void* arg) 
{ 

	// Each thread computes sum of 1/2 of array 
	int thread_part = part++; 
	for (int i = thread_part * (size / 2); i < (thread_part + 1) * (size / 2); i++) 
		sum[thread_part] += a[i]; 
} 

// Driver Code 
int main() 
{ 
	// the thread identifier
	pthread_t threads[MAX_THREAD]; 

	// Creating 2 threads 
	for (int i = 0; i < MAX_THREAD; i++)
		pthread_create(&threads[i], NULL, runner, (void*)NULL); 

	// joining 2 threads, waiting for all 2 threads to complete 
	for (int i = 0; i < MAX_THREAD; i++) 
		pthread_join(threads[i], NULL); 

	// adding sum of 2 parts 
	float total_sum = 0; 
	for (int i = 0; i < MAX_THREAD; i++) 
		total_sum += sum[i]; 

	printf("sum = %.2f",total_sum);
	printf("\n");
	pthread_exit(0);
} 
