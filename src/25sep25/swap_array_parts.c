#include <stdio.h>

void reverse(int arr[], int left, int right)
{
    /* left, right - Индексы правого и левого элементов, которые меняются местами */
    while (left < right) {
        int element = arr[left];
        arr[left] = arr[right];
        arr[right] = element;
        left++;
        right--;
    }
}

int main(void)
{
    const int m = 3;
    const int n = 4;
    int numbers[7] = { 1, 2, 3, 4, 5, 6, 7 };

    /* Вывод первоначального массива циклом*/
    for (int i = 0; i < n + m; i++)
        printf("%d ", numbers[i]);

    printf("\n^^^Исходный массив^^^\n");

    /* Сам алгорим перестановки частей массива */
    reverse(numbers, 0, m - 1);
    reverse(numbers, m, m + n - 1);
    reverse(numbers, 0, m + n - 1);

    /* Вывод обработанного массива */
    for (int i = 0; i < n + m; i++)
        printf("%d ", numbers[i]);

    printf("\n^^^Обработанный массив^^^\n");

    return 0;
}
