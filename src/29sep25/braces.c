#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkStr(char* string)
{
    int balance = 0;
    int len = strlen(string);
    for (int i = 0; i < len; i++) {
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
    char* string = NULL;
    int capacity = 10;
    int size = 0;
    int c;
    
    string = malloc(capacity);
    
    printf("Введите строку: ");
    
    while ((c = getchar()) != '\n') {
        if (size >= capacity - 1) {
            capacity *= 2;
            char* temp = realloc(string, capacity);
            string = temp;
        }
        string[size++] = c;
    }
    string[size] = '\0';
    
    int correct = checkStr(string);
    printf("%d\n", correct);

    return 0;
}