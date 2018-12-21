#include <stdio.h>

void f(int*, int*, int*, int);

int main() {
	int h, m, s, t;
	scanf("%d%d%d%d", &h, &m, &s, &t);

	f(&h, &m, &s, t);
	printf("%02d:%02d:%02d\n", h, m, s);
	return 0;
}

void f(int* h, int* m, int* s, int t) {
	*s += t;
	*m += *s / 60;
	*s %= 60;
	*h += *m / 60;
	*m %= 60;
	*h %= 24;
}
