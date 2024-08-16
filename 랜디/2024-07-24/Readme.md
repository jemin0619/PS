### [A 스타워즈 로고 B5](https://www.acmicpc.net/problem/9653)

### [B Perfect Shuffle S5](https://www.acmicpc.net/problem/9492)

### [C Account Names S4](https://www.acmicpc.net/problem/29881)

### [D Bumper-To-Bumper-Traffic S2](https://www.acmicpc.net/problem/14766)

### [E 거스름돈이 싫어요 S1](https://www.acmicpc.net/problem/20003)

### [F Inverting bits (Easy) G5](https://www.acmicpc.net/problem/18774)

### [G 달팽이와 쿼리 G4](https://www.acmicpc.net/problem/25294)

### [H 막대 자르기 G4](https://www.acmicpc.net/problem/27361)

# 학습노트

+ 학습한 내용
  - A : 출력하기
  - B : 문자열, 구현
  - C : map
  - D : Bruteforce
  - E : 유클리드 호제법
  - F : 애드훅, 해 구성하기
  - G : 구현, 수학
  - H : DP Knapsack

+ 총평
  - D는 for문에 최대시간 넣어서 찝찝하긴 함
  - E는 분자 또한 유클리드 호제법으로 구해줘야 했음 + 마지막에 기약분수로 처리
  - F는 입력 7개가 전부 1비트기에 7비트로 합쳐서 not치면 됨
  - 출력 부분에서 각 수들을 1비트로 맞춰줘야 했는데 이를 잊어서 애먹음.
  - G는 아직 이해가 안가는데, 수학 지식이 필요할듯...
  - H는 Knapsack DP였는데 [dp[i][j]: i번 막대까지 보았고, 길이 1인 막대를 j개 이상 얻는 최소비용] 으로 해결함

###  

## H 막대 자르기
<details>
<summary> 접기/펼치기 </summary>

```cpp
//dp[i][j] : i번째 막대기까지 보았고, 길이 1인 막대기를 j개 이상 만드는 최소비용
//dp[i][0]은 사용하지 않으므로 주석처리해도 잘 동작한다. (애초에 접근할 수 없는 공간임)
//그리고 풀다가 겪은 억까의 원인은 0x7f7f7f7f였다. 
//얘를 LLONG_MAX로 하니까 잘 동작했음...

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
const ll INF = LLONG_MAX;

int main() {
    fastio;
    ll T; cin>>T;
    while(T--){
        ll N, K, A, B; cin>>N>>K>>A>>B;
        vector<ll> S(1); //1-indexed 설정

        ll cnt = 0; //길이 1의 막대의 개수
        for(int i=1;i<=N;i++){
            ll x; cin>>x;
            if(x==1) cnt++;
            else S.push_back(x);
        }

        //길이 1의 막대만으로 K를 구성할 수 있다면 그게 최적해이므로 0 출력
        K-=cnt;
        if(K<=0){
            cout<<0<<'\n';
            continue;
        }

        N = S.size()-1;
        vector<vector<ll>> dp(N+3, vector<ll>(K+3, INF));
        //dp[0][0] = 0;
        for(int i=1;i<=N;i++){
            ll cost = A*(S[i]-1)*(S[i]-1) + B;
            //dp[i][0] = dp[i-1][0];
            for(int j=1;j<=K;j++){
                //만드려는 막대 길이(=j) 가 막대 길이 이하라면 
                if(j <= S[i]) dp[i][j] = min(dp[i-1][j], cost);

                //만드려는 막대 길이(=j) 가 막대 길이보다 크면 
                else if(j > S[i]){
                    if(dp[i-1][j-S[i]]>=INF) continue;
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-S[i]] + cost);
                }
            }
        }
        cout<<dp[N][K]<<'\n';
    }
    return 0;
}

```
</details>

- 최댓값은 항상 LLONG_MAX로...
- 어려운 DP문제는 아니고 그냥 전형적인 Knapsack인데 이거때문에 억까당함
