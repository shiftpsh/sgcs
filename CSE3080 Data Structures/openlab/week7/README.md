# Week 7

- 입력: 없음
- [정답 코드](main.c)

## 문제
책 [그림 5.23]에 있는 Threaded Binary Tree를 구성하고 inorder의 결과를 출력한다.
`main` 함수와 함수의 원형, 자료구조는 아래와 같고 수정할 수 없다.
노드를 왼쪽에 삽입하는 함수인 `insertLeft` 함수와 빈 노드를 반환하는 함수인 `getNewNode` 함수는 직접 구현해야 한다.

### 예제 입력
입력은 없다.

### 예제 출력
출력은 표준 출력으로 출력한다. 첫째줄에 inorder로 탐색한 결과를 출력한다.

```
H D I B E A F C G
```

### 템플릿
```c
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
threadedPointer getNewNode(char data) ;
int main() {
    /* image 5.23 */
    threadedPointer root = getNewNode('-');
    insertLeft(root, getNewNode('A'));
    insertLeft(root->leftChild, getNewNode('B'));
    insertLeft(root->leftChild->leftChild, getNewNode('D'));
    insertLeft(root->leftChild->leftChild->leftChild, getNewNode('H'));
    insertRight(root->leftChild->leftChild->leftChild, getNewNode('I'));
    insertRight(root->leftChild->leftChild, getNewNode('E'));
    insertRight(root->leftChild, getNewNode('C'));
    insertLeft(root->leftChild->rightChild, getNewNode('F'));
    insertRight(root->leftChild->rightChild, getNewNode('G'));
    tinorder(root);
    return 0;
}
```