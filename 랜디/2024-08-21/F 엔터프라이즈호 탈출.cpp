//2차원 행렬에서의 다익스트라
//Quick out of the harbour과 비슷한 문제라 기억에 남는다.
//44줄의 코드가 기억에 남는데, 저게 최적해라고 한다.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define tiii tuple<ll,ll,ll>

ll dy[] = {1,0,-1,0};
ll dx[] = {0,1,0,-1};

int main(){
    fastio;
    int tc; cin>>tc;
    while(tc--){
        ll K, W, H; cin>>K>>W>>H;
        vector<ll> Weight(30);
        for(int i=0; i<K; i++){
            char X; int w; cin>>X>>w;
            Weight[X-'A'] = w;
        }
        vector<vector<char>> board(H+3, vector<char>(W+3));
        vector<vector<ll>> dp(H+3, vector<ll>(W+3, 0x7f7f7f7f));
        priority_queue<tiii, vector<tiii>, greater<tiii>> PQ;
        for(ll i=0; i<H; i++){
            for(ll j=0; j<W; j++){
                cin>>board[i][j];
                if(board[i][j]=='E'){
                    PQ.push({0,i,j});
                    dp[i][j] = 0;
                }
            }
        }
        while(!PQ.empty()){
            auto [curW, curY, curX] = PQ.top(); PQ.pop();

            if(dp[curY][curX] < curW) continue;

            for(int dir=0; dir<4; dir++){
                ll ny = curY + dy[dir];
                ll nx = curX + dx[dir];
                if(ny<0 || nx<0 || ny>=H || nx>=W){
                    cout<<curW<<'\n'; //현재 위치가 가장자리라는 의미이므로 탈출했다.
                    goto fin;
                }
                ll nw = curW + Weight[board[ny][nx]-'A'];
                if(dp[ny][nx] <= nw) continue;
                dp[ny][nx] = nw;
                PQ.push({nw, ny, nx});
            }
        }
        fin: continue;
    }
    return 0;
}
