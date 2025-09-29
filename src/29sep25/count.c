#include <string.h>
#include <stdio.h>

int count(char str[100], char str1[100])
{
    int size = strlen(str);
    int size1 = strlen(str1);
    int number_of_substrings = 0;

    if (size == 0 || size1 == 0)
        return 0;

    for (int start = 0; start <= size - size1; start++) {
        /* если элемент совпал, продожаем считать, иначе ищем следующий стартовы элемент */
        int coincidences = 0;
        for (int current = 0; current < size1; current++) {
            if (str1[current] == str[start + current])
                coincidences += 1;
            else
                break;
        }
        
        /* если все элементы подстроки есть, то добавляем одно вхождение */
        if (coincidences == size1)
            number_of_substrings += 1;
    }

    return number_of_substrings;
}

int main()
{
    char string[100] = "abcabc";
    char string1[100] = "ab";
    int result = count(string, string1);
    printf("Количество вхождений %d\n", result);
    return 0;
}