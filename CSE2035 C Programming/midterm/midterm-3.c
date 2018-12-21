#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void readPolygon(char*, int**, int**, int*);
int isInsidePolygon(int, int, int*, int*, int);
int intersectionCount(int, int, int*, int*, int);

int main() {
	char filename[21];
	int x, y, *xarr, *yarr, n;

	scanf("%s", &filename);
	readPolygon(filename, &xarr, &yarr, &n);

	scanf("%d%d", &x, &y);

	if (isInsidePolygon(x, y, xarr, yarr, n)) {
		printf("in\n");
	}
	else {
		printf("out\n");
	}

	free(xarr);
	free(yarr);

	return 0;
}

void readPolygon(char* filename, int** polygon_x, int** polygon_y, int* number_of_point) {
	int x, y, *xarr, *yarr, n, i;

	FILE* file = fopen(filename, "r");
	fscanf(file, "%d", &n);

	xarr = (int*)malloc(n * sizeof(int));
	yarr = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		fscanf(file, "%d%d", &xarr[i], &yarr[i]);
	}

	fclose(file);

	*polygon_x = xarr;
	*polygon_y = yarr;
	*number_of_point = n;
}

int isInsidePolygon(int x, int y, int* polygon_x, int* polygon_y, int number_of_point) {
	int count = intersectionCount(x, y, polygon_x, polygon_y, number_of_point);

	return count % 2;
}

int intersectionCount(int x, int y, int* xarr, int* yarr, int n) {
	int i, j, ix, iy, jx, jy, mx, my, Mx, My, kp, kq, flag = 0, count = 0;
	int px = x, py = y, qx = x + 7, qy = y + 13; // random point; qx > x, qy > y
	double k, l, inx, iny;

	while (!flag) {
		flag = 1;
		count = 0;
		for (i = 0; i < n; i++) {
			j = (i + 1) % n;

			ix = xarr[i];
			iy = yarr[i];
			jx = xarr[j];
			jy = yarr[j];

			// Can't calculate intersections
			if (
				(px == ix && py == iy) ||
				(qx == jx && qy == jy)) {
				flag = 0;
				break;
			}

			if (ix > jx) {
				Mx = ix;
				mx = jx;
			}
			else {
				Mx = jx;
				mx = ix;
			}

			if (iy > jy) {
				My = iy;
				my = jy;
			}
			else {
				My = jy;
				my = iy;
			}

			// k = kp / kq
			kp = jy * ix - jx * iy + (jx - ix) * py - (jy - iy) * px;
			kq = (qx - px) * (jy - iy) - (qy - py) * (jx - ix);
			if (kq == 0) {
				flag = 0;
				break;
			}

			k = (double) kp / kq;

			inx = (double)px + k * (qx - px);
			iny = (double)py + k * (qy - py);

			if (
				((mx <= inx && inx <= Mx) || (my <= iny && iny <= My))
				&& ((x <= inx) && (y <= iny))) {
				count++;
			}
		}

		// If not found, try another point
		qx++;
		qy++;
	}

	return count;
}