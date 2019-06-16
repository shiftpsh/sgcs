#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TERMS 100
typedef struct treeNode* treePtr;
struct treeNode {
    treePtr lchild;
    int data;
    treePtr rchild;
};

void inorder(treePtr);
void preorder(treePtr);
void insert(treePtr*, int);
treePtr modifiedSearch(treePtr, int);

void inorder(treePtr tree) {
    if (tree->lchild != NULL) {
        inorder(tree->lchild);
    }
    printf("%d ", tree->data);
    if (tree->rchild != NULL) {
        inorder(tree->rchild);
    }
};

void preorder(treePtr tree) {
    printf("%d ", tree->data);
    if (tree->lchild != NULL) {
        preorder(tree->lchild);
    }
    if (tree->rchild != NULL) {
        preorder(tree->rchild);
    }
};

treePtr modifiedSearch(treePtr tree, int key) {
    treePtr last = NULL;
    while (tree) {
        if (key == tree->data) return NULL;
        if (key < tree->data) {
            last = tree;
            tree = tree->lchild;
        } else {
            last = tree;
            tree = tree->rchild;
        }
    }
    return last;
}

void insert(treePtr *node, int num) {
    treePtr ptr, temp = modifiedSearch(*node, num);
    if (temp || !(*node)) {
        ptr = (treePtr) malloc(sizeof(struct treeNode));
        if (ptr == NULL) {
            fprintf(stderr, "The memory is full");
            exit(1);
        }
        ptr->data = num;
        ptr->lchild = ptr->rchild = NULL;
        if (*node) {
            if (num < temp->data) {
                temp->lchild = ptr;
            } else {
                temp->rchild = ptr;
            }
        }
        else *node = ptr;
    }
}

int main() {
    int n = 0, a[MAX_TERMS];
    FILE* fp = fopen("input.txt", "r");

    treePtr tree = NULL;
    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &a[i]);
        insert(&tree, a[i]);
    }

    inorder(tree);
    printf("\n");
    preorder(tree);
    printf("\n");

    fclose(fp);
    return 0;
}