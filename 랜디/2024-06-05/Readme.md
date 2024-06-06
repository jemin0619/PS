### [A Результаты контеста B1](https://www.acmicpc.net/problem/28638)

### [B NBA 농구 S3](https://www.acmicpc.net/problem/2852)

### [C sqrt log sin S3](https://www.acmicpc.net/problem/4172)

### [D 상자넣기 S2](https://www.acmicpc.net/problem/1965)

### [E 체인 S1](https://www.acmicpc.net/problem/2785)

### [F 모노톤길 G5](https://www.acmicpc.net/problem/11067)

### [G 가희의 고구마 먹방 G5](https://www.acmicpc.net/problem/21772)

### [H 타일 채우기 3 G4](https://www.acmicpc.net/problem/14852)

# 학습노트

+ 학습한 내용
  - A : 구현
  - B : 구현
  - C : 수학, DP
  - D : DP(LIS)
  - E : 구현, 그리디
  - F : 구현, 자료구조(Set, Map)
  - G : 백트래킹, DFS
  - H : DP

+ 힙에 동적으로 메모리 할당시키기
  - [관련자료](https://stackoverflow.com/questions/38842681/segmentation-fault-chkstk-ms-c)
  - F를 풀면서 위와 같은 문제가 발생했었다.
  - mycompiler에서는 잘 실행되는데 vscode에서만 그래서 꼭 문제를 해결하고 싶었는데, 아래 방식과 같이 선언하면 해결할 수 있다.
  - 힙은 스택보다 메모리가 크기에 메모리 면에선 유리하다.
 
```cpp
vector<ll>* Ypos = new vector<ll>[100003];
delete[] Ypos;
```
