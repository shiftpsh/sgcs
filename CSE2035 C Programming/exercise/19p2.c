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
void PrintAll(nptr);

int main() {
	int A[10] = { 3, 9, 8, 2, 5, 10, 7, 1, 4, 6 };

	nptr head = (NODE*)malloc(sizeof(NODE));
	head->link = NULL;

	nptr curr = head, prev;

	for (int i = 0; i < 10; i++) {
		Insert(&head, A[i]);
	}

	PrintAll(head);
	
	prev = head;
	curr = head->link;
	for (int i = 0; i < 10; i++) {
		free(prev);
		prev = curr;
		curr = curr->link;
	}
	free(curr);

	return 0;
}


void Insert(nptr* ptr, int value) {
	nptr newNode = (nptr) malloc(sizeof(NODE));
	newNode->data = value;
	newNode->link = *ptr;
	*ptr = newNode;
}

void PrintAll(nptr ptr) {
	nptr curr = ptr;

	while (1) {
		if (curr->link == NULL) break;
		printf("%d ", curr->data);
		curr = curr->link;
	}
}