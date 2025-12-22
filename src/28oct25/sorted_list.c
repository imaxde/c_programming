#include "sorted_list.h"
#include <stdio.h>
#include <stdlib.h>

struct SortedListNode {
    int value;
    SortedListNode* next;
};

static SortedListNode* createNode(int value)
{
    SortedListNode* node = (SortedListNode*)malloc(sizeof(SortedListNode));
    node->value = value;
    node->next = NULL;
    return node;
}

SortedList* sortedListNew(void)
{
    SortedList* list = (SortedList*)malloc(sizeof(SortedList));
    list->head = NULL;
    return list;
}

void sortedListInsert(SortedList* list, int value)
{
    SortedListNode* newNode = createNode(value);

    if (!list->head || list->head->value >= value) {
        newNode->next = list->head;
        list->head = newNode;
        return;
    }

    SortedListNode* current = list->head;
    while (current->next && current->next->value < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void sortedListRemove(SortedList* list, int value)
{
    SortedListNode* current = list->head;
    SortedListNode* prev = NULL;

    while (current && current->value != value) {
        prev = current;
        current = current->next;
    }

    if (!current)
        return;

    if (!prev) {
        list->head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

void sortedListPrint(SortedList* list)
{
    SortedListNode* current = list->head;
    printf("[");
    while (current) {
        printf("%d", current->value);
        if (current->next)
            printf(", ");
        current = current->next;
    }
    printf("]\n");
}

void sortedListDelete(SortedList* list)
{
    SortedListNode* current = list->head;
    while (current) {
        SortedListNode* next = current->next;
        free(current);
        current = next;
    }

    free(list);
}
