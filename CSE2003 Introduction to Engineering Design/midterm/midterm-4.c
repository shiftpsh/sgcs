#include <stdio.h>

/**
 *  April 19th, 2018
 *  CSE2003 Midterm Exam
 *  Problem #4
 */

float check(float c1, float c2, float c3, float c4);

int main(void) {
	float c1, c2, c3, c4;

	scanf("%f%f%f%f", &c1, &c2, &c3, &c4);

	printf("%.1f\n", check(c1, c2, c3, c4));

	return 0;
}

float check(float c1, float c2, float c3, float c4) {
	float a = c2 - c1;
	float b = c3 - c2;
	float c = c4 - c3;

	float sum = a + b + c;
	if (a > b && a > c) sum -= a;
	if (b > a && b > c) sum -= b;
	if (c > a && c > b) sum -= c;

	return sum;
}