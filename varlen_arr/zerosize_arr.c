#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct payload {
    int size;
    char data[0];
};

int main() {
    int data_len = 10;
    int i = 0;
    char loc_data[] = {
        0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b
    };
    char *dptr = NULL;
    struct payload *ptr = (struct payload *)malloc(sizeof(struct payload) +
                          data_len * sizeof(char));
    if (!ptr) {
        printf("Memory Error\n");
        exit(1);
    }
    ptr->size = data_len;
    memcpy(ptr->data, loc_data, ptr->size);

    printf("Print data\n");
    for (i = 0, dptr = ptr->data; i < 10; i++, dptr++) {
        printf("%02X ", *dptr);
    }
    printf("\n");
    return 0;
}
