/* 
# Name: Lydia Myla
# Date: 10/8/24
# Title: Lab 3 - Step 7 
# Description: fix for the program in step 6
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *go(void *);
#define NTHREADS 10
int thread_args[NTHREADS];
pthread_t threads[NTHREADS];
int main() {
    int i;
    for (i = 0; i < NTHREADS; i++) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, go, &thread_args[i]);
       // usleep(3000);
    }
    for (i = 0; i < NTHREADS; i++) {
	printf("Thread %d returned\n", i);
        pthread_join(threads[i],NULL);
    }
    printf("Main thread done.\n");
    return 0;
}
void *go(void *arg) {
    int i = *(int *)arg;
    //printf("Hello from thread %d with iteration %d\n", (int)pthread_self(), i);
    printf("Hello from thread %d with iteration %d\n",  (int)pthread_self(), *(int *)arg);
    return 0;
}

