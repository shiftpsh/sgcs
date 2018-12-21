#include <stdio.h>

void is_prime(int***);

int main() {
	int a;
	scanf("%d", &a);

	int *pa;
	pa = &a;
	int **ppa;
	ppa = &pa;

	is_prime(&ppa);

	printf("%d\n", **ppa);

	return 0;
}

void is_prime(int*** a) {
	if (***a <= 1) {
		***a = 0;
	}
	else {
		int p[201];
		for (int i = 0; i <= 200; i++) p[i] = 1;

		for (int i = 2; i <= 200; i++) {
			if (p[i]) for (int j = i * 2; j <= 200; j += i) {
				p[j] = 0;
			}
		}

		***a = p[***a];
	}
}
