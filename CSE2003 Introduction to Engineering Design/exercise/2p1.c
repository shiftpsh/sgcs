#include <stdio.h>

int main(void) {
    int a;

    printf("Input a: ");
    scanf("%d", &a);

    printf("a = %d\n", a);
    printf("a = a + 1; a = %d\n", ++a);
    printf("a = a + 1; a = %d\n", ++a);
    printf("a = a - 1; a = %d\n", --a);

    return 0;
}
