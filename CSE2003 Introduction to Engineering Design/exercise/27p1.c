#include <stdio.h>

int main() {
	int arr[10];
	int i;
	int max = -2047483648;
	int min = 2147483647;

	for (i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);	
	}

	// Swapping
	for (i = 0; i < 5; i++) {
		int temp = arr[i];
		arr[i] = arr[9 - i];
		arr[9 - i] = temp;
	}

	// Printing & calculating min / max
	for (i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
		if (max < arr[i]) {
			max = arr[i];
		}
		if (min > arr[i]) {
			min = arr[i];
		}
	}
	printf("\n");

	printf("Max: %d, Min: %d\n", max, min);
}