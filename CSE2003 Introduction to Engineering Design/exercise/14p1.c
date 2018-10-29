#include <stdio.h>

int main(void) {
    int year;

    printf("Enter the year to be tested : ");
    scanf("%d", &year);

    int flag = 0; // 1 if leap, 0 if not leap

    if (year %   4 == 0) flag = 1;
    if (year % 100 == 0) flag = 0;
    if (year % 400 == 0) flag = 1;

    if (flag) {
        printf("Year %d is a leap year.\n", year);
    } else {
        printf("Year %d is NOT a leap year.\n", year);

        int lastLeapYear = (year / 4) * 4;
        if (lastLeapYear % 100 == 0 && lastLeapYear % 400 != 0) lastLeapYear -= 4;

        printf("Last leap year was year %d.\n", lastLeapYear);
    }

    return 0;
}
