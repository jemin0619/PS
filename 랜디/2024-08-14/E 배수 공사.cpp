//슬쩍 보니 DP였다.
//N이 작아서 O(100*NM)에 동작한다.
//dp[i][j+Len]++을 해서 틀렸었다.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    ll N, M; cin>>N>>M;
    vector<vector<ll>> dp(N+3, vector<ll>(M+3));
    vector<ll> L(N+3), C(N+3);
    for(int i=1; i<=N; i++){
        cin>>L[i]>>C[i];
    }
    dp[0][0] = 1;
    for(int i=1; i<=N; i++){
        for(int j=0; j<=M; j++){
            if(dp[i-1][j]>0){
                ll Len = L[i];
                for(int k=1; k<=C[i]; k++){
                    if(j+Len>M) break;
                    dp[i][j+Len]+=dp[i-1][j]; 
                    Len += L[i];
                }
            }
        }
        for(int j=0; j<=M; j++){
            dp[i][j] += dp[i-1][j];
        }
    }
    cout<<dp[N][M];
    return 0;
}
