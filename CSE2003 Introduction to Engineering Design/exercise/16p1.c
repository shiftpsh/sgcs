#include <stdio.h>

int main(void) {
    int a, b;

    printf("Enter 2 numbers : ");
    scanf("%d%d", &a, &b);

    int carryOperations = 0;

    if (a % 10 + b % 10 >= 10) {
        carryOperations++;
    }

    if (a % 100 + b % 100 >= 100) {
        carryOperations++;
    }

    if (a + b >= 1000) {
        carryOperations++;
    }

    printf(carryOperations == 1 ? "%d carry operation needed.\n" : "%d carry operations needed.\n", carryOperations);

    return 0;
}
