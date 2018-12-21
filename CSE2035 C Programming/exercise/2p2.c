#include <stdio.h>

void swap(int*, int*);
void sort4(int*, int*, int*, int*);

int main() {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	sort4(&a, &b, &c, &d);
	printf("%d %d %d %d\n", a, b, c, d);
	
	return 0;
}

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// a < b < c < d
void sort4(int* a, int* b, int* c, int* d) {
	if (*a > *b) swap(a, b);
	if (*b > *c) swap(b, c);
	if (*c > *d) swap(c, d);
	if (*a > *b) swap(a, b);
	if (*b > *c) swap(b, c);
	if (*a > *b) swap(a, b);
}
