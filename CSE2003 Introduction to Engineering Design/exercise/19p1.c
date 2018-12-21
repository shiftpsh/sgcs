#include <stdio.h>

int absValue(int n);
void swap(int* a, int* b);

int main(void) {
	int a, b, c;

	printf("Input: ");
	scanf("%d%d%d", &a, &b, &c);

	a = absValue(a);
	b = absValue(b);
	c = absValue(c);

	if (a < c) {
		swap(&a, &c);
	}

	if (b < c) {
		swap(&b, &c);
	}

	if (a < b) {
		swap(&a, &b);
	}

	printf("Result: %d %d %d\n", a, b, c);

	return 0;
}

int absValue(int n) {
	if (n < 0) {
		return -n;
	} else {
		return n;
	}
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}