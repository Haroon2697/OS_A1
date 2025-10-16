#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid1, pid2;
    int status;
    
    printf("Parent process - PID: %d\n", getpid());
    
    // First fork: parent creates first child (Child1)
    pid1 = fork();
    
    if (pid1 == 0) {
        // First child process
        printf("First child process - PID: %d\n", getpid());
        
        // Second fork: Child1 creates second child (Child2)
        pid2 = fork();
        
        if (pid2 == 0) {
            // Child2: replace this process image with /bin/ls -l using execvp
            printf("Second child process - PID: %d\n", getpid());
            printf("Executing 'ls -l' command...\n");
            
            // Prepare arguments for execvp
            char *args[] = {"ls", "-l", NULL};
            
            // Execute: on success, this process becomes 'ls'; on failure, returns -1
            if (execvp("ls", args) == -1) {
                printf("execvp failed in second child\n");
                exit(1);
            }
        } else {
            // First child waits for second child
            wait(&status);
            printf("First child terminating\n");
            exit(0);
        }
    } else {
        // Parent process
        // Wait for first child to complete
        wait(&status);
        
        // Check the return status
        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);
            if (exit_status == 0) {
                printf("child successful\n");
            } else {
                printf("child failed\n");
            }
        } else {
            printf("child failed\n");
        }
        
        printf("Parent process terminating\n");
    }
    
    return 0;
}
