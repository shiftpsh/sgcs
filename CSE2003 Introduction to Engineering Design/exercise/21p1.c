#include <stdio.h>

int main() {
	int n, y = 0;
	printf("Size : ");
	scanf("%d", &n);

	while (y < n) {
		int asterisks = y * 2 + 1;
		int spaces = n - y;

		int aidx = 0;
		int sidx = 0;

		while (sidx < spaces) {
			printf(" ");
			sidx++;
		}

		while (aidx < asterisks) {
			printf("*");
			aidx++;
		}

		printf("\n");
		y++;
	}

	return 0;
}