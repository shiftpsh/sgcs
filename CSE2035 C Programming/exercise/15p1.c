#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int numerator;
	int denominator;
} FRACTION;

void multiFr(FRACTION*, FRACTION*, FRACTION*);

int main() {
	int a, b, c, d;
	FRACTION p, q, r;

	printf("x/y : ");
	scanf("%d/%d", &a, &b);
	printf("x/y : ");
	scanf("%d/%d", &c, &d);

	p.numerator = a;
	p.denominator = b;
	q.numerator = c;
	q.denominator = d;

	multiFr(&p, &q, &r);

	printf(
		"%d/%d * %d/%d = %d/%d\n",
		p.numerator, p.denominator,
		q.numerator, q.denominator,
		r.numerator, r.denominator
		);

	return 0;
}

void multiFr(FRACTION* pFr1, FRACTION* pFr2, FRACTION* pRes) {
	pRes->numerator = pFr1->numerator * pFr2->numerator;
	pRes->denominator = pFr1->denominator * pFr2->denominator;
}