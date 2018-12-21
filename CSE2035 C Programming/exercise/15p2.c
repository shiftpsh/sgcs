#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	float price;
	float number;
} Buying;

Buying average(Buying* arr, int n);

int main() {
	int n, i;
	scanf("%d", &n);

	Buying* arr = (Buying*)malloc(sizeof(Buying) * n);
	for (i = 0; i < n; i++) {
		scanf("%f%f", &(arr[i].price), &(arr[i].number));
	}

	Buying avg = average(arr, n);
	printf("%.2f %.2f\n", avg.price, avg.number);

	free(arr);

	return 0;
}

Buying average(Buying* arr, int n) {
	int i;
	Buying sum = {0, 0};

	for (i = 0; i < n; i++) {
		sum.number += arr[i].number;
		sum.price += arr[i].price;
	}

	sum.price /= n;
	sum.number /= n;

	return sum;
}