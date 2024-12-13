#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    //printf("Parent Process PID: %d\n", getpid());

    pid_t child1_pid, child2_pid;

    if ((child1_pid = fork()) == 0) {
        printf("Child 1 PID: %d, Parent: %d\n", getpid(), getppid());

        pid_t grandchild_pid1, grandchild_pid2;

        for (int i = 0; i < 2; i++) {
            if ((i == 0 && (grandchild_pid1 = fork()) == 0) || 
                (i == 1 && (grandchild_pid2 = fork()) == 0)) {
                printf("Grandchild from Child 1 PID: %d, Parent: %d\n", getpid(), getppid());
                exit(0); 
            }
        }

        while (wait(NULL) > 0);
        printf("Child 1 PID: %d, Grandchildren PIDs: %d and %d\n", getpid(), grandchild_pid1, grandchild_pid2);
        exit(0); 
    }

    if ((child2_pid = fork()) == 0) {
        printf("Child 2 PID: %d, Parent: %d\n", getpid(), getppid());

        pid_t grandchild_pid1, grandchild_pid2;

        for (int i = 0; i < 2; i++) {
            if ((i == 0 && (grandchild_pid1 = fork()) == 0) || 
                (i == 1 && (grandchild_pid2 = fork()) == 0)) {
                printf("Grandchild from Child 2 PID: %d, Parent: %d\n", getpid(), getppid());
                exit(0); 
            }
        }

        while (wait(NULL) > 0);
        printf("Child 2 PID: %d, Grandchildren PIDs: %d and %d\n", getpid(), grandchild_pid1, grandchild_pid2);
        exit(0); 
    }

    while (wait(NULL) > 0);
    printf("Parent PID: %d, Child 1 PID: %d and Child 2 PID: %d\n", getpid(), child1_pid, child2_pid);

    return 0; 
}
