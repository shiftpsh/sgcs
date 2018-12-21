#include <stdio.h>

float average(int matrix[100][100], int col, int n);

int main() {
	int matrix[100][100], n, x, y;

	scanf("%d", &n);

	for (x = 0; x < n; x++) for (y = 0; y < n; y++) {
		scanf("%d", &matrix[x][y]);
	}

	for (x = 0; x < n; x++) {
		printf("%.2f ", average(matrix, x, n));
	}

	return 0;
}

float average(int matrix[100][100], int col, int n) {
	int sum = 0, x;

	for (x = 0; x < n; x++) {
		sum += matrix[x][col];
	}

	return (float) sum / n;
}