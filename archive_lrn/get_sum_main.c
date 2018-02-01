#include "inc.h"

int main(int argc, char *argv[])
{
    int num1, num2;
    int sum = 0;
    char msg[50];

    if (argc != 3) {
        printf("Usage: ./sum_out <num1> <num2>\n");
        exit(1);
    }

    num1 = atoi(argv[1]);
    num2 = atoi(argv[2]);
    sum = sumofnums(num1, num2);
    sprintf(msg, "sum of [%d, %d] = %d", num1, num2, sum);
    print_msg(msg);
}
