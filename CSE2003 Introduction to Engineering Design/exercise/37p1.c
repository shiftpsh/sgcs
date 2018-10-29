#include <stdio.h>

void merge(int arrayA[], int arrayB[], int arrayMerge[]);

int main() {
	int arrayA[5], arrayB[5], arrayMerge[10], i;

	printf("Input array A : ");
	for (i = 0; i < 5; i++) {
		scanf("%d", &arrayA[i]);
	}

	printf("Input array B : ");
	for (i = 0; i < 5; i++) {
		scanf("%d", &arrayB[i]);
	}

	merge(arrayA, arrayB, arrayMerge);

	printf("Merged array : ");
	for (i = 0; i < 10; i++) {
		printf("%d ", arrayMerge[i]);
	}
	printf("\n");

	return 0;
}

void merge(int arrayA[], int arrayB[], int arrayMerge[]) {
	int aidx = 0, bidx = 0, i;

	for (i = 0; i < 10; i++) {
		if (aidx < 5 && bidx < 5) {
			if (arrayA[aidx] > arrayB[bidx]) {
				arrayMerge[i] = arrayB[bidx];
				bidx++;
			} else {
				arrayMerge[i] = arrayA[aidx];
				aidx++;
			}
		} else if (aidx < 5) {
			arrayMerge[i] = arrayA[aidx];
			aidx++;
		} else {
			arrayMerge[i] = arrayB[bidx];
			bidx++;
		}
	}

	return;
}



