#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../stack/stack.h"

int getPrecedence(char op)
{
    if (op == '*' || op == '/')
        return 2;

    if (op == '+' || op == '-')
        return 1;

    return 0;
}

bool appendPostfixChar(char* postfix, size_t postfixCapacity, size_t* postfixIndex, char token)
{
    if (*postfixIndex + 1 >= postfixCapacity)
        return false;

    postfix[*postfixIndex] = token;
    (*postfixIndex)++;
    return true;
}

bool appendPostfixToken(char* postfix, size_t postfixCapacity, size_t* postfixIndex, char token)
{
    if (!appendPostfixChar(postfix, postfixCapacity, postfixIndex, token))
        return false;

    return appendPostfixChar(postfix, postfixCapacity, postfixIndex, ' ');
}

bool infixToPostfix(char* infix, char* postfix, size_t postfixCapacity)
{
    Stack* stack = newStack();
    size_t infixIndex = 0;
    size_t postfixIndex = 0;
    bool isValid = true;

    if (stack == NULL || postfixCapacity == 0) {
        if (postfixCapacity > 0) {
            postfix[0] = '\0';
        }
        return false;
    }

    while (infix[infixIndex] != '\0' && isValid) {
        char token = infix[infixIndex];

        if (isspace((unsigned char)token)) {
            infixIndex++;
            continue;
        }

        if (isdigit((unsigned char)token)) {
            isValid = appendPostfixToken(postfix, postfixCapacity, &postfixIndex, token);
            infixIndex++;
            continue;
        }

        if (token == '(') {
            push(stack, token);
            infixIndex++;
            continue;
        }

        if (token == ')') {
            bool hasOpeningParen = false;
            int stackTop = 0;

            while (peek(stack, &stackTop)) {
                pop(stack, &stackTop);

                if (stackTop == '(') {
                    hasOpeningParen = true;
                    break;
                }

                if (!appendPostfixToken(postfix, postfixCapacity, &postfixIndex, (char)stackTop)) {
                    isValid = false;
                    break;
                }
            }

            if (!hasOpeningParen)
                isValid = false;

            infixIndex++;
            continue;
        }

        if (token == '+' || token == '-' || token == '*' || token == '/') {
            int stackTop = 0;

            while (peek(stack, &stackTop) && stackTop != '('
                && getPrecedence((char)stackTop) >= getPrecedence(token)) {
                pop(stack, &stackTop);

                if (!appendPostfixToken(postfix, postfixCapacity, &postfixIndex, (char)stackTop)) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) 
                push(stack, token);

            infixIndex++;
            continue;
        }

        isValid = false;
        infixIndex++;
    }

    while (isValid) {
        int stackTop = 0;

        if (!peek(stack, &stackTop))
            break;

        pop(stack, &stackTop);

        if (stackTop == '(') {
            isValid = false;
            break;
        }

        if (!appendPostfixToken(postfix, postfixCapacity, &postfixIndex, (char)stackTop)) {
            isValid = false;
            break;
        }
    }

    if (isValid && postfixIndex > 0) 
        postfixIndex--;

    postfix[isValid ? postfixIndex : 0] = '\0';

    deleteStack(stack);
    return isValid;
}

int main(void)
{
    size_t infixCapacity = 16;
    char* infix = calloc(infixCapacity, sizeof(char));
    char* postfix = NULL;
    size_t infixLength = 0;
    int ch = 0;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (infixLength + 1 >= infixCapacity) {
            infixCapacity *= 2;

            char* temp = realloc(infix, infixCapacity * sizeof(char));
            if (temp == NULL) {
                free(infix);
                return 1;
            }
            infix = temp;
        }
        infix[infixLength++] = (char)ch;
    }

    infix[infixLength] = '\0';

    size_t postfixCapacity = infixLength * 2 + 1;
    postfix = calloc(postfixCapacity, sizeof(char));
    if (postfix == NULL) {
        free(infix);
        return 1;
    }

    infixToPostfix(infix, postfix, postfixCapacity);
    printf("%s\n", postfix);

    free(infix);
    free(postfix);

    return 0;
}
