#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct _Node {
	char c;
	struct _Node *link;
} Node;

Node *head = NULL, *tail = NULL;

void InsertNodeAtFront(char a);
void InsertNodeAtBack(char b);
void PrintList();
void FreeList();

int main() {	
	InsertNodeAtFront('p');
	InsertNodeAtFront('p');
	InsertNodeAtFront('a');
	InsertNodeAtBack('l');
	InsertNodeAtBack('e');
	PrintList();

	FreeList();

	return 0;
}

void InsertNodeAtFront(char a) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->c = a;
	newNode->link = NULL;

	if (head == NULL) {
		head = newNode;
		tail = head;
	}
	else {
		newNode->link = head;
		head = newNode;
	}
}

void InsertNodeAtBack(char b) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->c = b;
	newNode->link = NULL;

	if (head == NULL) {
		head = newNode;
		tail = head;
	}
	else {
		tail->link = newNode;
		tail = tail->link;
	}
}

void PrintList() {
	Node *curr = head;

	while (1) {
		printf("%c", curr->c);
		if (curr->link == NULL) break;
		curr = curr->link;
	}

	printf("\n");
}

void FreeList() {
	Node *prev = head;
	Node *curr = prev->link;

	while (1) {
		free(prev);
		prev = curr;
		if (curr->link == NULL) break;
		curr = curr->link;
	}

	free(curr);
}