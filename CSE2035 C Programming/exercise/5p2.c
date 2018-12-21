
#include <stdio.h>
#include <stdlib.h>

void swap(int*, int*);
void sort(int*, int);
void all_sort(int[][100], int, int);
int binary_search(int*, int*, int, int**);
int all_binary_search(int[][100], int, int, int, int**);

int main() {
	int i, j, n, m, k, result, *findPtr;
	int a[100][100];

	scanf("%d%d%d", &n, &m, &k);

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", (*(a + i) + j));
		}
	}

	all_sort(a, n, m);
	result = all_binary_search(a, n, m, k, &findPtr);

	printf("%d\n%p\n", result, findPtr);

	return 0;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int* a, int m) {
	int i, j;

	for (i = m - 1; i >= 0; i--) {
		for (j = 1; j <= i; j++) {
			if (*(a + j - 1) > *(a + j)) {
				swap((a + j - 1), (a + j));
			}
		}
	}
}

void all_sort(int a[][100], int n, int m) {
	int i;

	for (i = 0; i < n; i++) {
		sort(a[i], m);
	}
}

int binary_search(int* a, int* endPtr, int key, int** findPtr) {
	int *l, *m, *r;

	l = a;
	r = endPtr;

	while (l <= r) {
		m = l + (r - l) / 2;

		if (key > *m) {
			l = m + 1;
		} else if (key < *m) {
			r = m - 1;
		} else {
			l = r + 1;
		}
	}
	*findPtr = m;
	return (key == *m);
}

int all_binary_search(int a[][100], int n, int m, int key, int **findPtr) {
	int i;
	int flag = 0;

	for (i = 0; i < n; i++) {
		if (binary_search(a[i], a[i] + m - 1, key, findPtr)) {
			flag = 1;
			break;
		}
	}

	return flag;
}
