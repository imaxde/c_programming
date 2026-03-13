#include <stdio.h>
#include <stdint.h>

typedef union {
    double value;
    uint64_t bits;
} DoubleBits;

int main(void)
{
    DoubleBits num;
    printf("введите число: ");
    scanf("%lf", &num.value);

    // извлечение знака
    int sign = (num.bits >> 63) & 1;
    char s = sign ? '-' : '+';

    // извлечение порядка
    int exponentBits = (num.bits >> 52) & 0b11111111111;
    int p = exponentBits - 1023;

    // извлечение мантиссы
    uint64_t mantissaBits = num.bits & ((1ULL << 52) - 1);

    // перевод в десятичные
    double m = 1.0;
    double frac = 0.5;
    for (int i = 51; i >= 0; --i) {
        if ((mantissaBits >> i) & 1)
            m += frac;
        frac *= 0.5;
    }

    printf("Результат: %c%.19g*2^%d\n", s, m, p);
    return 0;
}