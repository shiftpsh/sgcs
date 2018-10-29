#include <stdio.h>

void multiply(int matrix[3][4][4]);

int main() {
	int matrix[3][4][4], x, y;

	printf("First matrix:\n");
	for (x = 0; x < 4; x++) for (y = 0; y < 4; y++) {
		scanf("%d", &matrix[0][x][y]);
	}

	printf("Second matrix:\n");
	for (x = 0; x < 4; x++) for (y = 0; y < 4; y++) {
		scanf("%d", &matrix[1][x][y]);
	}

	multiply(matrix);
	printf("Result:\n");

	for (x = 0; x < 4; x++) {
		for (y = 0; y < 4; y++) {
			printf("%8d", matrix[2][x][y]);
		}
		printf("\n");
	}

	return 0;
}

void multiply(int matrix[3][4][4]) {
	int x, y, i;

	for (x = 0; x < 4; x++) for (y = 0; y < 4; y++) {
		matrix[2][x][y] = 0;
		for (i = 0; i < 4; i++) {
			matrix[2][x][y] += matrix[0][x][i] * matrix[1][i][y];
		}
	}

	return;
}