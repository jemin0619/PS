// {0,0} -> {N-1,M-1} BFS 경로 역추적

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define Y first 
#define X second

int N,M; //Y X
string board[150];

int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};
queue<pair<int,int>> Q;
bool vis[150][150];
pair<int,int> pre[150][150]; //경로복원 pre[y][x] : (y,x)로 이동하기 전에 있던 칸의 좌표

int main(){
    fastio;
    cin>>N>>M;
    for(int i=0;i<N;i++) cin>>board[i];
    Q.push({0,0}); vis[0][0]=true;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();

        if(cur.Y==N-1 && cur.X==M-1){ //N,M 도착
            vector<pair<int,int>> V;
            int y=N-1,x=M-1;
            while(!(y==0 && x==0)){
                V.push_back({y,x});
                int ny = pre[y][x].Y;
                int nx = pre[y][x].X;
                y=ny, x=nx;
            }
            V.push_back({0,0});
            for(int i=V.size()-1;i>=0;i--){
                cout<<V[i].Y+1<<' '<<V[i].X+1<<'\n';
            }
            break;
        }

        for(int dir=0;dir<4;dir++){
            int ny = cur.Y + dy[dir];
            int nx = cur.X + dx[dir];
            if(ny<0 || nx<0 || ny>=N || nx>=M) continue; //OOB
            if(vis[ny][nx] || board[ny][nx]=='*') continue;
            Q.push({ny,nx}); vis[ny][nx]=true;
            pre[ny][nx] = {cur.Y,cur.X};
        }
    }
    return 0;
}
