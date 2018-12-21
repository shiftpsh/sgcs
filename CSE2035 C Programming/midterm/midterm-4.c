#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void readPoint(char*, int**, int**, int*);
void doJavis(int*, int*, int*, int);
void printQ(int*, int*, int*);

int main() {
	char filename[21];
	int *xarr, *yarr, n, *idx;

	scanf("%s", &filename);
	readPoint(filename, &xarr, &yarr, &n);

	idx = (int*)malloc(n * sizeof(int));
	
	doJavis(idx, xarr, yarr, n);

	printQ(idx, xarr, yarr);

	free(xarr);
	free(yarr);
	free(idx);

	return 0;
}

void readPoint(char* filename, int** point_x, int** point_y, int* number_of_point) {
	int x, y, *xarr, *yarr, n, i;

	FILE* file = fopen(filename, "r");
	fscanf(file, "%d", &n);

	xarr = (int*)malloc(n * sizeof(int));
	yarr = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		fscanf(file, "%d%d", &xarr[i], &yarr[i]);
	}

	fclose(file);

	*point_x = xarr;
	*point_y = yarr;
	*number_of_point = n;
}

void doJavis(int* q_i, int* point_x, int* point_y, int number_of_point) {
	int i = 0, im1, j, q0x, curr = 0, minidx;
	double theta, mintheta;

	int minx = 0x7fffffff;
	for (i = 0; i < number_of_point; i++) {
		if (minx >= point_x[i]) {
			minx = point_x[i];
			minidx = i;
		}
	}

	q_i[0] = minidx;
	q0x = point_x[minidx];

	i = 0;

	while (1) {
		mintheta = 2 * M_PI;
		if (i == 0) {
			for (j = 1; j < number_of_point; j++) {
				theta =
					atan2(0 - point_y[q_i[i]], q0x - point_x[q_i[i]]) -
					atan2(point_y[j] - point_y[q_i[i]], point_x[j] - point_x[q_i[i]]);
				if (theta < 0) theta += 2 * M_PI;

				if (mintheta >= theta) {
					mintheta = theta;
					minidx = j;
				}
			}

			q_i[i + 1] = minidx;
		}
		else {
			for (j = 0; j < number_of_point; j++) if (j != q_i[i] && j != q_i[i - 1]){
				theta =
					atan2(point_y[q_i[i - 1]] - point_y[q_i[i]], point_x[q_i[i - 1]] - point_x[q_i[i]]) -
					atan2(point_y[j] - point_y[q_i[i]], point_x[j] - point_x[q_i[i]]);
				if (theta < 0) theta += 2 * M_PI;

				if (mintheta >= theta) {
					mintheta = theta;
					minidx = j;
				}
			}

			if (minidx == q_i[0]) {
				q_i[i + 1] = q_i[0];
				break;
			}
			else {
				q_i[i + 1] = minidx;
			}			
		}

		i++;
	}
}

void printQ(int* idx, int* xarr, int* yarr) {
	int i = 0;

	while (1) {
		if (i == 0) {
			printf("%d %d\n", xarr[idx[0]], yarr[idx[0]]);
		}
		else {
			if (idx[i] == idx[0]) break;
			printf("%d %d\n", xarr[idx[i]], yarr[idx[i]]);
		}
		i++;
	}

	i++;
}