#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int left, int middle, int right)
{
    int i, j, k;
    int n = middle - left + 1;
    int m = right - middle;
    int* leftArr = malloc(n * sizeof(int));
    int* rightArr = malloc(m * sizeof(int));

    for (i = 0; i < n; i++)
        leftArr[i] = arr[left + i];

    for (j = 0; j < m; j++)
        rightArr[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n && j < m) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < m) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    free(leftArr);
    free(rightArr);
}

void mergeSort(int* arr, int left, int right)
{
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}


int* removeDuplicates(int* arr, int* arraySize)
{
    if (*arraySize <= 0)
        return arr;

    int j = 0;
    for (int i = 0; i < *arraySize - 1; i++) {
        if (arr[i] != arr[i + 1])
            arr[j++] = arr[i];
    }
    arr[j++] = arr[*arraySize - 1];

    *arraySize = j;
    return realloc(arr, *arraySize * sizeof(int));
}

int main(void)
{
    int* array = malloc(1 * sizeof(int));   
    int number = 999;
    int count = 0;

    while (number != 0) {
        scanf("%d", &number);
        count++;
        array = realloc(array, count * sizeof(int));
        array[count - 1] = number;
    }

    mergeSort(array, 0, count - 1);
    array = removeDuplicates(array, &count);

    for (int i = 1; i < count; i++)
        printf("%d ", array[i]);

    printf("\n");
    return 0;
}