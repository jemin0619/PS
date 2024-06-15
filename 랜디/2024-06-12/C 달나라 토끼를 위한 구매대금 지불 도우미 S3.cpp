//DP 문제이다.
//1차원 DP가 정해인데, 당장 기억나는 Knapsack으로 풀었다. (비효율적임)
//동전의 가짓수를 입력받는 문제였으면 knapsack이 정해일텐데 가짓수가 정해져있어서 1차원 DP로 해결할 수 있는 것 같다.

//DP[i][j] : i번째 동전까지 고려했을 때 j를 만들어내는 동전의 최소 개수
//테이블 초기값은 dp[0][0]을 제외하고 전부 INF

//점화식은 다음과 같다.
//dp[i][j] = dp[i-1][j]
//if(j-coin[i]>=0) dp[i][j] = min(dp[i][j], dp[i][j-coin[i]]+1)

//처음에 두 번째 식을 dp[i-1][j-coin[i]]+1로 해서 WA가 떴다.
//가장 최근에 갱신된 값을 기준으로 변경해야 하는데 햇갈렸다.

//또 처음엔 j%coin[i]==0 이면 j/coin[i]도 min 인자에 추가했는데 이는 두 번째 점화식의 확장이기에 굳이 필요가 없다.

#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(NULL) -> sync_with_stdio(false);
#define ll long long

const ll INF = 0x7f7f7f7f;
ll n;
ll dp[5][100003]; // i번째 동전까지 고려했을 때 j를 만들어내는 동전의 최소개수
ll coin[5] = {0, 1, 2, 5, 7}; // 동전의 값들

int main() {
    fastio;
    cin>>n;
  
    for(int i=0; i<=4; i++)
        for(int j=0; j<=n; j++)
            dp[i][j] = INF;
  
    dp[0][0] = 0;
  
    for (int i=1; i<=4; i++) {
        for (int j=0; j<=n; j++) {
            dp[i][j] = dp[i-1][j];
            if(j-coin[i]>=0) dp[i][j] = min(dp[i][j], dp[i][j-coin[i]]+1);
        }
    }
    cout<<dp[4][n];
    return 0;
}
