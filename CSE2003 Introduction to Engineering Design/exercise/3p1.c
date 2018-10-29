#include <stdio.h>
int main(void) {
    int a, b;
    printf("Input two integer: ");
    scanf("%d %d", &a, &b);
    printf("%d / %d is %d with a remainder of %d\n", a, b, a / b, a % b);
    return 0;
}
