#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 64  // Default to 64 threads for demonstration
#define BUFFER_SIZE 10000

void *copy_file(void *arg) {
    char buffer[BUFFER_SIZE];
    FILE *fp_in, *fp_out;
    char **files = (char **)arg;  // Use the argument to pass input/output file names
    fp_in = fopen(files[0], "rb");
    fp_out = fopen(files[1], "wb");
    if (fp_in == NULL || fp_out == NULL) {
        perror("Error opening file");
        pthread_exit(NULL);
    }
    while (fread(buffer, sizeof(buffer), 1, fp_in)) {
        fwrite(buffer, sizeof(buffer), 1, fp_out);
    }

    fclose(fp_in);
    fclose(fp_out);
    free(files);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS];
    char *file_in = argv[1];  // Input file
    int num_threads = atoi(argv[3]);  // Number of threads
    char file_names [num_threads][20];
    // Create NUM_THREADS output files with names like copy1.out, copy2.out, etc.
    for (int i = 0; i < num_threads; i++) {
        // Dynamically allocate output file name
        // char *file_out = malloc(20);  // Output file name
        sprintf(file_names[i], "copy%d.out", i + 1);

        // Prepare arguments for the thread (input file and dynamically created output file)
        char **args = malloc(2*sizeof(char *));
        args[0] = file_in;
        args[1] = file_names[i];

        // Create thread to copy file
        pthread_create(&threads[i], NULL, copy_file, args);
        // free (file_names[i]);
    }

    // Join threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("File copy completed with %d threads.\n", num_threads);
    return 0;
}
