#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL) -> sync_with_stdio(false)

int solve(int N, vector<int>&V){
    //dp[i][j]: i에서 j까지 합쳤을 때 내야 하는 최소 비용
    //prefix[en] - prefix[st-1] = st ~ en까지 부분합

    //dp[i][i] = 0  (1 <= i <= N)
    //dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j] + prefix[j]-prefix[i-1])     (i <= k < j)

    //[i~j까지 묶는 최소비용] 은 다음과 같다.
    //[i~k 까지 묶는 최소비용] + [k+1~j 까지 묶는 최소비용] + [i~j까지의 구간합]

    vector<vector<int>> dp(N+1, vector<int>(N+3));

    vector<int> prefix(N+1);

    for(int i=1;i<=N;i++){
        prefix[i] = prefix[i-1] + V[i];
    }

    for(int gap=1; gap<N; gap++){
        for(int i=1;i+gap<=N;i++){
            int j = i+gap;
            dp[i][j] = 1e9;
            for(int k=i; k<=j-1; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + prefix[j] - prefix[i-1]);
            }
        }
    }
    return dp[1][N];
}

int main(){
    fastio;
    int t; cin>>t;
    while(t--){
        int N; cin>>N;
        vector<int> V(N+1);
        for(int i=1;i<=N;i++) cin>>V[i];
        cout<<solve(N, V)<<'\n';
    }
    return 0;
}
