#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
} QUEUE_NODE;

typedef struct {
    QUEUE_NODE* front;
    int count;
    QUEUE_NODE* rear;
} QUEUE;

void Exit(QUEUE*);
void Enqueue(QUEUE*);
void PrintAll(QUEUE);

int main() {
    QUEUE* q = (QUEUE*) malloc(sizeof(QUEUE));
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;

    int op;

    printf("****** Menu ******\n");
    printf("* 0 : Exit       *\n");
    printf("* 1 : Enqueue    *\n");
    printf("* 2 : -------    *\n");
    printf("* 3 : Print All  *\n");
    printf("******************\n");

    int exitFlag = 0;

    while (!exitFlag) {
        printf("Select > ");
        scanf("%d", &op);

        switch (op) {
        case 0:
            exitFlag = 1;
            break;
        case 1:
            Enqueue(q);
            break;
        case 3:
            PrintAll(*q);
            break;
        default:
            break;
        }        
    }

    Exit(q);

    return 0;
}

void Exit(QUEUE* queue) {
    if (queue->count != 0) {
        QUEUE_NODE* prev, *curr = queue->front;

        while (curr != NULL) {
            prev = curr;
            curr = curr->next;
            free(prev);
        }
    }

    free(queue);
}

void Enqueue(QUEUE * queue) {
    int data;
    printf("Input Data > ");
    scanf("%d", &data);

    QUEUE_NODE* newNode = (QUEUE_NODE*) malloc(sizeof(QUEUE_NODE));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->count == 0) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    queue->count++;
}

void PrintAll(QUEUE queue) {
    if (queue.count == 0) {
        printf("Queue is empty!\n");
        return;
    }

    QUEUE_NODE* curr = queue.front;

    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    printf("\n");
}