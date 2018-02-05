#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define PROG_NAME_LEN 10

pid_t spawn(char *, char **);

int main(int argc, char *argv[])
{
    char program[PROG_NAME_LEN];
    pid_t child_pid;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <prog_name> [prog_arg1] [prog_arg2] ...\n", argv[0]);
        exit(1);
    }

    if (strlen(argv[1]) >= PROG_NAME_LEN) {
        fprintf(stderr, "prog_name length can't be >= %d characters\n", PROG_NAME_LEN);
        exit(1);
    }
    strcpy(program, argv[1]);
    child_pid = spawn(program, argv + 1);
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
