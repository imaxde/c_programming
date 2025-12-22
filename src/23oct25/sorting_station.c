#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../stack/stack.h"

int getPrecedence(char op)
{
    if (op == '*' || op == '/') {
        return 2;
    }

    if (op == '+' || op == '-') {
        return 1;
    }

    return 0;
}

void infixToPostfix(const char* infix, char* postfix)
{
    struct Stack* stack = new();
    int i = 0;
    int j = 0;
    int topVal = 0;
    int val = 0;

    while (infix[i] != '\0') {
        char token = infix[i];

        if (isspace(token)) {
            i++;
            continue;
        }

        if (isdigit(token)) {
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
            continue;
        }

        if (token == '(') {
            stack = push(stack, token);
        } else if (token == ')') {
            while (stack != NULL && peek(stack) != '(') {
                stack = pop(stack, &topVal);
                postfix[j++] = (char)topVal;
                postfix[j++] = ' ';
            }

            if (stack != NULL && peek(stack) == '(') {
                stack = pop(stack, &topVal);
            }
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            while (stack != NULL) {
                int top = peek(stack);
                if (top == '(') {
                    break;
                }

                if (getPrecedence((char)top) >= getPrecedence(token)) {
                    stack = pop(stack, &val);
                    postfix[j++] = (char)val;
                    postfix[j++] = ' ';
                } else {
                    break;
                }
            }

            stack = push(stack, token);
        }

        i++;
    }

    while (stack != NULL) {
        stack = pop(stack, &val);
        postfix[j++] = (char)val;
        postfix[j++] = ' ';
    }

    if (j > 0 && postfix[j - 1] == ' ') {
        postfix[j - 1] = '\0';
    } else {
        postfix[j] = '\0';
    }

    delete(stack);
}

int main(void)
{
    char* infix = NULL;
    char* postfix = NULL;
    size_t capacity = 0;
    size_t length = 0;
    int ch = 0;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (length + 1 >= capacity) {
            if (capacity == 0) {
                capacity = 16;
            } else {
                capacity *= 2;
            }

            infix = realloc(infix, capacity * sizeof(char));
            if (infix == NULL) {
                return 1;
            }
        }
        infix[length++] = (char)ch;
    }

    if (infix != NULL) {
        infix[length] = '\0';
    } else {
        infix = calloc(1, sizeof(char));
    }

    postfix = calloc(length * 2 + 1, sizeof(char));
    if (postfix == NULL) {
        free(infix);
        return 1;
    }

    infixToPostfix(infix, postfix);
    printf("%s\n", postfix);

    free(infix);
    free(postfix);

    return 0;
}
