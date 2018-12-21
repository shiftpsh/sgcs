#include <stdio.h>
#include <stdlib.h>

void swap(int*, int*);
void sort(int*, int);
int* get_next_process(int*, int);
void print_array(int*, int);

int main() {
	int n, i;
	int* arr;
	scanf("%d", &n);

	arr = (int*) malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		scanf("%d", arr + i); // &(*(arr + i)) == arr + i
	}

	do {
		arr = get_next_process(arr, n);
		n = (n + 1) / 2;
	} while (n > 1);

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
                        if (*(a + j - 1) < *(a + j)) {
                                swap((a + j - 1), (a + j));
                        }
                }
        }
}

int* get_next_process(int* prev_pointer, int size) {
	int next_size, i;
	int *next_pointer;

	sort(prev_pointer, size);

	next_size = (size + 1) / 2;
	next_pointer = (int*) calloc(next_size * sizeof(int), 0);

	for (i = next_size - 1; i >= 0; i--) {
		if (i == next_size - 1) {
			if (size % 2 == 0) {
				*(next_pointer + i) = *(prev_pointer + 2 * i) + *(prev_pointer + 2 * i + 1);
			} else {
				*(next_pointer + i) = *(prev_pointer + 2 * i);
			}
		} else {
			*(next_pointer + i) = *(prev_pointer + 2 * i) + *(prev_pointer + 2 * i + 1);
		}
	}

	print_array(next_pointer, next_size);

	return next_pointer;
}

void print_array(int* arr, int size) {
	int i;

	for (i = 0; i < size; i++) {
		printf("%d ", *(arr + i));
	}

	printf("\n");
}
