/*
Name: Lydia Myla
Date: 10/1/2024
Title: Lab 2 - Step 7
# Description: write a program that has a parent process that spawns a child which runs the ls command
*/

#include <stdio.h>      
#include <sys/types.h>  
#include <unistd.h>    
#include <stdlib.h>    
#include <errno.h>    

int main(int argc, char *argv[]) {
    pid_t  pid;
    printf("Before forking.\n");
    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "can't fork, error %d\n", errno);
    }
 
    else if(pid == 0)  {
        execlp("/bin/ls", "ls", NULL);
    }
    else {
        wait(NULL);
        printf("Child Complete");
        exit(0);
    }
    return 0;
}
