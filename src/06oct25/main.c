#include <stdio.h>
#include "merge_sort.h"

int main(void)
{
    int number;
    int data[100];
    int original_data[100];
    int index = 0;
    
    printf("введите числа (для завершения нажмите enter+ctrl+d):\n");

    while (scanf("%d", &number) == 1) {
        data[index] = number;
        original_data[index] = number;  // сохраняем копию исходного массива
        index++;
    };

    merge_sort(data, index);
    printf("отсортированные числа:\n");

    for (int i = 0; i < index; i++)
        printf("%d ", data[i]);
    printf("\n");

    // подсчитываем различия
    int moved_count = 0;
    for (int i = 0; i < index; i++) {
        if (data[i] != original_data[i]) {
            moved_count++;
        }
    }

    return moved_count;
}