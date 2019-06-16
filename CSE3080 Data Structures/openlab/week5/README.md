# Week 5

- 입력: [input.txt](input.txt)
- [정답 코드](main.c)

## 문제
linked stack과 linked queue를 각각 구현하고 테스트하는 프로그램을 작성하시오. 

### 예제 입력
각 행에는 하나 혹은 두 개의 정수로 이루어져 있다. 첫번째 숫자가 0 일 때에는 두번째 숫자를 삽입하고 첫번째 숫자가 1 일 때에는 삭제하는 연산을 의미한다.
최종 출력은 스택 혹은 큐에서 차례대로 pop 한 결과이다.

예를 들어 `input.txt`의 경우에는 `push(10)`, `push(40)`, `pop()`, `push(80)`, `push(70)`, `push(60)`, `pop()`, `push(50)`을 나타내고,
최종 출력은 스택의 경우 `50 70 80 10`, 큐의 경우 `80 70 60 50` 을 출력한다.

```
0 10
0 40
1
0 80
0 70
0 60
1
0 50
```

### 예제 출력
출력은 표준 출력으로 출력한다. 첫째줄에 스택의 pop 결과를 출력하고 둘째줄에 큐의 pop 결과를 출력한다.

```
50 70 80 10
80 70 60 50
```

### 템플릿
```c
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int key;
} element;
typedef struct stack* stackPointer;
typedef struct stack {
    element data;
    stackPointer link;
} stack;
typedef struct queue* queuePointer;
typedef struct queue {
    element data;
    queuePointer link;
} queue;
stackPointer top;
queuePointer front, rear;
```