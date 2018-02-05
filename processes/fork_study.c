#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t child_pid;

    printf("The main function: process id: %d\n", (int)getpid());

    child_pid = fork();
    if (child_pid == 0) {
        /* This is a child process */
        printf("This is child process\n");
        printf("Child process ID: %d\n", (int)getpid());
        printf("Child's parent process ID: %d\n", (int)getppid());
    } else {
        /* This is the parent process */
        printf("This is parent process\n");
        printf("Child process ID: %d\n", (int)child_pid);
        printf("Child's parent process ID: %d\n", (int)getpid());
    }
    return 0;
}
