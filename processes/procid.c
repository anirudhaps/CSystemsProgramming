#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	printf("The process-id: %d\n", (int)getpid());
	printf("The parent process-id: %d\n", (int)getppid());
	return 0;
}
