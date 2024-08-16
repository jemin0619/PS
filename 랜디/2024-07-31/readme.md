### [A Toilet Seat B1](https://www.acmicpc.net/problem/11189)

### [B Bingo S5](https://www.acmicpc.net/problem/31678)

### [C Matrix Chain Multiplication S3](https://www.acmicpc.net/problem/6604)

### [D 순열 선물하기 S2](https://www.acmicpc.net/problem/30021)

### [E Enjoyable Entree S1](https://www.acmicpc.net/problem/26015)

### [F 불장난 G4](https://www.acmicpc.net/problem/14945)

### [G 두 개의 문 G4](https://www.acmicpc.net/problem/17453)

### [H1 Up and Down (Large) G3](https://www.acmicpc.net/problem/12237)

### [H2 DNA 발견 G4](https://www.acmicpc.net/problem/2806)

# 학습노트

+ 학습한 내용
  - A : 문자열, 구현
  - B : 구현, 시뮬레이션
  - C : 문자열, 파싱, 스택, 수학(행렬의 곱)
  - D : 애드훅, 해 구성하기
  - E : 수학, 구현
  - F : DP
  - G : bitset, Bruteforce
  - H1 : Greedy
  - H2 : DP

+ 총평
  - D는 재밌는 애드훅이여서 기억에 남는다.
  - E는 그냥 피보나치처럼 돌리다가 실수했다.
  - F는 3시간동안 바텀업으로 풀려고 시도했다가 실패하고 탑다운으로 해결했다.
  - G는 bitset(비트 집합)으로 상수커팅을 해서 시간복잡도를 줄여야 했는데, bitset이 처음이라 기억에 남는다.
  - 여기서 Map을 써서 시간초과가 났었는데 그냥 배열로 바꿔주니 무난하게 통과했다.
  - H1은 그리디 풀이가 잘 이해가 되지 않았다.
  - H2는 실수로 문제 언어 변경을 눌러서 보상을 안받은 H1이 날라가면서 생긴 문제이다.
  - DP를 풀땐 당장 테이블 구성이 생각나지 않으면 dp[i][..][...]... 는 i까지 보았을 때 ~~ 이런 식으로 세우면 편한 것 같다.

###  

## F 불장난
<details>
<summary> 접기/펼치기 </summary>

```cpp
//https://github.com/HaecheonLee/personal-studies/blob/06d3c8854aaa30dfd6bb3c924d0e75fcc8291ea3/PS/BOJ/20201030/%EB%B6%88%EC%9E%A5%EB%82%9C.cpp#L4

//어떻게든 규칙을 찾아내보려고 했는데 실패했다...
//파스칼의 삼각형에 얽매이던게 큰 실수였다.
//3시간동안 분석하다가 그제서야 탑다운 DP로 푸는게 맞는 것 같다는 확인이 섰다.

//y축, x축(기웅), x축(민수) 세 가지의 매개변수를 DFS에 사용했다.
//그에 따라 dx_A와 dx_B를 만들었다.

//좌표 변화 없이 내려가기 (0)
//한 쪽만 앞으로 이동 (1, 2)
//둘 다 앞으로 이동 (3)

//이렇게 해주면 기웅이가 앞에, 민수가 뒤에 있는 경우와 민수가 앞에, 기웅이가 뒤에 있는 경우를 모두 확인할 수 있다.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e4 + 7;

int N;
ll DP[103][103][103];
int dx_A[] = {0,1,0,1};
int dx_B[] = {0,0,1,1};

ll DFS(int y, int Ax, int Bx){
    if(y>1 && Ax==Bx) return 0; //첫 번째 칸이 아닌데 둘이 위치가 겹친 경우
    if(Ax>y || Bx>y) return 0; //문제 조건에 따라 y가 가로축 길이와 같으므로 OOB인 경우이다.
    
    if(y==N) return 1; //정상적으로 마지막 위치에 도달한 경우 1을 반환한다. (새로운 경로를 찾음)

    //메모이제이션
    ll&ret = DP[y][Ax][Bx];
    if(ret != -1) return ret;
    ret = 0;

    for(int dir=0; dir<4; dir++){
        ret += DFS(y+1, Ax+dx_A[dir], Bx+dx_B[dir]);
        ret %= MOD;
    }

    return ret;
}

int main(){
    cin>>N;
    memset(DP, -1, sizeof(DP));
    cout<<DFS(1,1,1);
    return 0;
}

```
</details>

- 탑다운 DP

###  

## G 두 개의 문
<details>
<summary> 접기/펼치기 </summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N, M;
string S;
bitset<101> door;
bitset<101> sw[23];
bool vis[1101010];
vector<vector<int>> Mp(300);

//현재 문 상태, 탐색깊이, 누른 스위치들 (누르면 1, int형으로 저장)
void Brute(bitset<101> cur, int depth, int swBit){
    if(depth>M) return;
    if(vis[swBit]) return;
    vis[swBit] = true;
    for(int i=0; i<M; i++){
        int bit = 1<<i;
        Brute(cur ^ sw[i], depth+1, swBit | bit);
    }
    int year = 100 - N + cur.count()*2;
    Mp[year].push_back(depth);
    Mp[year].push_back(swBit);
}

int main(){
    fastio;
    cin>>N>>M>>S;

    //String으로 입력된 문 초기 상태를 bitset으로 변환
    for(int i=0;i<S.size();i++){
        if(S[i]=='1') door.set(100-i, true);
    }

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            char x; cin>>x;
            if(x=='1') sw[i].set(100-j, true);
        }
    }

    Brute(door, 0, 0);

    for(int i=-1*N + 100; i<=N+100; i++){
        if(Mp[i].empty()) {cout<<-1<<'\n'; continue;}
        cout<<Mp[i][0]<<' ';
        int num = Mp[i][1];
        int idx = 1;
        while(num>0){
            if(num&1) cout<<idx<<' ';
            num >>= 1;
            idx++;
        }
        cout<<'\n';
    }
    return 0;
}

```
</details>

- Map은 느립니다
- 왠만해서 배열을 Map으로 바꿔쓰지 마십쇼..
