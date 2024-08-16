//https://www.acmicpc.net/problem/21772

//처음에 BFS로 하려다가 보니 먹이를 먹으면 먹이를 먹었다는 표시를 해야 하는데 BFS로 해당 기능을 구현하기는 어렵게 보였습니다.
//DFS 방식으로 접근해 가희를 이동시키면서 백트래킹으로 깊이 우선 탐색을 한 후, 이전 상태로 복귀하게 하면 해결할 수 있습니다.

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> Pii;
#define Y first
#define X second

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
char board[103][103];
int R,C,T; //세로 가로 이동시간
Pii Stpos;
int ans;

void DFS(int y, int x, int score, int depth){
    if(depth==T){
        ans = max(ans, score);
        return;
    }
    for(int dir=0; dir<4; dir++){
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny<0 || nx<0 || ny>=R || nx>=C) continue; //OOB
        if(board[ny][nx]=='#') continue; //이동 불가능한 장소

        bool flag = false; //ny nx에 고구마가 있는가?
        if(board[ny][nx]=='S') {flag=true; board[ny][nx]='.';} //있다면 고구마를 치움
        DFS(ny, nx, score+flag, depth+1); //DFS
        if(flag) board[ny][nx]='S'; //있었다면 고구마를 돌려놓음 (이전 상태로 복귀)
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>R>>C>>T;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>board[i][j];
            if(board[i][j]=='G'){
                Stpos={i,j};
                board[i][j]='.';
            }
        }
    }
    DFS(Stpos.Y, Stpos.X, 0, 0);
    cout<<ans;
    return 0;
}
