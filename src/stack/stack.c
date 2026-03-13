#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

struct StackElement {
    int value;
    struct StackElement* next;
};

struct Stack {
    struct StackElement* headElement;
};

void push(struct Stack* stack, int value)
{
    struct StackElement* newHead = calloc(1, sizeof(struct StackElement));

    if (newHead == NULL)
        return;
    
    newHead->next = stack->headElement;
    newHead->value = value;
    stack->headElement = newHead;
}

void pop(struct Stack* stack, int* value) 
{
    struct StackElement* element = stack->headElement;

    if (element == NULL) 
        return;

    struct StackElement* temp = element->next;
    *value = element->value;
    free(element);
    stack->headElement = temp;
}

bool peek(struct Stack* stack, int* value) 
{
    if (stack->headElement == NULL)
        return false;

    *value = stack->headElement->value;
    return true;
}

struct Stack* newStack(void) 
{
    struct Stack* stack = calloc(1, sizeof(struct Stack));

    if (stack == NULL)
        return NULL;

    stack->headElement = NULL;
    return stack;
}

void deleteStack(struct Stack* stack) 
{
    struct StackElement* element = stack->headElement;

    while (element != NULL) {
        struct StackElement* temp = element;
        element = element->next;
        free(temp);
    }

    free(stack);
}

