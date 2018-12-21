#include <stdio.h>

void shift_right(int*);
void shift_n_right(int*, int);
void print_array(int*);

int main() {
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n;
	scanf("%d", &n);

	shift_n_right(a, n);
	print_array(a);

	return 0;
}

void shift_right(int* a) {
	int temp = *(a + 9);
	for (int i = 9; i >= 1; i--) {
		*(a + i) = *(a + i - 1);
	}
	*(a + 0) = temp;
}

void shift_n_right(int* a, int n) {
	while (n--) shift_right(a);
}

void print_array(int* a) {
	for (int i = 0; i < 10; i++) {
		printf("%d ", *(a + i));
	}
	printf("\n");
}
