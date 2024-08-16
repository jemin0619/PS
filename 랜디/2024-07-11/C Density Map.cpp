#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int board[253][253];
int W[253][253];
int dp[253][253];

int main() {
    fastio;
    int n,r; cin>>n>>r;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>board[i][j];

    //2차원 누적합
    for(int i=1;i<=n;i++){
        dp[i][1] = board[i][1];
        for(int j=2;j<=n;j++){
            dp[i][j] = dp[i][j-1]+board[i][j];
        }
    }
 
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] += dp[i-1][j];
        } 
    }
         
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int W = 0;
            W += dp[min(n,i+r)][min(n,j+r)];
            W -= dp[max(i-r-1,0)][min(n,j+r)];
            W -= dp[min(n,i+r)][max(j-r-1,0)];
            W += dp[max(i-r-1,0)][max(j-r-1,0)];
            cout<<W<<' ';
        } cout<<'\n';
    }
    return 0;
}
