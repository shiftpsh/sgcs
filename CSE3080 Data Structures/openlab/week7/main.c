#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct threadedTree *threadedPointer;
typedef struct threadedTree {
    short int leftThread;
    threadedPointer leftChild;
    char data;
    threadedPointer rightChild;
    short int rightThread;
} threadedTree;

threadedPointer insucc(threadedPointer tree);

void tinorder(threadedPointer tree);

void insertRight(threadedPointer s, threadedPointer r);

void insertLeft(threadedPointer s, threadedPointer l);

threadedPointer getNewNode(char data);

threadedPointer insucc(threadedPointer tree) {
    threadedPointer temp;
    temp = tree->rightChild;
    if (!tree->rightThread) {
        while (!temp->leftThread) {
            temp = temp->leftChild;
        }
    }
    return temp;
}

void tinorder(threadedPointer tree) {
    threadedPointer temp = tree;
    while (1) {
        temp = insucc(temp);
        if (temp == tree) break;
        printf("%3c", temp->data);
    }
}

void insertRight(threadedPointer parent,
                 threadedPointer child) {
    threadedPointer temp;
    child->rightChild = parent->rightChild;
    child->rightThread = parent->rightThread;
    child->leftChild = parent;
    child->leftThread = 1;
    parent->rightChild = child;
    parent->rightThread = 0;
    if (!child->rightThread) {
        temp = insucc(child);
        temp->leftChild = child;
    }
}

void insertLeft(threadedPointer parent,
                threadedPointer child) {
    threadedPointer temp;
    child->leftChild = parent->leftChild;
    child->leftThread = parent->leftThread;
    child->rightChild = parent;
    child->rightThread = 1;
    parent->leftChild = child;
    parent->leftThread = 0;
    if (!child->leftThread) {
        temp = insucc(child);
        temp->rightChild = child;
    }
}

threadedPointer getNewNode(char data) {
    threadedPointer newNode = (threadedPointer) malloc(sizeof(threadedTree));
    newNode->data = data;
    newNode->leftChild = newNode;
    newNode->rightChild = newNode;
    newNode->leftThread = 1;
    newNode->rightThread = 0;
    return newNode;
}

int main() {
    threadedPointer root = getNewNode('-');
    insertLeft(root, getNewNode('A'));
    insertLeft(root->leftChild, getNewNode('B'));
    insertLeft(root->leftChild->leftChild, getNewNode('D'));
    insertLeft(root->leftChild->leftChild->leftChild,
               getNewNode('H'));
    insertRight(root->leftChild->leftChild->leftChild,
                getNewNode('I'));
    insertRight(root->leftChild->leftChild, getNewNode('E'));
    insertRight(root->leftChild, getNewNode('C'));
    insertLeft(root->leftChild->rightChild, getNewNode('F'));
    insertRight(root->leftChild->rightChild, getNewNode('G'));
    tinorder(root);
    return 0;
}