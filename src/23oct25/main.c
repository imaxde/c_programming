#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../stack/stack.h"

bool isBalanced(char* str) 
{
    if (!str)
        return false;

    struct Stack* stack = newStack();
    if (stack == NULL) 
        return false;
    
    bool balanced = true;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            push(stack, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            int top = peek(stack);
            if (top == -1) {
                balanced = false;
                break;
            }

            pop(stack, &top);

            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) {
                balanced = false;
                break;
            }
        }
    }

    if (balanced && peek(stack) != -1)
        balanced = false;

    int value = 0;
    while (peek(stack) != -1)
        pop(stack, &value);
    
    deleteStack(stack);
    return balanced;
}

int main(void) 
{
    char* tests[] = {"()", "[]", "{}", "({})", "({)}", "((()))", "([{}])", "}{", "(", ")", ""};
    int numTests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < numTests; i++) {
        printf("Строка \"%s\" %s\n", tests[i], isBalanced(tests[i]) ? "сбалансирована" : "не сбалансирована");
    }

    return 0;
}
