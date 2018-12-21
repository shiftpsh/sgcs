#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
	double x;
	double y;
	double z;
	double r;
} SPHERE;

double DISTANCE(SPHERE, SPHERE);
double CrossSectionArea(SPHERE, SPHERE);
double SurfaceArea(SPHERE, SPHERE);
double Volume(SPHERE, SPHERE);

int main() {
	SPHERE p, q;
	double d;

	printf("1st sphere coordinates : ");
	scanf("%lf%lf%lf", &(p.x), &(p.y), &(p.z));
	printf("1st sphere radius : ");
	scanf("%lf", &(p.r));

	printf("2nd sphere coordinates : ");
	scanf("%lf%lf%lf", &(q.x), &(q.y), &(q.z));
	printf("2nd sphere radius : ");
	scanf("%lf", &(q.r));

	d = DISTANCE(p, q);

	if (d == (p.r + q.r)) {
		printf("Sum of Surface Area : %.2lf\n", SurfaceArea(p, q));
	}
	else if (d < (p.r + q.r)) {
		printf("Sum of Volume : %.2lf\n", Volume(p, q));
	}
	else {
		printf("Sum of Cross Section Area : %.2lf\n", CrossSectionArea(p, q));
	}
	
	return 0;
}

double DISTANCE(SPHERE p, SPHERE q) {
	return sqrt(
		(p.x - q.x) * (p.x - q.x) +
		(p.y - q.y) * (p.y - q.y) +
		(p.z - q.z) * (p.z - q.z)
	);
}

double CrossSectionArea(SPHERE p, SPHERE q) {
	double PI = 3.14;

	return PI * (p.r * p.r + q.r * q.r);
}

double SurfaceArea(SPHERE p, SPHERE q) {
	double PI = 3.14;

	return 4 * PI * (p.r * p.r + q.r * q.r);
}

double Volume(SPHERE p, SPHERE q) {
	double PI = 3.14;

	return 4 * PI * (p.r * p.r * p.r + q.r * q.r * q.r) / 3;
}