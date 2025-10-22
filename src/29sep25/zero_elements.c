#include <stdio.h>

int count_zero_elements(int arr[], int size) 
{
    int count = 0;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0)
            count++;
    }
    
    return count;
}

/* в C приходится выводить массив по одному элементу */
void print_array(int arr[], int size) 
{
    printf("Массив: [");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");
}

int main() 
{
    int arr[] = {1, 0, 3, 0, 5, 0, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, size);
    int zeros = count_zero_elements(arr, size);
    printf("Количество нулевых элементов: %d\n", zeros);
    
    return 0;
}
