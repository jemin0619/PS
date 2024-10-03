//기본적인 dp 누적합

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int R,C,Q; cin>>R>>C>>Q;
    vector<vector<int>> dp(R+1, vector<int>(C+1, 0));
    for(int i=1; i<=R; i++)
        for(int j=1; j<=C; j++)
            cin>>dp[i][j];
    
    for(int i=2; i<=R; i++)
        for(int j=1; j<=C; j++)
            dp[i][j] += dp[i-1][j];
    for(int i=1; i<=R; i++)
        for(int j=2; j<=C; j++)
            dp[i][j] += dp[i][j-1];

    while(Q--){
        int r1,c1,r2,c2; cin>>r1>>c1>>r2>>c2;
        int A = (r2-r1+1)*(c2-c1+1); //넓이
        int sum = dp[r2][c2] - dp[r2][c1-1] - dp[r1-1][c2] + dp[r1-1][c1-1];
        cout<<sum/A<<'\n';
    }
    return 0;
}
