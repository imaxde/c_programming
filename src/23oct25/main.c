#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../stack/stack.h"

bool isBalanced(const char* str) {
    struct Stack* stack = new();
    bool balanced = true;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            stack = push(stack, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (stack == NULL) {
                balanced = false;
                break;
            }

            int top;
            stack = pop(stack, &top);

            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) {
                balanced = false;
                break;
            }
        }
    }
    
    if (stack != NULL) {
        balanced = false;
        delete(stack);
    }
    
    return balanced;
}

int main(void) {
    const char* tests[] = {"()", "[]", "{}", "({})", "({)}", "((()))", "([{}])", "}{", "(", ")", ""};
    int numTests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < numTests; i++) {
        printf("String: \"%s\" is %s\n", tests[i], isBalanced(tests[i]) ? "сбалансирована" : "не сбалансирована");
    }

    return 0;
}
