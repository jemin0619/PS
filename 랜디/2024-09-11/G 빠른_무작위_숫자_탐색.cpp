//비트마스킹, 그래프탐색

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};
int board[8][8];

//어떤 상태로 공간에 방문했는지를 저장해야됨
int vis[8][8][1023]; //Y X state

int Y, X;

int main(){
    fastio;
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            cin>>board[i][j];
    cin>>Y>>X;
    int ans = 0x7f7f7f7f;
    queue<tuple<int,int,int, int>> Q;
    Q.push({Y, X, 0, 0});
    vis[Y][X][0] = true;
    while(!Q.empty()){
        auto[curY, curX, curB, curD] = Q.front(); Q.pop();
        if(curB==126){
            ans = min(ans, curD);
            continue;
        }
        if(curD >= ans) continue;
        for(int dir=0; dir<4; dir++){
            int ny = curY + dy[dir];
            int nx = curX + dx[dir];
            if(ny<0 || nx<0 || ny>=5 || nx>=5) continue;
            if(board[ny][nx]==-1) continue;
            int nB = curB | (1<<board[ny][nx]);
            if(board[ny][nx]==0) nB = curB; //이걸 넣어줘야 TC 2에서 AC를 받음
            if(vis[ny][nx][nB]) continue;
            Q.push({ny, nx, nB, curD+1});
            vis[ny][nx][nB] = true;
        }
    }
    if(ans==0x7f7f7f7f) cout<<-1;
    else cout<<ans;
    return 0;
}
