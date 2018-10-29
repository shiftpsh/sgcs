#include <stdio.h>

int add(int a, int b);

int main(void) {
    int a, b;
    printf("Input first number: ");
    scanf("%d", &a);
    printf("Input second number: ");
    scanf("%d", &b);

    printf("%d + %d = %d\n", a, b, add(a, b));
    return 0;
}

int add(int a, int b) {
    return a + b;
}
