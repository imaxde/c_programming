#pragma once 

typedef struct Stack Stack;

// Создает новый стек с NULL внутри
struct Stack* newStack(void);

// Кладет элемент на стек и возвращает измененный стек. В случае нехватки памяти ничего не делает
void push(struct Stack* stack, int value);

// Берет элемент со стека, если получится, сохраняет удаленное значение в аргумент value
void pop(struct Stack* stack, int* value);

// Возвращает верхний элемент стека или -1, если пусто
int peek(struct Stack* stack);

// Удаляет весь стек
void deleteStack(struct Stack* stack);