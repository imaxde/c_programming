#include "loop_list.h"
#include <stdio.h>
#include <stdlib.h>


static LoopListNode* createNode(int value)
{
    LoopListNode* node = (LoopListNode*)malloc(sizeof(LoopListNode));
    node->value = value;
    node->next = NULL;
    return node;
}

LoopList* loopListNew(void)
{
    LoopList* list = (LoopList*)malloc(sizeof(LoopList));
    list->head = NULL;
    return list;
}

void loopListInsert(LoopList* list, int value)
{
    LoopListNode* newNode = createNode(value);

    if (!list->head) {
        list->head = newNode;
        newNode->next = newNode;
        return;
    }

    LoopListNode* current = list->head;
    while (current->next != list->head) {
        current = current->next;
    }

    current->next = newNode;
    newNode->next = list->head;
}

void loopListRemove(LoopList* list, int value)
{
    LoopListNode* current = list->head;
    LoopListNode* prev = NULL;

    do {
        if (current->value == value)
            break;
        prev = current;
        current = current->next;
    } while (current != list->head);

    if (current->value != value)
        return;

    if (current == list->head) {
        if (current->next == list->head) {
            list->head = NULL;
        } else {
            LoopListNode* last = list->head;
            while (last->next != list->head) {
                last = last->next;
            }
            list->head = current->next;
            last->next = list->head;
        }
    } else {
        prev->next = current->next;
    }

    free(current);
}

void loopListPrint(LoopList* list)
{
    printf("[");
    if (list->head) {
        LoopListNode* current = list->head;
        do {
            printf("%d", current->value);
            if (current->next != list->head)
                printf(", ");
            current = current->next;
        } while (current != list->head);
    }
    printf("]\n");
}

void loopListDelete(LoopList* list)
{
    if (list->head) {
        LoopListNode* current = list->head;
        LoopListNode* last = list->head;
        while (last->next != list->head) {
            last = last->next;
        }
        last->next = NULL;

        while (current) {
            LoopListNode* next = current->next;
            free(current);
            current = next;
        }
    }

    free(list);
}
