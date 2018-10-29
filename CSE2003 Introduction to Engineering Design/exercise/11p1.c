#include <stdio.h>

int a, b;

void fourMath (int *c, int *d) ;
void printResult (int *c, int *d);

int main(void) {
    int a, b;

    printf("Input two number : ");
    scanf("%d %d", &a, &b);

    fourMath(&a, &b);
    printResult(&a, &b);

    return 0;
}

void fourMath (int *c, int *d) {
    // *c = main.&a
    // *d = main.&b

    a = *c + *d;
    b = *c - *d;

    *c = *c * *d;

    // *c = a * b
    // *d = a / b
    //    = a * b / b / b
    //    = *c / *d / *d
    *d = *c / *d / *d;

    return;
}

void printResult(int *c, int *d) {
    //  a = a + b
    //  b = a - b
    // *c = a * b
    // *d = a / b

    printf("Result:\n");
    printf("a + b = %10d\n",  a);
    printf("a - b = %10d\n",  b);
    printf("a * b = %10d\n", *c);
    printf("a / b = %10d\n", *d);

    return;
}
