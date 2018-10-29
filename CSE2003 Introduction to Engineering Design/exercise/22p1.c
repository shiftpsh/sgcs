#include <stdio.h>

void swap(int* a, int* b);
int sumInRange(int a, int b);

int main(void) {
	int a, b;

	printf("Input first number  : ");
	scanf("%d", &a);
	printf("Input second number : ");
	scanf("%d", &b);

	if (a > b) {
		swap(&a, &b);
	}

	if (a < 1) {
		printf("Input is less than 1\n");
	} else {
		printf("Result: %d\n", sumInRange(a, b));
	}

	return 0;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// O(b - a)
int sumInRange(int a, int b) {
	int sum = 0;
	int i;
	for (i = a; i <= b; i++) {
		if (i % 2 == 0 || i % 3 == 0) {
			sum += i;
		}
	}

	return sum;
}

// Also can be achieved in O(1) time w/out for loop:
/*
int sumInRange(int a, int b) {
	int a2 = (a - 1) / 2;
	int a3 = (a - 1) / 3;
	int a6 = (a - 1) / 6;
	int b2 = b / 2;
	int b3 = b / 3;
	int b6 = b / 6;

	int sum_a2 = a2 * (a2 + 1) / 2 * 2;
	int sum_a3 = a3 * (a3 + 1) / 2 * 3;
	int sum_a6 = a6 * (a6 + 1) / 2 * 6;
	int sum_b2 = b2 * (b2 + 1) / 2 * 2;
	int sum_b3 = b3 * (b3 + 1) / 2 * 3;
	int sum_b6 = b6 * (b6 + 1) / 2 * 6;

	return (sum_b3 + sum_b2 - sum_b6) - (sum_a2 + sum_a3 - sum_a6);
}
*/