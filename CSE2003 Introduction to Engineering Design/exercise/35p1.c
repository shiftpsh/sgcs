#include <stdio.h>

int main() {
	int n, pascal[20][20], h, x;
	printf("Input size of triangle : ");
	scanf("%d", &n);

	for (h = 0; h < n; h++) for (x = 0; x <= h; x++) {
		if (x == 0 || x == h) {
			pascal[h][x] = 1;
		} else {
			pascal[h][x] = pascal[h - 1][x] + pascal[h - 1][x - 1];
		}
	}

	for (h = 0; h < n; h++) {
		for (x = 0; x <= h; x++) {
			printf("%d ", pascal[h][x]);
		}
		printf("\n");
	}

	return 0;
}