#include <stdio.h>
#include "bin_numbers.h"

unsigned char plus(unsigned char n1, unsigned char n2) 
{
    unsigned char result = 0;
    unsigned char carry = 0;

    for (int i = 0; i < 8; i++) {
        unsigned char b1 = (n1 >> i) & 1;
        unsigned char b2 = (n2 >> i) & 1;

        unsigned char sum = b1 ^ b2 ^ carry;
        carry = (b1 & b2) | (b1 & carry) | (b2 & carry);

        result |= (sum << i);
    }

    return result;
}

unsigned char to_binary(int decimal_number) 
{
    return (unsigned char)decimal_number;
}

int to_decimal(unsigned char binary_number) 
{
    if ((binary_number & 10000000) == 0)
        return binary_number;

    return (int)binary_number - 256;
}

void print_binary(unsigned char binary_number) 
{
    for (int i = 7; i >= 0; i--) 
        printf("%d", (binary_number >> i) & 1);
        
    printf("\n");
}