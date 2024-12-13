/* 
Name: Lydia Myla
Date: 11/12/24
Title: Lab 8 - Step 1
Description: write code to generate testInput.txt
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
        FILE *fp;
        char buffer [sizeof(int)];
        int i;
        fp = fopen("testInput.txt", "w");
        for (i=0; i < 10; i++){
                sprintf(buffer, "%d\n", rand()%50);
                fputs(buffer, fp);
        }
        fclose(fp);
        return 0;
}
