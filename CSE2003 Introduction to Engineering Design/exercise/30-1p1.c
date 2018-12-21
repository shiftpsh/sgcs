#include <stdio.h>

void snail(int snail[20][20], int n);
void print_snail(int snail[20][20], int n);

int main() {
	int arr[20][20], i, n;

	scanf("%d", &n);

	for (i = n; i > 0; i--) {
		snail(arr, i);
		print_snail(arr, i);
		printf("\n");
	}

	return 0;
}

void snail(int arr[20][20], int n) {
	int dx[4] = {0, 1, 0, -1}; // directions of x
	int dy[4] = {1, 0, -1, 0}; // directions of y
	int d = 0, x = 0, y = 0, i, j, nx, ny;

	for (i = 0; i < n; i++) for (j = 0; j < n; j++) {
		arr[i][j] = -1; // Initalize array
	}

	for (i = 1; i <= n * n; i++) {
		arr[x][y] = i;

		nx = x + dx[d];
		ny = y + dy[d];

		if ((nx == -1 || nx == n) || (ny == -1 || ny == n) // new (x, y) out of array bounds
			|| (arr[nx][ny] != -1)) { // (x, y) already calculated
			d++;
			d %= 4;
		}

		x += dx[d];
		y += dy[d];
	}
}

void print_snail(int snail[20][20], int n) {
	int x, y;
	for (x = 0; x < n; x++) {
		for (y = 0; y < n; y++) {
			printf("%4d ", snail[x][y]);
		}
		printf("\n");
	}
}