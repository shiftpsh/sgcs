#include <stdio.h>
#include <stdlib.h>

typedef struct __triple__ {
    int x, y, val;
} triple;

typedef struct __sparse_matrix__ {
    int rows, columns, entry_count;
    triple *values;
} sparse_matrix;

void appendEntry(sparse_matrix *matrix, int x, int y, int value) {
    int i = matrix->entry_count;
    matrix->values = (triple*) realloc(matrix->values, (i + 1) * sizeof(triple));
    matrix->entry_count = i + 1;

    (matrix->values[i]).x = x;
    (matrix->values[i]).y = y;
    (matrix->values[i]).val = value;
}

void fastTranspose(sparse_matrix *matrix, sparse_matrix *result) {
    result->rows = matrix->columns;
    result->columns = matrix->rows;
    result->entry_count = 0;

    for (int y = 0; y < result->rows; y++) {
        for (int i = 0; i < matrix->entry_count; i++) {
            if (matrix->values[i].y == y) {
                appendEntry(result,
                            matrix->values[i].y,
                            matrix->values[i].x,
                            matrix->values[i].val);
            }
        }
    }
}

void freeSparseMatrix(sparse_matrix* matrix) {
    free(matrix->values);
}

void initSparseMatrix(sparse_matrix *matrix) {
    matrix->entry_count = 0;
    matrix->columns = 0;
    matrix->rows = 0;
    matrix->values = (triple*) malloc(0);
}

void readSparseMatrix(sparse_matrix *matrix, char *filename) {
    FILE* fp = fopen(filename, "r");

    int r, c, val;
    fscanf(fp, "%d%d", &r, &c);

    matrix->rows = r;
    matrix->columns = c;

    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            fscanf(fp, "%d", &val);
            if (val != 0) {
                appendEntry(matrix, x, y, val);
            }
        }
    }

    fclose(fp);
}

void printTriple(triple tri) {
    printf("%d %d %d\n", tri.x, tri.y, tri.val);
}

void printSparseMatrix(sparse_matrix matrix) {
    printf("%d %d %d\n", matrix.rows, matrix.columns, matrix.entry_count);
    for (int i = 0; i < matrix.entry_count; i++) {
        printTriple(matrix.values[i]);
    }
}

int main() {
    sparse_matrix matrix, transposed;

    initSparseMatrix(&matrix);
    initSparseMatrix(&transposed);

    readSparseMatrix(&matrix, "a[3].txt");
    fastTranspose(&matrix, &transposed);

    printSparseMatrix(transposed);

    freeSparseMatrix(&matrix);
    freeSparseMatrix(&transposed);

    return 0;
}