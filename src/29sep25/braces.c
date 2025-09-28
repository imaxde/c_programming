#include <stdio.h>

int check_str(char string[99])
{
    int balance = 0;
    for (int i = 0; i < 99; i++) {
        if (string[i] == '(')
            balance += 1;
        else if (string[i] == ')')
            balance -= 1;
        if (balance < 0)
            return 0;
    }
    return balance == 0;
}

int main(void)
{
    char string[99];
    scanf("%s", string);
    int correct = check_str(string);
    printf("%d\n", correct);
    return 0;
}