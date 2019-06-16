#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
} element;

typedef struct stack *stackPointer;

typedef struct stack {
    element data;
    stackPointer link;
} stack;

typedef struct queue *queuePointer;

typedef struct queue {
    element data;
    queuePointer link;
} queue;

stackPointer top;

queuePointer front, rear;

void stack_push(int x) {
    stackPointer temp = top;
    stackPointer new = (stackPointer) malloc(sizeof(stackPointer));
    new->data.key = x;
    new->link = temp;

    top = new;
}

int stack_pop(int *x) {
    if (top == NULL) return 0;
    *x = top->data.key;
    stackPointer temp = top;
    top = top->link;
    free(temp);
    return 1;
}

void queue_push(int x) {
    queuePointer new = (queuePointer) malloc(sizeof(queuePointer));
    new->link = NULL;
    new->data.key = x;

    if (front == NULL) {
        front = new;
        rear = new;
    } else {
        rear->link = new;
        rear = new;
    }
}

int queue_pop(int *x) {
    if (front == NULL) return 0;
    *x = front->data.key;
    queuePointer temp = front;
    front = front->link;
    free(temp);
    return 1;
}

int main() {
    FILE* fp = fopen("input.txt", "r");

    int op, x;
    while (~fscanf(fp, "%d", &op)) {
        if (op == 0) {
            fscanf(fp, "%d", &x);
            stack_push(x);
            queue_push(x);
        } else {
            stack_pop(&x);
            queue_pop(&x);
        }
    }

    while (stack_pop(&x)) {
        printf("%d ", x);
    }
    printf("\n");
    while (queue_pop(&x)) {
        printf("%d ", x);
    }

    return 0;
}