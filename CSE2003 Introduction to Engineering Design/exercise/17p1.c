#include <stdio.h>

float avgFunc(float a, float b, float c);
char gradeFunc(float score);

int main(void) {
	float a, b, c;

	printf("Input: ");
	scanf("%f%f%f", &a, &b, &c);
	printf("Grade: %c\n", gradeFunc(avgFunc(a, b, c)));
	scanf("%f", &a);

	return 0;
}

float avgFunc(float a, float b, float c) {
	return (a + b + c) / 3;
}

char gradeFunc(float score) {
	if (score >= 50) {
		if (score >= 70) {
			if (score >= 80) {
				if (score >= 90) {
					return 'A';
				} else {
					return 'B';
				}
			} else {
				return 'C';
			}
		} else {
			return 'D';
		}
	} else {
		return 'F';
	}

	/*
	 *  Also can be achieved
	 *  w/out else branches:

		if (score >= 90) return 'A';
		if (score >= 80) return 'B';
		if (score >= 70) return 'C';
		if (score >= 50) return 'D';
		return 'F';

	*/
}