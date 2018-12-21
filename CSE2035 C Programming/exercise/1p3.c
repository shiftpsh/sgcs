#include <stdio.h>

int main() {
	double x1, y1, z1, x2, y2, z2;
	double *px1, *py1, *pz1, *px2, *py2, *pz2;

	scanf("%lf%lf%lf", &x1, &y1, &z1);
        scanf("%lf%lf%lf", &x2, &y2, &z2);

	px1 = &x1; py1 = &y1; pz1 = &z1;
	px2 = &x2; py2 = &y2; pz2 = &z2;

	// x1 = abs(x1 - x2),
	// y1 = abs(y1 - y2),
	// z1 = abs(z1 - z2)
	*px1 -= *px2; *py1 -= *py2; *pz1 -= *pz2;
	if (*px1 < 0) *px1 *= -1;
        if (*py1 < 0) *py1 *= -1;
        if (*pz1 < 0) *pz1 *= -1;

	// x1 = max(x1, y1, z1)
	if (*px1 < *py1) *px1 = *py1;
	if (*px1 < *pz1) *px1 = *pz1;

	printf("%lf\n", *px1);

	return 0;
}
