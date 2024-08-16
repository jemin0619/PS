//이게 이번 셋에서 시간 내에 푼 4문제중 가장 어려웠다.
//매번 방문배열 초기화해주는 발상이 쉽게 떠오르지 않는다.
//청소를 할 때마다 방문 배열을 초기화해주어야 하는 이유는 청소를 했다면 다음에 방문했던 곳을 다시 방문하더라도 경로가 바뀌기 때문이다.

#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int N, M; //세로 가로
int R,C,D;
string A[70];
string B[70];
int board[70][70];
bool vis[103][103][5];
long long Ans = 0;

void DFS(int y, int x, int dir, long long depth){
    if(y<0 || x<0 || y>=N || x>=M) return;
    if(vis[y][x][dir]) return;
    vis[y][x][dir] = true;
    if(board[y][x]==0){
        Ans = max(Ans, depth+1);
        dir += (A[y][x]-'0');
        dir %= 4;
        board[y][x]=1;
        memset(vis, false, sizeof(vis));
    }
    else{
        dir += (B[y][x]-'0');
        dir %= 4;
    }
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    
    DFS(ny, nx, dir, depth+1);
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    memset(board, 0, sizeof(board));
    memset(vis, false, sizeof(vis));
    cin>>N>>M;
    cin>>R>>C>>D;
    for(int i=0; i<N; i++) cin>>A[i];
    for(int i=0; i<N; i++) cin>>B[i];

    DFS(R,C,D,0);

    cout<<Ans;
    return 0;
}
