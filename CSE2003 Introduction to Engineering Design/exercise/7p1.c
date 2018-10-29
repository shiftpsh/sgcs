#include <stdio.h>

float x(int a, int b, int c, int d);
float y(int a, int b, int c, int d);

int main(void) {
    int a, b, c, d;

    printf("1st equation: y = ax - b, input 'a' and 'b'\n");
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);

    printf("2nd equation: y = cx - d, input 'c' and 'd'\n");
    printf("c = ");
    scanf("%d", &c);
    printf("d = ");
    scanf("%d", &d);

    printf("Result:\n");
    printf("x is %f\n", x(a, b, c, d));
    printf("y is %f\n", y(a, b, c, d));

    return 0;
}

float x(int a, int b, int c, int d) {
    /**
     *         ax - b = cx - d
     *       (a - c)x = b - d
     *              x = (b - d) / (a - c)
     */

    return (float)(b - d) / (float)(a - c);
}

float y(int a, int b, int c, int d) {
    /**
     *    (y + b) / a = (y + d) / c
     *        cy + bc = ay + ad
     *       (c - a)y = ad - bc
     *              y = (ad - bc) / (c - a)
     */

    return (float)(a * d - b * c) / (float)(c - a);
}

