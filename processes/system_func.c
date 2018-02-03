#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int ret_val = 0;
	int i = 0;
	char command[100];

	if (argc < 2) {
		fprintf(stderr, "%s [command(s)]\n", argv[0]);
		exit(1);
	}
	sprintf(command, "%s", argv[1]);
	for (i = 2;i < argc; ++i) {
		strcat(command, " ");
		strcat(command, argv[i]);
	}
	ret_val = system(command);
	printf("Return value of system: %d\n", ret_val);
	return ret_val;
}
