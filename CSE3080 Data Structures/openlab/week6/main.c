#include <stdio.h>
#include <stdlib.h>

enum type {
    null_node, integer
};

typedef struct node *nodePointer;

typedef struct node {
    int data;
    enum type type;
    nodePointer llink, rlink;
} node;

nodePointer newList() {
    nodePointer newNode = (nodePointer) malloc(sizeof(node));
    newNode->type = null_node;
    newNode->rlink = newNode;
    newNode->llink = newNode;
    return newNode;
}

void push(nodePointer head, int x) {
    nodePointer newNode = (nodePointer) malloc(sizeof(node));
    newNode->data = x;
    newNode->type = integer;
    if (head->rlink == head) {
        newNode->llink = head;
        newNode->rlink = head;
        head->llink = newNode;
        head->rlink = newNode;
    } else {
        newNode->llink = head;
        newNode->rlink = head->rlink;
        head->rlink->llink = newNode;
        head->rlink = newNode;
    }
}

void delete(nodePointer node) {
    if (node->type == null_node) return;
    node->llink->rlink = node->rlink;
    node->rlink->llink = node->llink;
    free(node);
}

void append(nodePointer dest, nodePointer source) {
    do {
        source = source->llink;
        push(dest, source->data);
    } while (source->llink->type != null_node);
}

void deleteAll(nodePointer dest, nodePointer source) {
    dest = dest->llink;
    do {
        int flag = 0;
        do {
            source = source->llink;
            if (source->data == dest->data) flag = 1;
        } while (source->llink->type != null_node);
        dest = dest->llink;
        if (flag) delete(dest->rlink);
    } while (dest->type != null_node);
}

nodePointer initListFromFile(char* filename) {
    FILE* fp = fopen(filename, "r");
    nodePointer list = newList();
    int x;
    while (fscanf(fp, "%d", &x) != EOF) {
        push(list, x);
    }
    fclose(fp);
    return list;
}

void freeList(nodePointer node) {
    while (node->rlink->type != null_node) {
        delete(node->rlink);
    }
    free(node);
}

void print(nodePointer node) {
    do {
        node = node->llink;
        printf("%d ", node->data);
    } while (node->llink->type != null_node);
    printf("\n");
}

int main() {
    nodePointer A = initListFromFile("A.txt");
    nodePointer B = initListFromFile("B.txt");
    nodePointer C = initListFromFile("C.txt");

    append(A, B);
    print(A);
    deleteAll(A, C);
    print(A);

    freeList(A);
    freeList(B);
    freeList(C);

    return 0;
}