#include <stdio.h>
#include <stdlib.h>

void swap(int*, int*);
void sort(int*, int);
void double_double(int**, int*);
void print_array(int*, int);

int main() {
	int n, i;
	scanf("%d", &n);

	int* arr = (int*) malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	for (i = 0; i < 3; i++) {
		double_double(&arr, &n);
		print_array(arr, n);
	}

	free(arr);

	return 0;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int* a, int size) {
	int i, j;

	for (i = 0; i < size; i++) for (j = size - 1; j > i; j--) {
		if (*(a + j) < *(a + j - 1)) {
			swap(a + j, a + j - 1);
		}
	}
}

void double_double(int** a, int* size) {
	int i;

	*a = (int*) realloc(*a, *size * 2 * sizeof(int));

	for (i = *size - 1; i >= 0; i--) {
		*(*a + i + *size) = (*(*a + i)) * 2;
	}

	sort(*a, *size * 2);

	*size *= 2;
}

void print_array(int* a, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", *(a + i));
	}
	printf("\n");
}
