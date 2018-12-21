#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef float* Vector_Comp;
typedef float Comp;
typedef float VectorSize;
typedef float Distance;
typedef float Scalar;

typedef struct {
	Vector_Comp comps; int vec_size;
} Vector;

VectorSize vSize(Vector);
Distance DistVector(Vector, Vector);
Scalar innerProduct(Vector, Vector);

int main() {
	int n1, n2, i;

	scanf("%d", &n1);

	Vector v1;
	v1.vec_size = n1;
	v1.comps = (Vector_Comp)malloc(sizeof(Comp) * v1.vec_size);

	for (i = 0; i < n1; i++) {
		scanf("%f", &v1.comps[i]);
	}

	scanf("%d", &n2);

	Vector v2;
	v2.vec_size = n2;
	v2.comps = (Vector_Comp)malloc(sizeof(Comp) * v2.vec_size);

	for (i = 0; i < n2; i++) {
		scanf("%f", &v2.comps[i]);
	}

	printf("%f\n", vSize(v1));
	printf("%f\n", vSize(v2));

	if (v1.vec_size == v2.vec_size) {
		printf("%f\n", DistVector(v1, v2));
		printf("%f\n", innerProduct(v1, v2));
	}

	free(v1.comps);
	free(v2.comps);

	return 0;
}

VectorSize vSize(Vector v) {
	int i;
	VectorSize size = 0;

	for (i = 0; i < v.vec_size; i++) {
		size += v.comps[i] * v.comps[i];
	}

	return sqrt(size);
}

Distance DistVector(Vector v1, Vector v2) {
	if (v1.vec_size != v2.vec_size) return -1;
	int i;
	Distance d = 0;

	for (i = 0; i < v1.vec_size; i++) {
		d += (v1.comps[i] - v2.comps[i]) * (v1.comps[i] - v2.comps[i]);
	}

	return sqrt(d);
}

Scalar innerProduct(Vector v1, Vector v2) {
	if (v1.vec_size != v2.vec_size) return -1;
	int i;
	Scalar s = 0;

	for (i = 0; i < v1.vec_size; i++) {
		s += v1.comps[i] * v2.comps[i];
	}

	return s;
}