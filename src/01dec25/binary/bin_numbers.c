#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "bin_numbers.h"

struct BinNumber plus(struct BinNumber n1, struct BinNumber n2) 
{
    struct BinNumber result = {0};
    bool carry = false;

    for (int i = 31; i >= 0; i--) {
        int sum = n1.bits[i] + n2.bits[i] + carry;

        result.bits[i] = sum % 2;
        carry = sum / 2;
    }

    return result;
}

struct BinNumber toBinary(int32_t decimalNumber) 
{
    struct BinNumber new = {0};

    for (int i = 0; i < 32; i++) {
        if (decimalNumber & (1u << i))
            new.bits[31 - i] = true;
    }
    
    return new;
}

int32_t toDecimal(struct BinNumber binaryNumber) 
{
    int32_t result = 0;

    for (int i = 0; i < 32; i++) {
        if (binaryNumber.bits[i]) {
            result |= (1u << (31 - i));
        }
    }

    return result;
}

void printBinary(struct BinNumber binaryNumber) 
{
    bool leadingZero = true;

    for (int i = 0; i < 32; i++) {
        if (leadingZero && binaryNumber.bits[i])
            leadingZero = false;

        if (!leadingZero)
            printf("%d", (int)(binaryNumber.bits[i]));
    }
        
    printf("\n");
}