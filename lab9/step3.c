#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_file> <buffer_size>\n", argv[0]);
        return -1;
    }

    char *input_file = argv[1];
    int buffer_size = atoi(argv[2]);
    if (buffer_size <= 0) {
        fprintf(stderr, "Invalid buffer size.\n");
        return -1;
    }

    char *buffer = malloc(buffer_size);
    if (buffer == NULL) {
        perror("Error allocating buffer");
        return -1;
    }

    FILE *fp = fopen(input_file, "rb");
    if (fp == NULL) {
        perror("Error opening input file");
        free(buffer);
        return -1;
    }

    size_t bytes;
    while ((bytes = fread(buffer, 1, buffer_size, fp)) > 0) {
        // Just read, no processing
    }

    fclose(fp);
    free(buffer);
    printf("File %s read successfully with buffer size %d.\n", input_file, buffer_size);
    return 0;
}
