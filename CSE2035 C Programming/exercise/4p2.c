#include <stdio.h>

void mat_mul(int[100][100], int[100][100], int[100][100], int);

int main() {
	int n, a[100][100], b[100][100], c[100][100], i, j;

	scanf("%d", &n);

	for (i = 0; i < n; i++) for (j = 0; j < n; j++) {
		scanf("%d", *(a + i) + j); // &(*(*(a + i) + j)) == *(a + i) + j
	}
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) {
		scanf("%d", *(b + i) + j); // &(*(*(a + i) + j)) == *(a + i) + j
	}

	mat_mul(a, b, c, n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", *(*(c + i) + j));
		}
		printf("\n");
	}

	return 0;
}

void mat_mul(int a[100][100], int b[100][100], int c[100][100], int n) {
	int i, j, k, sum;

	for (i = 0; i < n; i++) for (j = 0; j < n; j++) {
		sum = 0;

		for (k = 0; k < n; k++) {
			sum += (*(*(a + i) + k)) * (*(*(b + k) + j));
		}

		*(*(c + i) + j) = sum;
	}
}
