//11066 파일 합치기와 비슷한 방식으로 풀 수 있다.
//시간복잡도: O(N^3)

//V에 입력받지 말고 바로 dp에 넣어도 된다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define pii pair<int,int>

struct matrix{
    int ff;
    int ss;
    int val;
};


int main(){
    fastio;
    int N; cin>>N;
    vector<pii> V(N);
    vector<vector<matrix>> dp(N, vector<matrix>(N));
    for(int i=0;i<N;i++){
        cin>>V[i].first>>V[i].second;
        dp[i][i].ff = V[i].first;
        dp[i][i].ss = V[i].second;
    }

    for(int i=0; i<N-1; i++){
        dp[i][i+1].val = V[i].first * V[i+1].first * V[i+1].second;
        dp[i][i+1].ff = V[i].first;
        dp[i][i+1].ss = V[i+1].second;
    }

    for(int gap=1; gap<N; gap++){
        for(int i=0;i+gap<N; i++){
            int j = i+gap;
            dp[i][j].val = 1e9;
            for(int k=i; k<j; k++){
                int value = dp[i][k].ff * dp[k+1][j].ff * dp[k+1][j].ss + dp[i][k].val + dp[k+1][j].val;
                if(dp[i][j].val > value){
                    dp[i][j].val = value;
                    dp[i][j].ff = dp[i][k].ff;
                    dp[i][j].ss = dp[k+1][j].ss;
                }
            }
        }
    }
    cout<<dp[0][N-1].val;
    return 0;
}
