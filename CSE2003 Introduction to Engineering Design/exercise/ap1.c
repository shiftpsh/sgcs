#include <stdio.h>

float toFarenheit(float c);

int main(void) {
	float c;

	printf("Enter Temperature in Celcius : ");
	scanf("%f", &c);

	printf("Temperature in Farenheit     : %.2f\n", toFarenheit(c));

	return 0;
}

float toFarenheit(float c) {
	return c / 5 * 9 + 32;
}