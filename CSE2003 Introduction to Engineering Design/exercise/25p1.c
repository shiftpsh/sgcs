#include <stdio.h>

int isDivisor(int m, int n);
int isPrime(int n);

int main() {
	int n, i;
	printf("Input : ");
	scanf("%d", &n);

	// O(n^2) nooo
	for (i = 2; i <= n; i++) {
		if (isDivisor(i, n) && isPrime(i)) {
			printf("%7d", i);
		}
	}

	printf("\n");

	return 0;
}

int isDivisor(int m, int n) {
	if (n % m == 0) {
		return 1;
	} else {
		return 0;
	}
}

int isPrime(int n) {
	int flag = 1;
	int i;

	for (i = 2; i < n; i++) {
		if (isDivisor(i, n)) {
			flag = 0;
			break;
		}
	}

	return flag;
}