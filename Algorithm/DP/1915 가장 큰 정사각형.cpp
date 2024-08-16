//https://www.acmicpc.net/problem/1915

//dp[i][j]: 모서리를 i,j로 하는 정사각형의 최대 변 길이
//dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
//2차원 누적합이랑 비슷한 느낌이 들었다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int N, M; cin>>N>>M;
    vector<string> V(N);
    for(int i=0;i<N;i++) cin>>V[i];
    vector<vector<int>> dp(N+3, vector<int>(M+3, 0));
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            if(V[i-1][j-1]=='1') dp[i][j]=1;
    int mx = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(dp[i][j]==0) continue;
            dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
            mx = max(dp[i][j], mx);
        }
    }
    cout<<mx*mx;
    return 0;
}
