#include <stdio.h>

int fibo(int n);

int main() {
	int n;
	int iterations = 0;
	
	printf("Input n: ");
	scanf("%d", &n);

	if (n >= 0) {
		printf("fibo(%d) = %d\n", n, fibo(n));
	} else {
		printf("n cannot be a negative number.\n");
	}

	return 0;
}

int fibo(int n) {
	int a = 1, b = 0;
	int temp;
	int iterations = 0;

	if (n != 0) {
		do {
			temp = a;
			a += b;
			b = temp;

			iterations++;
		} while (iterations < n);

		return b;
	} else {
		return 0;
	}
}