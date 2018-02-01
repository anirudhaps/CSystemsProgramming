#include "inc.h"
#include <dlfcn.h>

int main(int argc, char *argv[])
{
    int num1, num2;
    int sum = 0;
    char msg[50];
    void *handle = NULL;
    int (*sum_func)(int, int) = NULL;
    void (*print_func)(char *) = NULL;

    if (argc != 3) {
        printf("Usage: ./sum_out <num1> <num2>\n");
        exit(1);
    }

    num1 = atoi(argv[1]);
    num2 = atoi(argv[2]);

    handle = dlopen("libsum.so", RTLD_LAZY);
    if (handle == NULL) {
        printf("Error during dynamically loading the module libsum.so: %s\n", dlerror());
        exit(1);
    }

    sum_func = dlsym(handle, "sumofnums");
    if (sum_func == NULL) {
        printf("Error during fetching sumofnums from module libsum.so: %s\n", dlerror());
        dlclose(handle);
        exit(1);
    }

    print_func = dlsym(handle, "print_msg");
    if (print_func == NULL) {
        printf("Error during fetching print_msg from module libsum.so: %s\n", dlerror());
        dlclose(handle);
        exit(1);
    }
    /*sum = sumofnums(num1, num2);*/
    sum = sum_func(num1, num2);
    sprintf(msg, "sum of [%d, %d] = %d", num1, num2, sum);
    /*print_msg(msg);*/
    print_func(msg);
    dlclose(handle);
    return 0;
}
