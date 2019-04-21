#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 100

typedef struct __term__ {
    float coeff;
    int degree;
} term;

typedef struct __poly__ {
    term *terms;
    int term_count;
} polynomial;

void initPoly(polynomial *poly) {
    poly->terms = (term *) malloc(0);
    poly->term_count = 0;
}

void freePoly(polynomial *poly) {
    free(poly->terms);
}

void addTerm(polynomial *poly, float coeff, int degree) {
    poly->terms = (term *) realloc(poly->terms, sizeof(term) * ++(poly->term_count));
    poly->terms[poly->term_count - 1].coeff = coeff;
    poly->terms[poly->term_count - 1].degree = degree;
}

void readPoly(polynomial *poly, char *filename) {
    FILE *fp = fopen(filename, "r");

    float coeff;
    int degree;
    while (fscanf(fp, "%f%d", &coeff, &degree) != EOF) {
        addTerm(poly, coeff, degree);
    }

    fclose(fp);
}

void printPoly(polynomial poly) {
    for (int i = 0; i < poly.term_count; i++) {
        printf("(%.1f, %d)", poly.terms[i].coeff, poly.terms[i].degree);
        if (i != poly.term_count - 1) {
            printf(", ");
        }
    }
}

void padd(polynomial A, polynomial B, polynomial *result) {
    initPoly(result);

    int a = 0, b = 0;

    while (a < A.term_count && b < B.term_count) {
        if (A.terms[a].degree > B.terms[b].degree) {
            addTerm(result, A.terms[a].coeff, A.terms[a].degree);
            a++;
        } else if (A.terms[a].degree < B.terms[b].degree) {
            addTerm(result, B.terms[b].coeff, B.terms[b].degree);
            b++;
        } else {
            addTerm(result, A.terms[a].coeff + B.terms[b].coeff, A.terms[a].degree);
            a++, b++;
        }
    }

    while (a < A.term_count) {
        addTerm(result, A.terms[a].coeff, A.terms[a].degree);
        a++;
    }

    while (b < B.term_count) {
        addTerm(result, B.terms[b].coeff, B.terms[b].degree);
        b++;
    }
}

int main() {
    polynomial A, B, C, ApB, ApBpC;
    initPoly(&A), initPoly(&B), initPoly(&C);
    readPoly(&A, "A.txt"), readPoly(&B, "B.txt"), readPoly(&C, "C.txt");

    padd(A, B, &ApB);
    padd(ApB, C, &ApBpC);

    printPoly(ApBpC);

    freePoly(&A), freePoly(&B), freePoly(&C), freePoly(&ApB), freePoly(&ApBpC);

    return 0;
}