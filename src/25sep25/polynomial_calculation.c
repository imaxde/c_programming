#include <stdio.h>

int calculate_polynomial(int x) {
    int t = x * x;
    int y = (t + 1) * (t + x) + 1;
    return y;
}

int main(void) {
    int input;
    scanf("%d", &input);
    int result = calculate_polynomial(input);
    printf("%d\n", result);
    return 0;
}