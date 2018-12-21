#include <stdio.h>

int main() {
	int h, w, n, a[9][99], i, j;
	scanf("%d%d%d", &h, &w, &n);

	for (i = 0; i < h; i++) for (j = 0; j < w; j++) {
		*(*(a + i) + j) = (i + 1) * 100 + (j + 1);
	}

	for (j = 0; j < w; j++) {
		for (i = 0; i < h; i++) {
			n--;
			if (n == 0) break;
		}
		if (n == 0) {
			printf("%d", *(*(a + i) + j));
			break;
		}
	}

	printf("\n");

	return 0;
}
