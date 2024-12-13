#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return -1;
    }

    char buffer[10000];
    FILE *fp = fopen(argv[1], "rb");

    if (fp == NULL) {
        perror("Error opening input file");
        return -1;
    }

    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
        // Just read, no processing
    }

    fclose(fp);
    printf("File %s read successfully.\n", argv[1]);
    return 0;
}
