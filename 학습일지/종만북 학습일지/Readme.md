# [BOJ 14939 불 끄기](https://www.acmicpc.net/problem/14939)
<details>
<summary> 접기/펼치기 </summary>
  
### 출처
- 2.3 문제 해결 전략 (37~38)

### 아이디어
- 순서가 없는 문제에 순서를 강제해서 문제를 풀 수 있다.
- 문제를 풀기 위해 다음의 두 가지를 깨달아야 한다.
  - 1. 어떤 순서로 버튼을 누르든 상관이 없다.
  - 2. 한 칸을 두 번 이상 누를 필요가 없다.

### 해결방법
- 제일 윗줄만 BruteForce로 누를지 말지 모든 경우의 수를 구한다.
- 나머지는 자기 자신의 바로 윗 칸이 켜져 있을 때만 누른다는 그리디한 전략으로 해결할 수 있다.

### 코드
<details>
<summary> 접기/펼치기 </summary>

```cpp
/*
첫째 줄만 누를지 말지를 결정한 후엔 
두번째줄부터 확인하면서 윗칸(지금이 아니면 바꿀 수 없는 칸)이 켜져 있으면 현재 칸을 눌러서 끈다.
비트마스킹으로 첫째 줄로 구할 수 있는 모든 경우의 수를 확인한다.
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL) -> sync_with_stdio(false);
#define ll long long

int ans = 0x7f7f7f7f;
string board_main[13];
string board[13];
int dy[] = {1,0,-1,0,0};
int dx[] = {0,1,0,-1,0};

void Click(int y, int x){
    for(int dir=0;dir<5;dir++){
        int ny = y+dy[dir];
        int nx = x+dx[dir];
        if(ny<0 || nx<0 || ny>=10 || nx>=10) continue;
        
        if(board[ny][nx]=='O') board[ny][nx] = '#';
        else board[ny][nx] = 'O';
    }
}

bool IsAllOff(){
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            if(board[i][j]=='O') return false;
    return true;
}

int main() {
    fastio;
    for(int i=0; i<10; i++) cin>>board_main[i];

    
    for(int i=0; i<(1<<10); i++){
        int temp = 0;

        for(int j=0;j<10;j++) board[j] = board_main[j];

        for(int j=0;j<10;j++){ //비트마스킹으로 생성된 순열에 따라 버튼을 누름 
            if((1<<j)&i) {Click(0,j); temp++;}
        }
        
        for(int ii=1;ii<10;ii++){
            for(int jj=0;jj<10;jj++){
                if(board[ii-1][jj]=='O'){
                    Click(ii,jj);
                    temp++;
                }
            }
        }

        if(IsAllOff()) ans = min(temp, ans);
    }

    if(ans == 0x7f7f7f7f) ans = -1;
    cout<<ans;
    return 0;
}
```
</details>
</details>

## ㅁㅁㅁㅁㅁ

# [BOJ 5015 ls](https://www.acmicpc.net/problem/5015)
<details>
<summary> 접기/펼치기 </summary>
  
### 출처
- 8. 동적 계획법 (218~255)

### 아이디어
- 완전탐색으로 패턴 매칭을 시도한다.
- 와일드카드 문자를 만나면 몇 번 문자까지 와일드카드 문자로 매칭시킬지 결정한다.
- 메모이제이션으로 계산했던 값들을 기억해놓는다.
- 몇 번 문자까지 와일드카드로 매칭시키지 고르는데 O(N)이므로 총 O(N^3)이 된다.

### 해결방법
- 와일드카드 문자를 만난다면 현재 문자를 대응시킬지, 대응시킬지 말지를 결정한다.
- 이렇게 하면 몇 번 문자까지 와일드카드로 매칭시킬지 고르지 않아도 되므로 O(N^2)에 동작하는 DP 코드를 짤 수 있다.

### 코드
<details>
<summary> 접기/펼치기 </summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N;
string P, W;
int dp[103][103];

bool solve(int p, int w){
    int &ret = dp[p][w];
    if(ret != -1) return ret;

    if(p<P.size() && w<W.size() && P[p]==W[w]) return ret = solve(p+1, w+1);

    if(p==P.size()) return ret = (w==W.size());

    if(P[p]=='*'){
        if((p<P.size() && solve(p+1, w) )|| (w<W.size() && solve(p, w+1))){
            return ret = 1;
        }
    }

    return ret = 0;
}

int main(){
    fastio;
    cin>>P>>N;
    for(int i=0; i<N; i++){
        cin>>W;
        memset(dp, -1, sizeof(dp));
        if(solve(0, 0)) cout<<W<<'\n';
    }
    return 0;
}
```
</details>
</details>
