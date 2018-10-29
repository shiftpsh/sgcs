#include <stdio.h>

int main() {
	int n, x, s;
	int idx = 0, sum = 0, fails = 0;
	printf("Number of class : ");
	scanf("%d", &n);
	printf("Cutline : ");
	scanf("%d", &x);

	while (idx < n) {
		printf("Input score #%d : ", idx);
		scanf("%d", &s);
		
		sum += s;
		if (s < x) {
			fails++;
		}

		idx++;
	}

	if (n != 0) {
		printf("Average score : %.2f\n", (double) sum / n);
		printf("Number of failures : %d\n", fails);
	} else {
		printf("Average score : %.2f\n", 0.0);
		printf("Number of failures : %d\n", 0);
	}

	return 0;
}