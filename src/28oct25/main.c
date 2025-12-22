#include "sorted_list.h"
#include <stdio.h>

int main(void)
{
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
            sortedListPrint(list);
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
