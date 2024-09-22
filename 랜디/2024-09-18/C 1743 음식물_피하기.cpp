//BFS Flood-Fill이 적합하다고 생각하긴 했는데, DFS로 풀어보았다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};

int ans = 0;
int N, M, K;
int board[103][103];
bool vis[103][103];

int DFS(int y, int x){
    int ret = 1;
    vis[y][x] = true;
    for(int dir=0; dir<4; dir++){
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
        if(vis[ny][nx] || board[ny][nx]==0) continue;
        ret += DFS(ny, nx);
    }
    return ret;
}

int main(){
    fastio;
    memset(board, 0, sizeof(board));
    cin>>N>>M>>K;
    while(K--){
        int a,b; cin>>a>>b;
        a--; b--;
        board[a][b] = 1;
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!vis[i][j] && board[i][j]==1) ans = max(DFS(i, j), ans);
        }
    }
    cout<<ans;
    return 0;
}
