#include <stdio.h>

void divideRemainder (int *a, int *b);

int main(void) {
    int a, b;

    printf("Input two number : ");
    scanf("%d %d", &a, &b);

    divideRemainder(&a, &b);

    printf("OUTPUT : divide [%d] remainder [%d]\n", a, b);
    return 0;
}

void divideRemainder (int *a, int *b) {
    int quotient = *a / *b;
    int remainder = *a % *b;

    *a = quotient;
    *b = remainder;
    return;
}
