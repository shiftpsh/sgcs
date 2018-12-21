#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, i, j, **p;
	scanf("%d", &n);

	p = (int**) malloc(n * sizeof(int*));
	for (i = 0; i < n; i++) {
		p[i] = (int*) malloc((i + 1) * sizeof(int));
	}

	p[0][0] = 1;

	for (i = 0; i < n; i++) {
		p[i][0] = 1;
		p[i][i] = 1;
	}

	for (i = 1; i < n; i++) for (j = 1; j < i; j++) {
		p[i][j] = p[i - 1][j - 1] + p[i - 1][j];
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			printf("%d ", p[i][j]);
		}

		printf("\n");
	}

	for (i = 0; i < n; i++) {
                free(p[i]);
        }

	free(p);

	return 0;
}
