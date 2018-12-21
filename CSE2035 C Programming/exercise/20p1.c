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

void Insert(nptr*, int, int);
void PrintAll(nptr);

int main() {
    int A[10] = { 3, 9, 8, 2, 5, 10, 7, 1, 4, 6 };

    nptr head = NULL;

    Insert(&head, A[0], 0);
    PrintAll(head);

    Insert(&head, A[1], 0);
    PrintAll(head);

    Insert(&head, A[2], 1);
    PrintAll(head);

    Insert(&head, A[3], 2);
    PrintAll(head);

    Insert(&head, A[4], 0);
    PrintAll(head);

    Insert(&head, A[5], 1);
    PrintAll(head);

    Insert(&head, A[6], 10);
    PrintAll(head);

    Insert(&head, A[7], 4);
    PrintAll(head);

    Insert(&head, A[8], -1);
    PrintAll(head);

    Insert(&head, A[9], 3);
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


void Insert(nptr* head, int value, int index) {
    nptr curr = *head;
    int i;

    if (index == -1) index = 0x7fffffff;

    nptr newPtr = (nptr)malloc(sizeof(NODE));
    newPtr->data = value;
    newPtr->link = NULL;

    if (curr == NULL) {
        *head = newPtr;
        return;
    }

    if (index == 0) {
        newPtr->link = *head;
        *head = newPtr;
    }
    else {
        for (i = 0; i < index - 1; i++) {
            if (curr->link == NULL) break;
            curr = curr->link;
        }

        newPtr->link = curr->link;
        curr->link = newPtr;
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