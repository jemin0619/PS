//1915번과 같은 dp이다.
//dp[i][j]: i,j를 우측 하단 꼭짓점으로 갖는 가장 큰 정사각형의 한 변의 길이

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int main(){
    fastio;
    int M, N; cin>>M>>N;
    int board[M+3][N+3];
    int dp[M+3][N+3];
    memset(dp, -1, sizeof(dp));

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin>>board[i][j];
            if(board[i][j]==0) dp[i][j] = 1;
        }
    }

    for(int i=1; i<M; i++){
        for(int j=1; j<N; j++){
            int p1 = dp[i][j];
            int p2 = dp[i][j-1];
            int p3 = dp[i-1][j];
            int p4 = dp[i-1][j-1];
            if(p1!=-1 && p2!=-1 && p3!=-1 && p4!=-1) dp[i][j] = min({p2,p3,p4})+1;
        }
    }

    int mx = 0;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            mx = max(mx, dp[i][j]);
        }
    }
    cout<<mx;
    return 0;
}
