#include <stdio.h>
#include <stdlib.h>

void read_box(char*, int***, int*, int*);
void print_box(int**, int, int);
int drop_box(int**, int, int);
void free_box(int***, int);

int main() {
	int row, col, **box;
	char filename[20];
	scanf("%s", filename);

	read_box(filename, &box, &row, &col);
	print_box(box, row, col);
	printf("%d\n", drop_box(box, row, col));

	free_box(&box, row);

	return 0;
}

void read_box(char* filename, int*** box, int* row, int* col) {
	int i, j;

	FILE* file = fopen(filename, "r");
        if (file == NULL) return;

        fscanf(file, "%d%d", row, col);

        *box = (int**) malloc(*row * sizeof(int*));
	for (i = 0; i < *row; i++) {
		(*box)[i] = (int*) malloc(*col * sizeof(int));
	}
	for (i = 0; i < *row; i++) for (j = 0; j < *col; j++) {
		fscanf(file, "%d", &((*box)[i][j]));
	}

	fclose(file);
}

void print_box(int **box, int row, int col) {
	int i, j;

	printf("%d %d\n", row, col);

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%d ", box[i][j]);
		}
		printf("\n");
	}
}

int drop_box(int **box, int row, int col) {
	int i = -1, j = 0, flag;

	while (i < row - 1) {
		flag = 0;

		while (j < col) {
			if (box[i + 1][j] == 0) {
				i++;
				flag = 1;
				break;
			} else {
				j++;
			}

			// printf("> %d %d\n", i, j);
		}

		if (!flag) {
			break;
		}
	}

	return j + 1;
}

void free_box(int ***box, int row) {
	int i;

	for (i = 0; i < row; i++) {
		free((*box)[i]);
	}

	free(*box);
}

