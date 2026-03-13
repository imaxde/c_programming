#pragma once

// складывает 2 двоичных числа в столбик
unsigned char plus(unsigned char n1, unsigned char n2);

// перевод числа от -128 до 127 в представление в дополнительном коде 
unsigned char to_binary(int decimal_number);

// дополнительный код в целое десятичное число
int to_decimal(unsigned char binary_number);

// печатает двоичное число
void print_binary(unsigned char binary_number);
