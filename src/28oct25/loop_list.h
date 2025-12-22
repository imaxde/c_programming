#pragma once

#include <stdbool.h>

typedef struct LoopListNode LoopListNode;

struct LoopListNode {
    int value;
    LoopListNode* next;
};

typedef struct {
    LoopListNode* head;
} LoopList;

// Создает новый циклический список
LoopList* loopListNew(void);

// Вставляет элемент в конец циклического списка
void loopListInsert(LoopList* list, int value);

// Удаляет первое вхождение элемента с заданным значением
void loopListRemove(LoopList* list, int value);

// Распечатывает содержимое циклического списка
void loopListPrint(LoopList* list);

// Удаляет список и освобождает память
void loopListDelete(LoopList* list);
