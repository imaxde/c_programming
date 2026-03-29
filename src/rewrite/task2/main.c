#include <stdio.h>
#include <stdbool.h>

long int minimizeNumber(long int n) 
{
    if (n <= 0) {
        return 0;
    }

    int cnt[10] = {0};

    while (n > 0) {
        int d = n % 10;
        cnt[d]++;
        n /= 10;
    }

    long int result = 0;

    for (int d = 1; d <= 9; d++) {
        if (cnt[d] > 0) {
            result = d;
            cnt[d]--;
            break;
        }
    }

    for (int d = 0; d <= 9; d++) {
        while (cnt[d] > 0) {
            result = result * 10 + d;
            cnt[d]--;
        }
    }

    return result;
}

bool testZero()
{
    return minimizeNumber(0) == 0;
}

bool testWithZero()
{
    return minimizeNumber(1001) == 1001;
}

bool testAllDigits()
{
    return minimizeNumber(8967450123L) == 1023456789L;
}

int main(void)
{
    if (!testZero() || !testWithZero() || !testAllDigits())
        return 1;
    return 0;
}
