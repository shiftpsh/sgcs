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
    char data;
    sptr link;
} STACK_NODE;

void free_stack(STACK*);
void Push(STACK*, char);
int Pop(STACK*);
char Peek(STACK* stack);

enum Opertation {
    EXIT_PROGRAM, PUSH, POP, PRINT_ALL
};

int main() {
    char str[100];
    STACK stack;
    stack.count = 0;
    stack.link = NULL;

    int flag = 1;

    gets(str, 100);

    for (int i = 0;; i++) {
        if (str[i] == '\0') break;

        if (str[i] == '(') {
            Push(&stack, '(');
        }
        else if (str[i] == '[') {
            Push(&stack, '[');
        }
        else if (str[i] == '{') {
            Push(&stack, '{');
        }
        else if (str[i] == ')') {
            char x = Peek(&stack);
            if (x == '(') {
                Pop(&stack);
            }
            else {
                flag = 0;
                break;
            }
        }
        else if (str[i] == ']') {
            char x = Peek(&stack);
            if (x == '[') {
                Pop(&stack);
            }
            else {
                flag = 0;
                break;
            }
        }
        else if (str[i] == '}') {
            char x = Peek(&stack);
            if (x == '{') {
                Pop(&stack);
            }
            else {
                flag = 0;
                break;
            }
        }
    }

    if (stack.count) flag = 0;

    if (flag) {
        printf("Matched Parentheses!\n");
    }
    else {
        printf("Unmatched Parentheses!");
    }

    free_stack(&stack);

    return 0;
}

void free_stack(STACK* stack) {
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

void Push(STACK* stack, char c) {
    sptr newNode = (sptr)malloc(sizeof(STACK_NODE));
    newNode->data = c;
    newNode->link = stack->link;
    stack->link = newNode;
    stack->count++;
}

int Pop(STACK* stack) {
    if (stack->count == 0) return 0;

    sptr temp = stack->link;
    stack->link = stack->link->link;
    free(temp);
    stack->count--;
    return 1;
}

char Peek(STACK* stack) {
    if (stack->count == 0) return -1;
    return stack->link->data;
}