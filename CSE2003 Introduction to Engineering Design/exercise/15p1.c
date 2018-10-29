#include <stdio.h>

int main(void) {
    int n;

    printf("Input : ");
    scanf("%d", &n);

    printf(n % 2 ? "%d is odd number.\n" : "%d is even number.\n", n);

    return 0;
}
