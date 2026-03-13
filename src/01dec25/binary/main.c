#include "bin_numbers.h"
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int32_t a = 0;
    int32_t b = 0;
    scanf("%d %d", &a, &b);

    struct BinNumber c = toBinary(a);
    struct BinNumber d = toBinary(b);

    printBinary(c);
    printBinary(d);

    struct BinNumber e = plus(c, d);

    printBinary(e);

    printf("%d\n", toDecimal(e));
    return 0;
}