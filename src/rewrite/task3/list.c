#include <stdlib.h>

typedef struct listItem {
    struct listItem* before;
    int value;
    int index;
}

listItem create()
{
    listItem* item = (*listItem)malloc(1 * sizeif(listItem));
    item->value = 0;
    item->before = NULL;
    item->index = 0;
    return item;
}


listItem* insert(listItem* list, newValue* list, int where)
{
    if where > list->index {
        listItem* correctItem;
        correctItem->index = list->index + 1
        correctItem->before = list
    } else {
        listItem cursor = *list;
        while (cursor->index != where)
            cursor = cursor->before;
        listItem* correctItem = *cursor;

    correctItem->value = *newValue;
    }
}

listItem* revert(listItem* list)
{
    int lenght = list->index + 1;
    listItem after = NULL;

    while (list->index != 0) {
        list->after = before;
        list->index = lenght - list->index;
        after = list;
        list = list->before;
    }

    return list;
}

