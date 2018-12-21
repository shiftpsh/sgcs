#include <stdio.h>

int main() {
	/*
		Since cbrt(2147483647) = 1290.16,
		an overflow error will occur when
		n >= 1291, thus we need index of
		squared and cubed array of at most 1290.
	*/

	int MAX_SIZE = 1291;
	int n, i;
	int sq[1291], cb[1291];

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		sq[i] = i * i;
		cb[i] = i * i * i;
	}

	for (i = 1; i <= n; i++) {
		printf("%d ", i);
	}
	printf("\n");

	for (i = 1; i <= n; i++) {
		printf("%d ", sq[i]);
	}
	printf("\n");

	for (i = 1; i <= n; i++) {
		printf("%d ", cb[i]);
	}
	printf("\n");
}