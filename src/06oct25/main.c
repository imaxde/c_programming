#include <stdio.h>
#include "merge_sort.h"

int main(void)
{
    int number;
    int data[100];
    int index = 0;
    
    printf("введите числа (для завершения нажмите enter+ctrl+d):\n");

    while (scanf("%d", &number) == 1) {
        data[index] = number;
        index++;
    };

    merge_sort(data, index);
    printf("отсортированные числа:\n");

    for (int i = 0; i < index; i++)
        printf("%d ", data[i]);
    printf("\n");

    return 0;
}