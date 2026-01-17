#include <stdio.h>
#include <stdlib.h>
#include "include/header.h"

int main (int argc, char** argv) {
    TestStruct s;
    char* input = malloc(sizeof(char) * 256);
    init(&s);
    printf("Input your names: ");
    if (scanf_s("%s", input, 256) >= 256)
        return 1;
    printf("\nHello %s\n", input);
    return 0;
}