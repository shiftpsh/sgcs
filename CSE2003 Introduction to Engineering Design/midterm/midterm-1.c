#include <stdio.h>

/**
 *  April 19th, 2018
 *  CSE2003 Midterm Exam
 *  Problem #1
 */

float weightSum(int* five_ago, int* four_ago, int* three_ago, int* two_ago, int* one_ago);
void printBySelection(float weight_sum);

int main(void) {
	int five_ago, four_ago, three_ago, two_ago, one_ago;

	scanf("%d%d%d%d%d", &five_ago, &four_ago, &three_ago, &two_ago, &one_ago);
	printBySelection(weightSum(&five_ago, &four_ago, &three_ago, &two_ago, &one_ago));

	return 0;
}

float weightSum(int* five_ago, int* four_ago, int* three_ago, int* two_ago, int* one_ago) {
	float sum = 0.0f;

	sum += *five_ago * 0.04f;
	sum += *four_ago * 0.06f;
	sum += *three_ago * 0.15f;
	sum += *two_ago * 0.25f;
	sum += *one_ago * 0.5f;

	return sum;
}

void printBySelection(float weight_sum) {
	if (weight_sum >= 150) {
		printf("%.2f very bad\n", weight_sum);
	}
	if (weight_sum >=  80 && weight_sum < 150) {
		printf("%.2f bad\n", weight_sum);
	}
	if (weight_sum >=  30 && weight_sum <  80) {
		printf("%.2f normal\n", weight_sum);
	}
	if (                     weight_sum <  30) {
		printf("%.2f good\n", weight_sum);
	}
}