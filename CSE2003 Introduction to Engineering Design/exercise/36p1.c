#include <stdio.h>

int main() {
	int n, x, y, h;
	printf("Input : ");
	scanf("%d", &n);

	if (n % 2 == 0) {
		for (x = 0; x < n; x++) {
			if (x < n / 2) {
				h = n / 2 - x;
			} else {
				h = x - n / 2 + 1;
			}


			for (y = 0; y < h; y++) printf("*");
			for (y = 0; y < n - 2 * h; y++) printf(" ");
			for (y = 0; y < h; y++) printf("*");
			printf("\n");
		}
	} else {
		for (x = 0; x < n; x++) {
			if (x == 0 || x == n - 1) {
				for (y = 0; y < n; y++) printf("*");
			} else {
				if (x < n / 2) {
					h = n / 2 - x + 1;
				} else {
					h = x - n / 2 + 1;
				}

				for (y = 0; y < h; y++) printf("*");
				for (y = 0; y < n - 2 * h; y++) printf(" ");
				for (y = 0; y < h; y++) printf("*");
			}
			printf("\n");
		}
	}

	return 0;
}