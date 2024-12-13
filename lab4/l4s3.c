/*
Name: Lydia Myla
Date: Tuesday - 2:15 
Title: Lab 4 - Step 3
Description: remove the for loop from the example
*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h> 

#define num 1024

#define N num
#define L num
#define M num

#define NTHREADS N

pthread_t threads[NTHREADS];
int thread_args[NTHREADS];

double matrixA[N][M];
double matrixB[M][L];
double matrixC[N][L];


void *matrix_multiply(void *arg);

int main() {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
                 matrixA[i][j] = (double) rand() / RAND_MAX;
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < L; j++)
            matrixB[i][j] = (double) rand() / RAND_MAX;
    }

    for(int i = 0; i < NTHREADS; i++) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, matrix_multiply, (void *)&thread_args[i]);
    }

    for(int i = 0; i < NTHREADS; i++)
        pthread_join(threads[i], NULL);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < L; j++)
            printf("%.2f ", matrixA[i][j]);
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < L; j++)
            printf("%.2f ", matrixB[i][j]);
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < L; j++)
            printf("%.2f ", matrixC[i][j]);
        printf("\n");
    }
}

void *matrix_multiply(void *arg) {
    int row = *((int*) arg);

    for(int i = 0; i < L; i++ ) {
        double tmp = 0;
        for(int j = 0; j < M; j++ )
            tmp += matrixA[row][j] * matrixB[j][i];
        matrixC[row][i] = tmp;
    }

    pthread_exit(NULL);
}