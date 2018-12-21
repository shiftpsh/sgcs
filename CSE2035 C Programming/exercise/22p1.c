#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node* sptr;

typedef struct {
    int count;
    sptr link;
} STACK;

typedef struct node {
    int data;
    sptr link;
} STACK_NODE;

void EXIT(STACK*);
void Push(STACK*);
void Pop(STACK*);
void PrintAll(STACK*);

enum Opertation {
    EXIT_PROGRAM, PUSH, POP, PRINT_ALL
};

int main() {
    int op;
    STACK stack;

    stack.count = 0;
    stack.link = NULL;

    printf("****** Menu ******\n");
    printf("* 0 : Exit       *\n");
    printf("* 1 : Push       *\n");
    printf("* 2 : Pop        *\n");
    printf("* 3 : Print All  *\n");
    printf("******************\n");

    while (1) {
        printf("Select > ");
        scanf("%d", &op);

        switch(op) {
        case EXIT_PROGRAM:
            EXIT(&stack);
            return 0;
        case PUSH:
            Push(&stack);
            break;
        case POP:
            Pop(&stack);
            break;
        case PRINT_ALL:
            PrintAll(&stack);
            break;
        }
    }

    return 0;
}

void EXIT(STACK* stack) {
    sptr curr = stack->link;
    sptr prev;

    while (curr != NULL) {
        prev = curr;

        if (curr->link == NULL) {
            free(curr);
            break;
        }
        curr = curr->link;

        free(prev);
    }
}

void Push(STACK* stack) {
    int i;
    printf("Input Data > ");
    scanf("%d", &i);

    sptr newNode = (sptr)malloc(sizeof(STACK_NODE));
    newNode->data = i;
    newNode->link = stack->link;
    stack->link = newNode;
    stack->count++;
}

void Pop(STACK* stack) {
    if (stack->count == 0) {
        printf("Stack is empty!\n");
    }
    else {
        printf("Pop %d\n", stack->link->data);

        sptr temp = stack->link;
        stack->link = stack->link->link;
        free(temp);
        stack->count--;
    }
}

void PrintAll(STACK* stack) {
    if (stack->count == 0) {
        printf("Stack is empty!\n");
    }
    else {
        sptr curr = stack->link;
        int* temp_arr = (int*)malloc(sizeof(int) * stack->count);

        for (int i = 0; i < stack->count; i++) {
            temp_arr[stack->count - i - 1] = curr->data;
            curr = curr->link;
        }

        for (int i = 0; i < stack->count; i++) {
            printf("%d ", temp_arr[i]);
        }

        free(temp_arr);
        printf("\n");
        printf("Stack Level : %d\n", stack->count);
    }
}