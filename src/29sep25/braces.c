#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
    };
    if (balance == 0)
        return true;
    else
        return false;
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
    
    bool correct = checkStr(string);
    printf("%s\n", correct ? "true" : "false");

    return 0;
}