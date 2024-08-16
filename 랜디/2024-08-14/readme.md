### [A 창영마을 B2](https://www.acmicpc.net/problem/3028)

### [B 장신구 명장 임스 S5](https://www.acmicpc.net/problem/25496)

### [C 알고리즘 수업 - 너비 우선 탐색 S2](https://www.acmicpc.net/problem/24444)

### [D 컴백홈 S1](https://www.acmicpc.net/problem/1189)

### [E 배수 공사 G5](https://www.acmicpc.net/problem/15817)

### [F 소수를 분수로 G5](https://www.acmicpc.net/problem/11082)

### [G PPAP G4](https://www.acmicpc.net/problem/16120)

### [H 철도 공사 G4](https://www.acmicpc.net/problem/23309)

# 학습노트

+ 학습한 내용
  - A : swap, 구현
  - B : 그리디, 정렬
  - C : BFS, 정렬
  - D : 백트래킹, 그래프 탐색
  - E : DP, Knapsack
  - F : 문자열, 파싱, 많조분, 유클리드 호제법
  - G : 그리디, 스택(덱)
  - H : 시뮬레이션, 연결리스트(구현해야됨)

+ 총평
  - E는 naive한 DP였다.
  - H는 원형 연결리스트 풀이가 정해인 것 같은데 배열로 풀었다.

###  

## D 컴백홈
<details>
<summary> 접기/펼치기 </summary>

```cpp
//크기 제한부터 딱 보니 백트래킹이었다.
//그냥 3차원 vis 배열로도 풀리긴 할 것 같았는데, 오기가 생겨서 백트래킹으로 해결했다.

//K-1을 K로 쓰고, 시작 위치를 C-1, 0으로 실수해서 두 번 틀렸다.

#include <bits/stdc++.h>
using namespace std;

int Ans = 0;
int R,C,K;
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int vis[10][10];
char board[10][10];

void DFS(int y, int x, int depth){
    if(y==0 && x==C-1){
        if(depth == K-1) Ans++;
        return;
    }
    if(depth == K-1){
        if(y==0 && x==C-1) Ans++;
        return;
    }
    for(int dir=0; dir<4; dir++){
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny<0 || nx<0 || ny>=R || nx>=C) continue;
        if(vis[ny][nx] || board[ny][nx]=='T') continue;
        vis[ny][nx] = true;
        DFS(ny, nx, depth+1);
        vis[ny][nx] = false;
    }
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    cin>>R>>C>>K;
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            cin>>board[i][j];
    vis[R-1][0] = true;
    DFS(R-1,0,0);
    cout<<Ans;
    return 0;
}

```
</details>

- 백트래킹
