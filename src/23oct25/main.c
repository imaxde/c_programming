#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../stack/stack.h"

bool isBalanced(char* str) 
{
    if (!str)
        return false;

    Stack* stack = newStack();
    if (stack == NULL) 
        return false;
    
    bool balanced = true;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            push(stack, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            int top = 0;
            if (!peek(stack, &top)) {
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

    int value = 0;
    if (balanced && peek(stack, &value))
        balanced = false;

    while (peek(stack, &value))
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
