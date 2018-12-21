#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct _Node {
	int st_id;
	char st_name[25];
	struct _Node *link;
} Node;

Node *head = NULL, *curr = NULL;

void create_Node(int, char*);
void print_list(Node*);
void free_list(Node*);

int main() {
	FILE* input = fopen("input.csv", "r");
	int id;
	char name[30];

	char buffer[1000], *token;
	int n;

	fgets(buffer, 1000, input);
	n = atoi(buffer);

	while (fgets(buffer, 1000, input)) {
		token = strtok(buffer, ",");
		id = atoi(token);
		token = strtok(NULL, ",");
		token[strlen(token) - 1] = '\0';
		strcpy(name, token);

		create_Node(id, name);
	}
	
	fclose(input);

	print_list(head);
	free_list(head);

	return 0;
}

void create_Node(int id, char *name){
	Node *newNode = (Node*) malloc(sizeof(Node));
	strcpy(newNode->st_name, name);
	newNode->st_id = id;
	newNode->link = NULL;

	if (head == NULL) {
		head = newNode;
		curr = head;
	}
	else {
		curr->link = newNode;
		curr = curr->link;
	}
}

void print_list(Node* head) {
	Node* currloc = head;

	while (1) {
		printf("%d / %s\n", currloc->st_id, currloc->st_name);
		if (currloc->link == NULL) break;
		currloc = currloc->link;
	}
}

void free_list(Node* head) {
	Node* prev = head;
	Node* currloc = head->link;

	while (1) {
		free(prev);
		prev = currloc;
		if (currloc->link == NULL) break;
		currloc = currloc->link;
	}

	free(currloc);
}