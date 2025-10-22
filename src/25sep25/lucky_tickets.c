#include <stdio.h>

int main(void)
{
    int count[28] = {0};  // сколько сумм какой результат дают

    /* перебор цифр первой тройки в билете */
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                count[i + j + k] += 1;
            }
        }
    }

    int result = 0;

    for (int summ = 0; summ <= 27; summ++)
        result = result + (count[summ] * count[summ]);  // для каждого колличества сумм существует ^2 счастливых билетов 

    printf("%d\n", result);
}