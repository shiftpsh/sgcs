#include <stdio.h>

void* f(void*, void*, int);

int main() {
	int option;
	int a, b;
	float fa, fb;
	double da, db;
	void *pa, *pb, *ans;

	scanf("%d", &option);

	switch (option)
	{
	case 0:
		scanf("%d%d", &a, &b);
		pa = &a;
		pb = &b;

		ans = f(pa, pb, 0);
		printf("%d\n", *((int*)ans));
		break;
	case 1:
		scanf("%f%f", &fa, &fb);
		pa = &fa;
		pb = &fb;

		ans = f(pa, pb, 1);
		printf("%f\n", *((float*)ans));
		break;
	case 2:
		scanf("%lf%lf", &da, &db);
		pa = &da;
		pb = &db;

		ans = f(pa, pb, 2);
		printf("%lf\n", *((double*)ans));
		break;
	default:
		break;
	}

	return 0;
}

void* f(void* pa, void* pb, int option) {
	int *a0, *b0;
	float *a1, *b1;
	double *a2, *b2;

	switch (option)
	{
	case 0:
		a0 = (int*) pa;
		b0 = (int*) pb;

		if (*a0 > *b0) {
			return pb;
		}
		else {
			return pa;
		}
		break;
	case 1:
		a1 = (float*)pa;
		b1 = (float*)pb;

		if (*a1 > *b1) {
			return pb;
		}
		else {
			return pa;
		}
		break;
	case 2:
		a2 = (double*)pa;
		b2 = (double*)pb;

		if (*a2 > *b2) {
			return pb;
		}
		else {
			return pa;
		}
		break;
	default:
		break;
	}
}
