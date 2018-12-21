#include <stdio.h>
#include <stdlib.h>

void multiply_matrix(int**, int**, int**, int);
void print_matrix(int**, int);

int main() {
	int n, i, j, **a, **b, **c;
	scanf("%d", &n);

	a = (int**) malloc(n * sizeof(int*));
	b = (int**) malloc(n * sizeof(int*));
	c = (int**) malloc(n * sizeof(int*));

	for (i = 0; i < n; i++) {
		a[i] = (int*) malloc(n * sizeof(int));
		b[i] = (int*) malloc(n * sizeof(int));
		c[i] = (int*) malloc(n * sizeof(int));
	}

	for (i = 0; i < n; i++) for (j = 0; j < n; j++) {
		scanf("%d", &a[i][j]);
	}

	for (i = 0; i < n; i++) for (j = 0; j < n; j++) {
                scanf("%d", &b[i][j]);
        }

	multiply_matrix(a, b, c, n);
	print_matrix(c, n);

	for (i = 0; i < n; i++) {
                free(a[i]);
		free(b[i]);
		free(c[i]);
        }

	free(a);
	free(b);
	free(c);

	return 0;
}

void multiply_matrix(int** a, int** b, int** c, int n) {
	int i, j, k;

	for (i = 0; i < n; i++) for (j = 0; j < n; j++) {
		c[i][j] = 0;

		for (k = 0; k < n; k++) {
			c[i][j] += a[i][k] * b[k][j];
		}
	}
}

void print_matrix(int** a, int n) {
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
