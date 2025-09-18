#include <stdlib.h>
#include <stdio.h>

int quotient(int a, int b) 
{
    if (b == 0)
        return 0;

    int sign = 1;
    if (a < 0)
        sign = -1;

    int aa = abs(a);
    int bb = abs(b);
    int q = 0;

    while (aa >= bb) {
        aa -= bb;
        q += 1;
    }
    q *= sign;

    if (a - bb * q < 0)
        q = q - 1;
    if (b < 0)
        q = -q;
    return q;
}

int main(void)
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    int result = quotient(a, b);
    printf("%d\n", result);
    return 0;
}