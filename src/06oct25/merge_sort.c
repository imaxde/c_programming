#include "merge_sort.h"

void merge(int left[], int right[], int data[], int left_size, int right_size)
{
    int i = 0, j = 0, k = 0;
    
    // слияние элементов пока оба массива не пусты
    while (i < left_size && j < right_size) {
        if (left[i] <= right[j])
            data[k++] = left[i++];
        else
            data[k++] = right[j++];
    }
    
    // добавляем оставшиеся элементы из левого массива
    while (i < left_size)
        data[k++] = left[i++];
    
    // добавляем оставшиеся элементы из правого массива
    while (j < right_size)
        data[k++] = right[j++];
}

void merge_sort(int data[], int size)
{
    if (size <= 1)
        return;

    // делим массив на два массива
    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    for (int i = 0; i < mid; i++)
        left[i] = data[i];

    for (int i = mid; i < size; i++)
        right[i - mid] = data[i];

        
    merge_sort(left, mid);
    merge_sort(right, size - mid);
    merge(left, right, data, mid, size - mid);
}