#include <stdio.h>
#include <stdlib.h>

void print_array(int*, int);
void push_back(int**, int*, int);
void pop_back(int**, int*);
double average(int*, int);
double variance(int*, int);

int main() {
	int* a = (int*) malloc(0);
	int n, i, size = 0, op, x;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &op);

		if (op == 1) { // push_back
			scanf("%d", &x);
			push_back(&a, &size, x);
		} else if (op == 2) { // pop_back
			pop_back(&a, &size);
		}
	}

	free(a);

	return 0;
}

void print_array(int* a, int size) {
	int i;

	for (int i = 0; i < size; i++) {
		printf("%d ", *(a + i));
	}
	printf("\n");
}

void push_back(int** a, int* size, int value) {
	(*size)++;
	*a = (int*) realloc(*a, *size * sizeof(int));
	*(*a + *size - 1) = value;

	print_array(*a, *size);
	printf("%lf %lf\n", average(*a, *size), variance(*a, *size));
}

void pop_back(int** a, int* size) {
	if (*size == 0) return;

	(*size)--;
	*a = (int*) realloc(*a, *size * sizeof(int));

	print_array(*a, *size);
        printf("%lf %lf\n", average(*a, *size), variance(*a, *size));
}

double average(int* a, int size) {
	int i;
	double sum = 0.0;

	if (size == 0) return 0.0;

	for (i = 0; i < size; i++) {
		sum += *(a + i);
	}

	return sum / size;
}

double variance(int* a, int size) {
	int i;
        double sum = 0.0, avg = average(a, size);

        if (size == 0) return 0.0;

        for (i = 0; i < size; i++) {
                sum += (*(a + i) - avg) * (*(a + i) - avg);
        }

        return sum / size;
}

