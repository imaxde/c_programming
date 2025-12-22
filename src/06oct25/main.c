#include <stdio.h>
#include "merge_sort.h"

int main(void)
{
    int number = 0;
    int data[100] = { 0 };
    int originalData[100] = { 0 };
    int index = 0;
    
    printf("введите числа (для завершения нажмите enter+ctrl+d):\n");

    while (scanf("%d", &number) == 1) {
        data[index] = number;
        // сохраняем копию исходного массива
        originalData[index] = number;
        index++;
    };

    mergeSort(data, index);
    printf("отсортированные числа:\n");

    for (int i = 0; i < index; i++)
        printf("%d ", data[i]);
    printf("\n");

    // подсчитываем различия
    int movedCount = 0;
    for (int i = 0; i < index; i++) {
        if (data[i] != originalData[i]) {
            movedCount++;
        }
    }

    return movedCount;
}