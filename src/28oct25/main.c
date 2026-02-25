#include "sorted_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int testInsertOrdered(void)
{
    SortedList* list = sortedListNew();
    if (!list)
        return 0;

    sortedListInsert(list, 3);
    sortedListInsert(list, 1);
    sortedListInsert(list, 2);
    sortedListInsert(list, 5);
    sortedListInsert(list, 4);

    int size;
    int* array = sortedListToArray(list, &size);
    if (!array || size != 5) {
        sortedListDelete(list);
        return 0;
    }

    int result = 1;
    int expected[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < size; i++) {
        if (array[i] != expected[i]) {
            result = 0;
            break;
        }
    }

    free(array);
    sortedListDelete(list);
    return result;
}

static int testRemoveElement(void)
{
    SortedList* list = sortedListNew();
    if (!list)
        return 0;

    sortedListInsert(list, 3);
    sortedListInsert(list, 1);
    sortedListInsert(list, 2);

    sortedListRemove(list, 2);

    int size;
    int* array = sortedListToArray(list, &size);
    if (!array || size != 2) {
        sortedListDelete(list);
        return 0;
    }

    int result = 1;
    if (array[0] != 1 || array[1] != 3)
        result = 0;

    free(array);
    sortedListDelete(list);
    return result;
}

static int testEmptyList(void)
{
    SortedList* list = sortedListNew();
    if (!list)
        return 0;

    int size;
    int* array = sortedListToArray(list, &size);
    if (array) {
        free(array);
        sortedListDelete(list);
        return 0;
    }

    if (size != 0) {
        sortedListDelete(list);
        return 0;
    }

    sortedListDelete(list);
    return 1;
}

static int testSingleElement(void)
{
    SortedList* list = sortedListNew();
    if (!list)
        return 0;

    sortedListInsert(list, 42);

    int size;
    int* array = sortedListToArray(list, &size);
    if (!array || size != 1) {
        sortedListDelete(list);
        return 0;
    }

    int result = (array[0] == 42);

    free(array);
    sortedListDelete(list);
    return result;
}

static int testDuplicates(void)
{
    SortedList* list = sortedListNew();
    if (!list)
        return 0;

    sortedListInsert(list, 2);
    sortedListInsert(list, 2);
    sortedListInsert(list, 1);
    sortedListInsert(list, 2);

    int size;
    int* array = sortedListToArray(list, &size);
    if (!array || size != 4) {
        sortedListDelete(list);
        return 0;
    }

    int result = 1;
    int expected[] = {1, 2, 2, 2};
    for (int i = 0; i < size; i++) {
        if (array[i] != expected[i]) {
            result = 0;
            break;
        }
    }

    free(array);
    sortedListDelete(list);
    return result;
}

static int testRemoveNonExistent(void)
{
    SortedList* list = sortedListNew();
    if (!list)
        return 0;

    sortedListInsert(list, 1);
    sortedListInsert(list, 3);

    int sizeBefore;
    int* arrayBefore = sortedListToArray(list, &sizeBefore);
    if (!arrayBefore || sizeBefore != 2) {
        sortedListDelete(list);
        return 0;
    }

    sortedListRemove(list, 999);

    int sizeAfter;
    int* arrayAfter = sortedListToArray(list, &sizeAfter);
    if (!arrayAfter || sizeAfter != 2) {
        free(arrayBefore);
        sortedListDelete(list);
        return 0;
    }

    int result = 1;
    if (arrayBefore[0] != arrayAfter[0] || arrayBefore[1] != arrayAfter[1])
        result = 0;

    free(arrayBefore);
    free(arrayAfter);
    sortedListDelete(list);
    return result;
}

static int testRemoveHead(void)
{
    SortedList* list = sortedListNew();
    if (!list)
        return 0;

    sortedListInsert(list, 1);
    sortedListInsert(list, 2);
    sortedListInsert(list, 3);

    sortedListRemove(list, 1);

    int size;
    int* array = sortedListToArray(list, &size);
    if (!array || size != 2) {
        sortedListDelete(list);
        return 0;
    }

    int result = (array[0] == 2 && array[1] == 3);

    free(array);
    sortedListDelete(list);
    return result;
}

static int testNegativeNumbers(void)
{
    SortedList* list = sortedListNew();
    if (!list)
        return 0;

    sortedListInsert(list, -5);
    sortedListInsert(list, 0);
    sortedListInsert(list, -10);
    sortedListInsert(list, 5);

    int size;
    int* array = sortedListToArray(list, &size);
    if (!array || size != 4) {
        sortedListDelete(list);
        return 0;
    }

    int result = 1;
    int expected[] = {-10, -5, 0, 5};
    for (int i = 0; i < size; i++) {
        if (array[i] != expected[i]) {
            result = 0;
            break;
        }
    }

    free(array);
    sortedListDelete(list);
    return result;
}

static void printList(SortedList* list)
{
    int size;
    int* array = sortedListToArray(list, &size);
    if (!array) {
        printf("[]\n");
        return;
    }

    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");

    free(array);
}

int main(int argc, char** argv)
{
    if (argc == 2 && strcmp(argv[1], "--test") == 0) {
        if (!testInsertOrdered()
            || !testRemoveElement()
            || !testEmptyList()
            || !testSingleElement()
            || !testDuplicates()
            || !testRemoveNonExistent()
            || !testRemoveHead()
            || !testNegativeNumbers())
            return 1;
        return 0;
    }

    SortedList* list = sortedListNew();
    int choice = -1;
    int value;

    printf("0 – выйти\n");
    printf("1 – добавить значение в сортированный список\n");
    printf("2 – удалить значение из списка\n");
    printf("3 – распечатать список\n");

    while (choice != 0) {
        printf("> ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
        case 1:
            printf("Введите значение: ");
            scanf("%d", &value);
            sortedListInsert(list, value);
            break;
        case 2:
            printf("Введите значение для удаления: ");
            scanf("%d", &value);
            sortedListRemove(list, value);
            break;
        case 3:
            printList(list);
            break;
        case 0:
            break;
        default:
            printf("Неверный выбор!\n");
            break;
        }
    }

    sortedListDelete(list);
    return 0;
}
