#include <stdio.h>

float average(int a, int b, int c, int d);
float deviation(int n, float average);

int main(void) {
    int a, b, c, d;

    printf("Enter the first  number : ");
    scanf("%d", &a);
    printf("Enter the second number : ");
    scanf("%d", &b);
    printf("Enter the third  number : ");
    scanf("%d", &c);
    printf("Enter the fourth number : ");
    scanf("%d", &d);

    float av = average(a, b, c, d);

    printf("******** Average is %6.2f ********\n", av);
    printf("First  number : %10d  -- Deviation: %10.2f\n", a, deviation(a, av));
    printf("Second number : %10d  -- Deviation: %10.2f\n", b, deviation(b, av));
    printf("Third  number : %10d  -- Deviation: %10.2f\n", c, deviation(c, av));
    printf("Fourth number : %10d  -- Deviation: %10.2f\n", d, deviation(d, av));

    return 0;
}

float average(int a, int b, int c, int d) {
    return (float)(a + b + c + d) / 4;
}

float deviation(int n, float average) {
    return n - average;
}
