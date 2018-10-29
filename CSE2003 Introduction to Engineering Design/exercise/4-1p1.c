#include <stdio.h>

int main(void) {
    int birthday;
    printf("Birthday : ");
    scanf("%d", &birthday);

    int year = birthday / 10000;
    int month = birthday % 10000 / 100;
    int date = birthday % 100;

    printf("Your birthday is %d / %d / %d\n", year, month, date);

    int preferredYear;
    printf("Year : ");
    scanf("%d", &preferredYear);

    printf("In %d, your age is %d\n", preferredYear, preferredYear - year + 1);

    return 0;
}
