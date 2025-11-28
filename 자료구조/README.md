## 학습 정리

#### 1. 배열과 리스트 그리고 벡터
<img src="https://github.com/user-attachments/assets/5de686cf-cb42-40ec-8177-7a0b915c3d4f" width="500">

```
정수형 또는 실수형 자료형에 담을 수 없을 정도로 긴 숫자가 입력으로 주어질 경우,
문자열로 입력을 받고 문자를 순서대로 읽으면서 숫자로 변환하여 사용한다. 
```

--- 
#### 2. 구간 합
<img src="https://github.com/user-attachments/assets/7cfa4ce2-4a1d-4f50-a334-9b83ec15c7e7" width="500">

```
구간 합(Prefix Sum) 알고리즘은 배열의 특정 구간에 대한 합을 매우 빠르게 구하기 위해 사용하는 알고리즘이다.
시간 복잡도를 O(1)으로 단축할 수 있다.

먼저 수열의 합 S는 다음과 같다.

S[0] = A[0] (i = 0)
S[i] = A[1] + A[2] + ... + A[i] (1 <= i)

따라서 구간 L이상 R이하 범위의 누적 합은 다음과 같다.

A[L] + ... + A[R] = S[R] - S[L - 1]
```

```cpp

vector<int> A(N + 1), S(N + 1);

// 주의! 누적 합 배열 pSum은 인덱스 1부터 시작한다.
for (int i = 1; i <= N; i++) {
    S[i] = S[i - 1] + A[i];
}
```
---
#### 3. 투 포인터
<img src="https://github.com/user-attachments/assets/a4a1f006-ca4c-4c18-9f6f-d8e602110189" width="500">


```
투 포인터(Two Pointers) 알고리즘은 리스트(배열)에 순차적으로 접근해야 할 때, 두 개의 점(포인터)의 위치를 기록하면서 처리하는 기법이다.
두 개의 포인터 left와 right는 현재 처리 중인 위치를 나타낸다.

left: 구간의 시작 지점을 가리키는 포인터
right: 구간의 끝 지점을 가리키는 포인터

이 두 포인터가 다음과 같은 조건에 따라 움직인다.

1. 앞에서 시작해 같이 이동하는 경우
- 연속된 부분 수열의 합이 M이 되는 경우의 수를 구합니다.
- 현재 구간의 합이 M보다 작으면, right를 오른쪽으로 1칸 이동하고 합을 키웁니다.
- 현재 구간의 합이 M보다 크거나 같으면, left를 오른쪽으로 1칸 이동하고 합을 줄입니다.
- 합이 M이면 경우의 수를 카운팅하고, 두 포인터가 양끝에 도달할 경우 종료합니다.

2. 양 끝에서 시작해 만나는 경우(주의! 반드시 정렬된 상태로 시작)
- 두 수의 합이 M이 되는 쌍을 구합니다.
- left는 맨 앞, right는 맨 뒤에 위치합니다.
- 두 수의 합이 M보다 작으면, 값을 키우기 위해 left를 오른쪽으로 이동합니다.
- 두 수의 합이 M보다 크면, 값을 줄이기 위해 right를 왼쪽으로 이동합니다.
- left가 right를 넘어갈 경우 종료합니다.
```

---
#### 4. 슬라이딩 윈도우
<img src="https://github.com/user-attachments/assets/9717bc59-2104-4d05-8d08-d97d4be7de94" width="500">

```
슬라이딩 윈도우(sliding winodw)는 연속된 구간을 유지한 채로, 윈도우를 한 칸씩 이동하며 계산을 갱신하는 알고리즘이다.
항상 고정된 크기의 구간을 처리한다는 점에서 투 포인터 알고리즘과 차이가 있다.

ex) K개 연속 원소의 최대 합을 구하시오.
```

```cpp
// 1칸씩 윈도우를 이동
for (int i = K; i < N; i++) {
    sum += A[i];       // 오른쪽 추가
    sum -= A[i - K];   // 왼쪽 제거
    answer = max(answer, sum);
}
```

---
#### 5. 스택과 큐
<img src="https://github.com/user-attachments/assets/33dd8e97-72b1-447c-8aed-e71832eec8fe" width="500">

```
스택(stack)은 LIFO(Last In, First Out) 구조로, 마지막에 들어온 요소가 가장 먼저 빠져나가는 알고리즘입니다.
모든 연산이 상수 시간 O(1)로 매우 빠르게 동작합니다.
주로 쌍, 재귀, DFS, 역순 등 문제에서 사용합니다.

큐는(queue)는 FIFO(First In, First Out) 구조로, 먼저 들어온 요소가 먼저 빠져나가는 알고리즘입니다.
모든 연산이 상수 시간 O(1)로 매우 빠르게 동작합니다.
주로 대기열, BFS, 프로세스 등 문제에서 사용합니다.
```

<img src="https://github.com/user-attachments/assets/7b561854-9b47-4790-a839-a3f8e0caa983" width="500">

```
!참고
우선순위 큐(priority queue)는 최대 힙(Max Heap) 또는 최소 힙(Min Heap) 구조로 우선순위가 높거나 낮은 값이 먼저 나오는 방식입니다.
완전 이진 트리의 구조로 모든 노드가 왼쪽부터 차례대로 채워지는 성질을 가집니다.
원소의 삽입 및 삭제 연산이 O(log N)의 시간 복잡도를 가집니다.
원소의 조회는 루트 노드이므로 O(1)의 시간 복잡도를 가집니다.
주로 가장 큰 값 또는 가장 작은 값을 반복적으로 꺼내야 할 때, 실시간으로 달라지는 우선순위를 관리할 때 사용합니다.
```

---
#### 이미지 출처
https://nitishhsinghhh.medium.com/mastering-vectors-in-c-41029caae196

https://medium.com/@tasmiamonzoor/mastering-sliding-window-problems-a-simple-yet-powerful-technique-993483d8f103

