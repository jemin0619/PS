//dp 테이블을 2차원으로 만들어서 풀었는데, 1차원 배열만으로도 해결이 가능하다.
//각 V[i]에 대해서 매번 K ~ V[i]까지 역순으로 순회하면서 dp[K ~ V[i]] 값을 갱신해주면 된다.
//역순으로 해주어야 구현이 간단해진다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int N, K;
vector<int> V;
vector<vector<int>> dp; //dp[i][j] : i번째 커피까지 보았을 때 j를 만들기 위한 최솟값

int main(){
    fastio;
    cin>>N>>K;
    V.resize(N+3);
    dp.resize(N+3, vector<int>(K+3, 0x7f7f7f7f));
    for(int i=1; i<=N; i++) cin>>V[i];
    dp[0][0] = 0;
    for(int i=1; i<=N; i++){
        for(int j=0; j<=K; j++){
            if(j-V[i]>=0) dp[i][j] = min(dp[i-1][j], dp[i-1][j-V[i]]+1);
            else dp[i][j] = dp[i-1][j];
        }
    }
    if(dp[N][K] == 0x7f7f7f7f) cout<<-1;
    else cout<<dp[N][K];
    return 0;
}
