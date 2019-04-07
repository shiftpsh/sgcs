#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int *arr, int n) {
    for (int pivot = 1; pivot < n; pivot++) {
        int temp = arr[pivot];
        int idx = pivot - 1;

        while ((idx >= 0) && (arr[idx] > temp)) {
            arr[idx + 1] = arr[idx];
            idx--;
        }

        arr[idx + 1] = temp;
    }
}

void lab1() {
    char filename[20] = "lab1.data";
    FILE *fp = fopen(filename, "r");
    int *arr = (int *) malloc(sizeof(int) * 0);
    int x, n = 0;

    while (fscanf(fp, "%d", &x) == 1) {
        n++;
        realloc(arr, sizeof(int) * n);
        arr[n - 1] = x;
    }

    printf("Input:  ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertion_sort(arr, n);

    printf("Output: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    fclose(fp);
    free(arr);
}

void sort_test(int n) {
    int *arr = malloc(sizeof(int) * n);
    int rep = 100000 / (n + 1);
    double elapsed = 0;

    for (int t = 0; t < rep; t++) {
        for (int i = 0; i < n; i++) {
            arr[i] = (n - i);
        }

        clock_t start = clock();
        insertion_sort(arr, n);
        elapsed += (double) (clock() - start);
    }

    free(arr);
    elapsed /= CLOCKS_PER_SEC;
    printf("%4d %12d %12.6lf\n", n, rep, elapsed);
}

void lab2() {
    printf("   n  repetitions         time\n");

    for (int i = 0; i <= 100; i += 10) {
        sort_test(i);
    }
}

int main() {
    lab1();
    lab2();

    return 0;
}