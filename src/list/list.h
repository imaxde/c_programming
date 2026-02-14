#pragma once

typedef struct ListNode ListNode;

typedef struct {
    ListNode* head;
} List;

List* listNew(void);

// Вставляет value на элемент списка под номером index
void listInsert(List* list, int index, int value);

// Возвращает элемент по индексу
int listGet(List* list, int index);

// Убирает элемент по индексу
void listRemove(List* list, int index);

// Сцепляет 2 списка
void listAppend(List* list1, List* list2);

// Распечатывает содержимое списка
void listPrint(List* list);

// Удаляет список и освобождает память
void listDelete(List* list);
