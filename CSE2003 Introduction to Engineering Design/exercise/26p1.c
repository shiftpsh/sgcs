#include <stdio.h>

int palindrome(int num, int digit);

int main() {
	int n;
	printf("Input : ");
	scanf("%d", &n);

	if (n < 0) {
		printf("Input number cannot be negative.\n");
	} else if (palindrome(n, 1)) {
		printf("%d is a palindrome number.\n", n);
	} else {
		printf("%d is NOT a palindrome number.\n", n);
	}

	return 0;
}

int palindrome(int num, int digit) {
	int len = 1;
	int lbase, hbase, ldigit, hdigit;

	if (num != 0) {
		// len = 10 ^ (length of num - 1)
		while (num > len) {
			len *= 10;
		}
		len /= 10;
	}

	lbase = digit;
	hbase = len / digit;

	ldigit = (num / lbase) % 10;
	hdigit = (num / hbase) % 10;

	if (lbase == hbase) {
		// checking center digit if length of n is odd
		return 1;
	} else if (lbase * 10 == hbase) {
		// checking center digit if length of n is even
		if (ldigit == hdigit) {
			return 1;
		} else {
			return 0;
		}
	} else {
		if (ldigit == hdigit) {
			return palindrome(num, digit * 10);
		} else {
			return 0;
		}
	}
}