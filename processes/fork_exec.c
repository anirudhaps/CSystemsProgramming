#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

pid_t spawn(char *, char **);

int main()
{
    char *program = "ls";
    char *arg_list[] = {
        "ls",
        "/",
        NULL
    };
    pid_t child_pid;

    child_pid = spawn(program, arg_list);
    printf("This is main process: pid: %d\n", (int)getpid());
    printf("This is main process: child pid: %d\n", (int)child_pid);
    printf("Done with main function\n");
    return 0;
}

pid_t spawn(char *program, char **arguments)
{
    pid_t proc_id;

    proc_id = fork();
    if (proc_id != 0) {
        /* Parent process case */
        printf("This is parent process\n");
        return proc_id;
    } else {
        printf("This is child process: %d\n", (int)getpid());
        printf("Parent of this child proc: %d\n", (int)getppid());
        execvp(program, arguments);
        /* This will return only if error occurs */
        fprintf(stderr, "Error during execvp\n");
        abort();
    }
}
