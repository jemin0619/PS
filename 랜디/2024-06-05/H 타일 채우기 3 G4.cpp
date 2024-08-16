#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

const ll MOD = 1'000'000'007;
ll dp[1000'003][2];

int main(){
    fastio;
    ll N; cin>>N;

    dp[0][0]=0;
    dp[1][0]=2;
    dp[2][0]=7; dp[2][1]=1;
    for(int i=3;i<=N;i++){
        dp[i][1] = (dp[i-1][1] + dp[i-3][0])%MOD;
        dp[i][0] = (dp[i-1][0]*2 + dp[i-2][0]*3 + 2*dp[i][1])%MOD;
    }

    cout<<dp[N][0];
    return 0;
}
