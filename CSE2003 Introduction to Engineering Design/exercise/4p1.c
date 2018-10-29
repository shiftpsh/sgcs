#include <stdio.h>

int main(void) {
    int price;
    printf("Price : ");
    scanf("%d", &price);

    int payment3 = price;
    int payment6 = price;

    for (int i = 0; i < 3; i++) {
        payment6 *= 1.05;
    }

    printf("----------------output----------------\n");
    printf("Month\t\t: %10d%10d\n", 3, 6);
    printf("Payment\t\t: %10d%10d\n", payment3, payment6);
    printf("Pay/month\t: %10.2f%10.2f\n", (float) payment3 / 3, (float) payment6 / 6);

    return 0;
}
