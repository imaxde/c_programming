#pragma once 

struct Stack;

// Создает новый стек с NULL
struct Stack* new(void);

// Кладет элемент на стек и возвращает измененный стек
struct Stack* push(struct Stack* stack, int value);

// Берет элемент со стек, возвращает измененный стек, сохраняет удаленное значение в аргумент value
struct Stack* pop(struct Stack* stack);

// Возвращает верхний элемент стека
int peek(struct Stack* stack);

// Удаляет весь стек
void delete(struct Stack* stack);