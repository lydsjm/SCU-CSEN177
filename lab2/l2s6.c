/*
Name: Lydia Myla
Date: 10/1/2024
Title: Lab 2 - Step 6
Description: rewrite the program to use threads instead of processes
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void* print_thread(void* arg) {
    int n = *((int*)arg);
    for (int i = 0; i < 100; i++) {
        printf("Thread %p: %d\n", (void*)pthread_self(), i);
        usleep(n);
    }
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s n in microseconds \n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    pthread_t thread1, thread2;

    printf("\nBefore Creating Threads\n");

    pthread_create(&thread1, NULL, print_thread, &n);
    pthread_create(&thread2, NULL, print_thread, &n);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
