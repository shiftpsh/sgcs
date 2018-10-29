#include <stdio.h>

void sqr(int n);
void printOne(int n);

int main(void) {
    int n;
    printf("Input: ");
    scanf("%d", &n);
    sqr(n);

    return 0;
}

void sqr(int n) {
    printOne(n * n);
    return;
}

void printOne(int n) {
    printf("Result: %d\n", n);
    return;
}
