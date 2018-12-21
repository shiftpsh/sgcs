#include <stdio.h>

int main() {
	double a, b, c, d;
	double *pa, *pb, *pc, *pd;

	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	pa = &a; pb = &b; pc = &c; pd = &d;

	if (*pa == *pc && *pb == *pd) {
		printf("oo\n");
	} else if (*pa == *pc) {
		printf("0\n");
	} else {
		printf("1\n");
	}
	return 0;
}
