#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int value;
    ListNode* next;
};

static ListNode* createNode(int value)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    if (!node)
        return NULL;
    node->value = value;
    node->next = NULL;
    return node;
}

List* listNew(void)
{
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    return list;
}

void listInsert(List* list, int index, int value)
{
    if (index == 0) {
        ListNode* newNode = createNode(value);
        if (!newNode)
            return;
        newNode->next = list->head;
        list->head = newNode;
        return;
    }

    ListNode* current = list->head;
    for (int i = 0; i < index - 1; ++i) {
        if (!current)
            return;
        current = current->next;
    }

    if (!current)
        return;

    ListNode* newNode = createNode(value);
    if (!newNode)
        return;
    newNode->next = current->next;
    current->next = newNode;
}

int listGet(List* list, int index)
{
    ListNode* current = list->head;
    for (int i = 0; i < index; ++i) {
        if (!current)
            return 0;
        current = current->next;
    }

    return current->value;
}

void listRemove(List* list, int index)
{
    if (!list || index < 0 || !list->head)
        return;

    ListNode* toDelete = NULL;

    if (index == 0) {
        toDelete = list->head;
        list->head = list->head->next;
    } else {
        ListNode* current = list->head;
        for (int i = 0; i < index - 1; ++i) {
            if (!current || !current->next)
                return;
            current = current->next;
        }

        if (!current || !current->next)
            return;

        toDelete = current->next;
        current->next = toDelete->next;
    }

    free(toDelete);
}

void listAppend(List* dest, List* src)
{
    if (!dest->head) {
        dest->head = src->head;
    } else {
        ListNode* current = dest->head;
        while (current->next)
            current = current->next;
        current->next = src->head;
    }
    
    src->head = NULL;
}

void listPrint(List* list)
{
    ListNode* current = list->head;
    printf("[");
    while (current) {
        printf("%d", current->value);
        if (current->next)
            printf(", ");
        current = current->next;
    }
    printf("]\n");
}

void listDelete(List* list)
{
    ListNode* current = list->head;
    while (current) {
        ListNode* next = current->next;
        free(current);
        current = next;
    }
    
    free(list);
}
