#include <stdio.h>

void solve(FILE* in);

int main() {
	FILE *in;
	char filename[100];
	
	scanf("%s", &filename);

	in = fopen(filename, "r");
	if (in == NULL) {
		printf("Input error.\n");
		return 1;
	}

	solve(in);

	fclose(in);

	return 0;
}

void solve(FILE* in) {
	int arr[100][100];
	int n, m, i, j, x, y, change;
	int max = 0, total = 0;

	fscanf(in, "%d%d", &n, &m);

	for (i = 0; i < n; i++) for (j = 0; j < m; j++) {
		fscanf(in, "%d", &arr[i][j]);
		if (arr[i][j]) total++;
	}

	for (i = 0; i < n; i++) for (j = 0; j < m; j++) {
		change = 0;

		for (x = 0; x < n; x++) {
			if (arr[x][j] == 0) change++; else change--;
		}
		for (y = 0; y < m; y++) {
			if (arr[i][y] == 0) change++; else change--;
		}

		if (arr[i][j] == 0) change -= 2; else change += 2;

		if (max < change) max = change;
	}


	printf("%d\n", total + max);
	return;
}