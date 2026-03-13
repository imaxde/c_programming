#include "bin_numbers.h"
#include <stdio.h>

int main(void)
{
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);

    if (a < -128 || b < -129 || a > 128 || b > 128)
        return 1;

    unsigned char c = to_binary(a);
    unsigned char d = to_binary(b);

    print_binary(c);
    print_binary(d);

    unsigned char e = plus(c, d);

    print_binary(e);

    printf("%d\n", to_decimal(e));
    return 0;
}