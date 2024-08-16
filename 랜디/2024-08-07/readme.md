### [A 고려대는 사랑입니다 B5](https://www.acmicpc.net/problem/11942)

### [B 기념품 S3](https://www.acmicpc.net/problem/12873)

### [C 돌아온 똥게임 S3](https://www.acmicpc.net/problem/30701)

### [D 피보나치 인버스 S2](https://www.acmicpc.net/problem/10425)

### [E 팩토리얼 0의 개수 S1](https://www.acmicpc.net/problem/11687)

### [F 정복자 G4](https://www.acmicpc.net/problem/14950)

### [G 여우의 꿈 G4](https://www.acmicpc.net/problem/30190)

### [H 화살표 미로(Easy) G3](https://www.acmicpc.net/problem/20419)

# 학습노트

+ 학습한 내용
  - A : 기본 출력
  - B : 세그먼트 트리, Kth Query (정해는 deque)
  - C : 정렬, 그리디
  - D : 수학, 이분탐색(정해?), 파이썬(dict 980ms)
  - E : 이분탐색, 수학
  - F : MST
  - G : 재귀(하노이의 탑)
  - H : BFS

+ 총평
  - 파이썬 dictionary의 대단함을 알았다.
  - D 시간제한이 1초인데 980ms에 아슬아슬하게 dictionary 풀이가 통과한다.
  - B는 O(N) deque 풀이가 있는 것 같은데, 복습할 겸 세그먼트 트리로 풀었다.
  - G는 서울대 문제였는데 문제 퀄리티가 높아서 기억에 남는다.
  - H는 구현 난이도가 조금 있던 BFS문제였다.

###  

## G 여우의 꿈
<details>
<summary> 접기/펼치기 </summary>

```cpp
//2023년도 서울대 문제인데 어려웠다.
//하노이의 탑도 5개월 전에 처음 볼 땐 엄청 어려웠는데, 이제는 이해가 잘 된다.
//큰 수 연산이 필요할 땐 항상 POW2같이 전처리를 해서 쓰는게 좋다.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio cin.tie(NULL)->sync_with_stdio(false)

const ll MOD = 1e9 + 7;

vector<int> V; //아름다운 배열
vector<ll> POW2;
ll Ans = 0;

//하노이 탑 문제에서 N개의 원판을 옮기는데 드는 최소 비용은 2^N -1이다.

void func(int from, int to, int height){
    if(height==0){ //남은 원판이 0개이면
        cout<<Ans;
        return;
    }
    if(from != to){ //이동해야 하는 곳이 현재 위치가 아닌 경우
        //N-1개의 원판을 from과 to 이외의 장소로 옮기고, N번째 원판을 to에 위치시킨다.
        Ans += POW2[height-1]; //2^(height-1) -1 +1
        Ans %= MOD;
        func(6-from-to, V[height-1], height-1);
    }
    else{ //이동해야 하는 곳이 현재 위치인 경우
        //맨 아래 원판이 정위치에 있으므로 그 위 원판을 옮길 준비를 함
        func(from, V[height-1], height-1);
    }
}

int main(){
    fastio;
    int N, K; cin>>N>>K;
    V.resize(N+3);
    for(int i=1; i<=N; i++) cin>>V[i];

    POW2.resize(N+3);
    POW2[0] = 1;
    POW2[1] = 2;
    for(int i=2; i<=N; i++){
        POW2[i] = POW2[i-1] * 2;
        POW2[i] %= MOD;
    }

    //큰 원판부터 작은 원판 순서로 맞춰가는게 최적이므로 V[N]에서 V[1]로 내려가게 설계
    func(K, V[N], N);
    return 0;
}

```
</details>

- 하노이의 탑
- N개의 원판을 하노이의 탑 문제에서 옮기면 2^(N-1)회 이동
- 2의 제곱수 전처리
