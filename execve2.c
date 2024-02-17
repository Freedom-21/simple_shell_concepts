#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork(); // Create a new process

    if (pid == -1) {
        // If fork() returns -1, an error occurred
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
    // Execute the "ls" command to list directory contents
    execlp("ls", "ls", NULL);
    // If execlp returns, it means there was an error
    perror("execlp failed");
    return 1;        
    } else {
        // This block is executed in the parent process
        printf("I am the parent process. My PID is %d and I created a child process with PID %d.\n", getpid(), pid);
        wait(NULL); // Wait for the child process to complete
    }

    return 0;
}

