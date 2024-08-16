//dp[i][j]: i번째 손님까지 걸리는 최소비용
//j==0: i번째 손님만 따로 처리
//j==1: i-1번째 손님과 i번째 손님을 같이 처리

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int main(){
    fastio;
    int N; cin>>N;
    vector<ll> V(N);
    vector<vector<ll>> dp(N, vector<ll>(3));
    for(int i=0; i<N; i++) cin>>V[i];
    
    dp[0][0] = dp[0][1] = V[0];
    for(int i=1; i<N; i++){
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + V[i];
        dp[i][1] = dp[i-1][0] - V[i-1] + max(V[i], V[i-1]);
    }
    
    cout<<min(dp[N-1][0], dp[N-1][1]);
    return 0;
}
