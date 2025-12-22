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

// Распечатывает содержимое списка
void sortedListPrint(SortedList* list);

// Удаляет список и освобождает память
void sortedListDelete(SortedList* list);
