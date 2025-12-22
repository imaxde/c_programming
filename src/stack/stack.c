#include <stdlib.h>
#include "stack.h"

struct Stack {
    int value;
    struct Stack* next;
};

struct Stack* push(struct Stack* stack, int value)
{
    struct Stack* newStack = malloc(sizeof(struct Stack));

    if (!newStack)
        return NULL;

    newStack->value = value;
    newStack->next = stack;
    return newStack;
}

struct Stack* pop(struct Stack* stack, int* value) 
{
    if (stack == NULL)
        return NULL;

    struct Stack* temp = stack->next;
    *value = stack->value;
    free(stack);
    return temp;
}

int peek(struct Stack* stack) 
{
    if (stack == NULL)
        return -1;

    return stack->value;
}

struct Stack* new(void) 
{
    return NULL;
}

void delete(struct Stack* stack) 
{
    while (stack != NULL) {
        struct Stack* temp = stack;
        stack = stack->next;
        free(temp);
    }
}

