#include "merge_sort.h"
#include <stdlib.h>
#include <string.h>

static void merge(int data[], int leftSize, int rightSize)
{
    int size = leftSize + rightSize;
    int* buffer = malloc((size_t)size * sizeof(int));
    int i = 0;
    int j = 0;
    int k = 0;
    int* left = data;
    int* right = data + leftSize;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            buffer[k++] = left[i++];
        } else {
            buffer[k++] = right[j++];
        }
    }

    while (i < leftSize)
        buffer[k++] = left[i++];

    while (j < rightSize)
        buffer[k++] = right[j++];

    memcpy(data, buffer, (size_t)size * sizeof(int));
    free(buffer);
}

void mergeSort(int data[], int size)
{
    if (size < 2)
        return;

    int mid = size / 2;
    mergeSort(data, mid);
    mergeSort(data + mid, size - mid);
    merge(data, mid, size - mid);
}
