#pragma once
#include <stdint.h>
#include <stdbool.h>

struct BinNumber {
    bool bits[32];
};

// складывает 2 двоичных числа в столбик
struct BinNumber plus(struct BinNumber n1, struct BinNumber n2);

// перевод 32-битного числа в двочиную систему
struct BinNumber toBinary(int32_t decimalNumber);

// дополнительный код в целое десятичное число
int32_t toDecimal(struct BinNumber binaryNumber) ;

// печатает двоичное число
void printBinary(struct BinNumber binaryNumber) ;
