# Week 8

- 입력: [input.txt](input.txt)
- [정답 코드](main.c)

## 문제
입력파일로 주어진 `n`개의 양의 정수들을 읽어 binary search tree를 구성하라.

### 예제 입력
입력 파일의 첫째 줄에는 읽어야 할 정수들의 개수 `n`이 주어지고 그 다음 `n`줄에 양수인 정수가 한 줄에 하나씩 주어진다.

```
10
3
9
8
2
5
10
7
1
4
6
```

### 템플릿
```c
#define MAX_TERMS 100
typedef struct treeNode* treePtr;
typedef struct treeNode {
    treePtr lchild;
    int data;
    treePtr rchild;
};
void inorder (treePtr);
void preorder(treePtr);
void insert(treePtr*, int);
treePtr modifiedSearch(treePtr, int);
void main() {
    int i, n, A[MAX_TERMS];
    treePtr tree = NULL;
    // 파일 오픈한다.
    // 파일을 읽어 정수의 개수는 n 에, 삽입할 정수들은 A 에 저장한다.
    // 순서대로 binary search tree 에 삽입한다.
    for (i=0; i<n; i++)
    insert(&tree, A[i]);
    //구성된 binary search tree 를 inorder 와 preorder 로 출력하여
    //올바르게 트리가 생성되었는지 확인한다.
}
```