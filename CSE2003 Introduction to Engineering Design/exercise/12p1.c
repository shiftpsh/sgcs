#include <stdio.h>

int x = 1;

int fibonacci (int *y);

int main(void) {
    int x = 0;

    printf("f(1) = %5d\n", fibonacci(&x));
    printf("f(2) = %5d\n", fibonacci(&x));
    printf("f(3) = %5d\n", fibonacci(&x));
    printf("f(4) = %5d\n", fibonacci(&x));
    printf("f(5) = %5d\n", fibonacci(&x));
    printf("f(6) = %5d\n", fibonacci(&x));
    printf("f(7) = %5d\n", fibonacci(&x));
    printf("f(8) = %5d\n", fibonacci(&x));
    printf("f(9) = %5d\n", fibonacci(&x));

    return 0;
}

int fibonacci (int *y) {
    int temp = x;

    x += *y;
    *y = temp;
    return x;
}
