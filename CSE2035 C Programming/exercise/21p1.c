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

void Insert(NODE**, int);

void Delete(NODE**);

void PrintAll(NODE*);


int main() {
    int A[10] = { 3, 9, 8, 2, 5, 10, 7, 1, 4, 6 };

    nptr head = NULL;

    for (int i = 0; i < 10; i++) {
        Insert(&head, A[i]);
    }
    PrintAll(head);

    for (int i = 0; i < 10; i++) {
        Delete(&head);
        PrintAll(head);
    }

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

void Delete(nptr* head) {
    nptr temp = *head;
    *head = (*head)->link;
    free(temp);
}

void PrintAll(nptr ptr) {
    nptr curr = ptr;
    int count = 0;

    while (1) {
        if (curr == NULL) break;
        printf("%d ", curr->data);
        curr = curr->link;
        count++;
    }

    if (!count) printf("Empty");

    printf("\n");
}