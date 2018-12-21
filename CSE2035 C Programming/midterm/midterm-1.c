#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void pointerSort(int**, int, int);
void swap(int**, int**);
void printArray(int**, int);
void printPointerArray(int**, int);

int main() {
	int ASC = 0, DESC = 1;
	int n, i, *ref, **arr;
	scanf("%d", &n);

	ref = (int*)malloc(n * sizeof(int));
	arr = (int**)malloc(n * sizeof(int*));

	for (i = 0; i < n; i++) {
		scanf("%d", &ref[i]);
		arr[i] = &(ref[i]);
	}

	pointerSort(arr, n, ASC);
	printPointerArray(arr, n);

	pointerSort(arr, n, DESC);
	printPointerArray(arr, n);

	printArray(ref, n);

	free(ref);
	free(arr);

	return 0;
}

void pointerSort(int** arr, int size, int flag)  {
	int ASC = 0, DESC = 1;
	int i, j;

	for (i = 0; i < size; i++) for (j = i; j < size; j++) {
		if (*(arr[i]) < *(arr[j])) {
			if (flag == DESC) swap(&(arr[i]), &(arr[j]));
		}
		else {
			if (flag == ASC) swap(&(arr[i]), &(arr[j]));
		}
	}
}

void swap(int** a, int** b) {
	int* c = *a;
	*a = *b;
	*b = c;
}

void printArray(int* arr, int n) {
	int i;

	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");
}

void printPointerArray(int** arr, int n) {
	int i;

	for (i = 0; i < n; i++) {
		printf("%d ", *(arr[i]));
	}

	printf("\n");
}