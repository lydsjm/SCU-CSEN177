#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return -1;
    }

    char buffer[10000];
    FILE *fp_in = fopen(argv[1], "rb");
    if (fp_in == NULL) {
        perror("Error opening input file");
        return -1;
    }

    FILE *fp_out = fopen("copy.out", "wb");  // Output file named 'copy.out'
    if (fp_out == NULL) {
        perror("Error opening output file");
        fclose(fp_in);
        return -1;
    }

    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), fp_in)) > 0) {
        fwrite(buffer, 1, bytes, fp_out);
    }

    fclose(fp_in);
    fclose(fp_out);
    printf("File copied from %s to copy.out successfully.\n", argv[1]);
    return 0;
}
