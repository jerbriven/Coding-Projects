#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct test
{
    char** stringArray;
} test;

int main(int _argc, char* _argv[])
{
    test* list = malloc(sizeof(test));
    list->stringArray = malloc(3 * sizeof(*list->stringArray));
    char input[11] = "Hello World";
    list->stringArray[0] = malloc(strlen(input) + 1);
    strcpy(list->stringArray[0], input);
    printf("%s", list->stringArray[0]);
}