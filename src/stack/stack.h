#pragma once 

typedef struct Stack Stack;

// Создает новый стек с NULL внутри
Stack* newStack(void);

// Кладет элемент на стек и возвращает измененный стек. В случае нехватки памяти ничего не делает
void push(Stack* stack, int value);

// Берет элемент со стека, если получится, сохраняет удаленное значение в аргумент value
void pop(Stack* stack, int* value);

// Возвращает успех ли, в value верхний элемент stack
bool peek(Stack* stack, int* value);

// Удаляет весь стек
void deleteStack(Stack* stack);