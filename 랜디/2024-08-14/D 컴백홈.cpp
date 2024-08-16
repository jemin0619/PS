//크기 제한부터 딱 보니 백트래킹이었다.
//그냥 3차원 vis 배열로도 풀리긴 할 것 같았는데, 오기가 생겨서 백트래킹으로 해결했다.

//K-1을 K로 쓰고, 시작 위치를 C-1, 0으로 실수해서 두 번 틀렸다.

#include <bits/stdc++.h>
using namespace std;

int Ans = 0;
int R,C,K;
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int vis[10][10];
char board[10][10];

void DFS(int y, int x, int depth){
    if(y==0 && x==C-1){
        if(depth == K-1) Ans++;
        return;
    }
    if(depth == K-1){
        if(y==0 && x==C-1) Ans++;
        return;
    }
    for(int dir=0; dir<4; dir++){
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny<0 || nx<0 || ny>=R || nx>=C) continue;
        if(vis[ny][nx] || board[ny][nx]=='T') continue;
        vis[ny][nx] = true;
        DFS(ny, nx, depth+1);
        vis[ny][nx] = false;
    }
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    cin>>R>>C>>K;
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            cin>>board[i][j];
    vis[R-1][0] = true;
    DFS(R-1,0,0);
    cout<<Ans;
    return 0;
}
