#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node* nptr;

typedef struct node {
    int data;
    nptr *link;
} NODE;

void Insert(nptr*, int);
void Sort(nptr*);
void PrintAll(nptr);

int main() {
    int A[10] = { 3, 9, 8, 2, 5, 10, 7, 1, 4, 6 };

    nptr head = NULL;

    for (int i = 0; i < 10; i++) {
        Insert(&head, A[i]);
    }

    PrintAll(head);

    Sort(&head);
    PrintAll(head);

    nptr curr = head->link, prev = head;
    while (1) {
        if (prev == NULL) break;
        free(prev);
        prev = curr;
        if (curr == NULL) break;
        curr = curr->link;
    }
    free(curr);

    return 0;
}


void Insert(nptr* head, int value) {
    nptr curr = *head;
    int i;

    nptr newPtr = (nptr)malloc(sizeof(NODE));
    newPtr->data = value;
    newPtr->link = NULL;

    if (curr == NULL) {
        *head = newPtr;
        return;
    }

    while (1) {
        if (curr->link == NULL) break;
        curr = curr->link;
    }

    curr->link = newPtr;
}

void Sort(nptr* head) {
    nptr curr = *head;
    nptr ref = curr;
    int i, j, size = 0;

    while (1) {
        if (curr == NULL) break;
        size++;
        curr = curr->link;
    }

    curr = *head;

    for (i = size - 1; i >= 0; i--) {
        for (j = 0; j <= i; j++) {
            if (ref->link == NULL) break;

            if ((ref->data) > ((nptr) ref->link)->data) {
                int temp = ref->data;
                ref->data = ((nptr)ref->link)->data;
                ((nptr)ref->link)->data = temp;
            }
            ref = ref->link;
        }
        ref = curr;
    }
}

void PrintAll(nptr ptr) {
    nptr curr = ptr;

    while (1) {
        if (curr == NULL) break;
        printf("%d ", curr->data);
        curr = curr->link;
    }

    printf("\n");
}