#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char command[8];
    struct node* next;
} QUEUE_NODE;

typedef struct {
    QUEUE_NODE* front;
    int count;
    QUEUE_NODE* rear;
} QUEUE;

void FreeQueue(QUEUE*);
int CheckCommand(char* command);
void EnqueueCommand(QUEUE*, char*);
int DequeuePrint(QUEUE*, char*);

int main() {
    QUEUE* q = (QUEUE*)malloc(sizeof(QUEUE));
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;

    char op[1000], temp[1000];

    while (1) {
        printf(">>");
        scanf("%s", op);

        if (CheckCommand(op)) {
            if (!strcmp("h", op) || !strcmp("history", op)) {
                while (DequeuePrint(q, temp)) {
                    printf("%s\n", temp);
                }
            }
            else if (!strcmp("q", op) || !strcmp("quit", op)) {
                break;
            }
            else {
                printf("[Valid] %s\n", op);
                EnqueueCommand(q, op);
            }
        }
        else {
            printf("[Invalid]\n");
        }
    }

    FreeQueue(q);

    return 0;
}

int CheckCommand(char* command) {
    char valid_op[][8] = {
        "help", "dir", "mkdir", "cd", "history", "h", "quit", "q"
    };

    for (int i = 0; i < 8; i++) {
        if (!strcmp(command, valid_op[i])) return 1;
    }

    return 0;
}

void FreeQueue(QUEUE* queue) {
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

void EnqueueCommand(QUEUE * pQueue, char* dataIn) {
    QUEUE_NODE* newNode = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
    strcpy(newNode->command, dataIn);
    newNode->next = NULL;

    if (pQueue->count == 0) {
        pQueue->front = newNode;
        pQueue->rear = newNode;
    }
    else {
        pQueue->rear->next = newNode;
        pQueue->rear = newNode;
    }

    pQueue->count++;
}

int DequeuePrint(QUEUE* pQueue, char* dataOut) {
    if (pQueue->count == 0) return 0;
    if (pQueue->count == 1) pQueue->rear == NULL;

    QUEUE_NODE* curr = pQueue->front;

    strcpy(dataOut, curr->command);
    pQueue->front = curr->next;
    free(curr);
    pQueue->count--;

    return 1;
}