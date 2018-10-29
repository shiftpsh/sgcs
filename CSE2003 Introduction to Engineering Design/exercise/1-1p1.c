#include <stdio.h>

int main(void) {
    char a; int b; float c;

    printf("Input one character, one integer, one real number : ");
    scanf("%c %d %f", &a, &b, &c);
    printf("%c %d %f\n", a, b, c);
    return 0;
}
