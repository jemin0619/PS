//나는 모든 직사각형을 만들고, 체크해서 O(N^4)인 알고리즘을 짰다.
//이 풀이보다 나은 풀이로는 M개의 블럭으로 만들 수 있는 직사각형만 만든 후 체크하는 방법이 있다.
//간단하게 설명하면 조각이 4개일 경우, {1,4}, {2,2}, {4,1} 식으로 뽑아내고 각 경우마다 2중 for문을 돌리는 것이다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define pii pair<int,int>
#define x first
#define y second

int getCost(pii st, pii en, int blocks, vector<vector<int>>&dp){
    int sz = (en.x-st.x+1)*(en.y-st.y+1);
    if(sz!=blocks) return -1; //구간 크기가 가진 블럭 수보다 많으면 불가능
    int k = dp[en.x][en.y] + dp[st.x-1][st.y-1] - dp[st.x-1][en.y] - dp[en.x][st.y-1];
    return blocks-k;
}

int main(){
    fastio;
    int N, M; cin>>N>>M;
    vector<vector<int>> board(N+1, vector<int>(N+1, 0));
    vector<vector<int>> dp(N+1, vector<int>(N+1, 0)); //dp[i][j] : {0,0}에서 {i,j}까지 한 개 이상 쌓여있는 블럭들의 개수
    for(int i=0; i<M; i++){
        int x,y; cin>>x>>y;
        board[x][y]++;
        dp[x][y] = 1;
    }

    for(int i=2; i<=N; i++)
        for(int j=1; j<=N; j++)
            dp[i][j] += dp[i-1][j];

    for(int i=1; i<=N; i++)
        for(int j=2; j<=N; j++)
            dp[i][j] += dp[i][j-1];

    int ans = 0x7f7f7f7f;
    for(int stx=1; stx<=N; stx++){
        for(int sty=1; sty<=N; sty++){
            for(int enx=stx; enx<=N; enx++){
                for(int eny=sty; eny<=N; eny++){
                    int x = getCost({stx, sty}, {enx, eny}, M, dp);
                    if(x==-1) continue;
                    ans = min(ans, x);
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
