#pragma once

#include <stdbool.h>

typedef struct SortedListNode SortedListNode;

typedef struct {
    SortedListNode* head;
} SortedList;

// Создает новый отсортированный список
SortedList* sortedListNew(void);

// Вставляет элемент в список, сохраняя порядок сортировки
void sortedListInsert(SortedList* list, int value);

// Удаляет первое вхождение элемента с заданным значением
void sortedListRemove(SortedList* list, int value);

// Возвращает содержимое списка в виде массива (caller должен освободить память)
int* sortedListToArray(SortedList* list, int* outSize);

// Удаляет список и освобождает память
void sortedListDelete(SortedList* list);
