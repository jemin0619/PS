//문제가 어렵진 않았는데, 구현에서 좀 헤맸다.
//left right 함수를 만들고, 시계방향으로 1씩 증가하게 방향을 부여하면 깔끔하게 짤 수 있었다.
//풀고 나서 보니 BFS1만 있어도 될 것 같긴 하다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

//Up이 0이고, 시계방향으로 1씩 증가하게 표시

int N, M, K;
int board[53][53];
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
bool vis0[53][53];
bool vis1[53][53][2][2];

int right(int n){
    return (n+1)%4;
}

int left(int n){
    if(n==0) return 4;
    else return n-1;
}

void BFS0(){ //K가 0일 때 일반 BFS
    queue<pair<int,int>> Q;
    Q.push({0,0});
    vis0[0][0] = true;
    while(!Q.empty()){
        auto&[y,x]=Q.front(); Q.pop();
        if(y==N-1 && x==M-1){cout<<"Yes"; return;}
        int dir = board[y][x];

        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
        if(vis0[ny][nx]) continue;
        Q.push({ny, nx});
        vis0[ny][nx] = true;
    }
    cout<<"No";
}

void BFS1(){
    queue<tuple<int,int,int,int>> Q;
    Q.push({0,0,1,1});
    vis1[0][0][1][1] = true;
    while(!Q.empty()){
        auto&[y,x,l,r] = Q.front(); Q.pop();
        if(y==N-1 && x==M-1){cout<<"Yes"; return;}
        int dir = board[y][x];

        int ny = y + dy[dir];
        int nx = x + dx[dir];
        int nl = l;
        int nr = r;
        if(0<=ny&&ny<N&&0<=nx&&nx<M&&!vis1[ny][nx][nl][nr]){
            Q.push({ny,nx,nl,nr});
            vis1[ny][nx][nl][nr]=true;
        }

        if(l==1){
            int dirLeft = left(dir);
            ny = y + dy[dirLeft];
            nx = x + dx[dirLeft];
            nl = 0;
            nr = r;
            if(0<=ny&&ny<N&&0<=nx&&nx<M&&!vis1[ny][nx][nl][nr]){
                Q.push({ny,nx,nl,nr});
                vis1[ny][nx][nl][nr]=true;
            }
        }
        
        if(r==1){
            int dirRight = right(dir);
            ny = y + dy[dirRight];
            nx = x + dx[dirRight];
            nl = l;
            nr = 0;
            if(0<=ny&&ny<N&&0<=nx&&nx<M&&!vis1[ny][nx][nl][nr]){
                Q.push({ny,nx,nl,nr});
                vis1[ny][nx][nl][nr]=true;
            }
        }
    }
    cout<<"No";
}

int main(){
    fastio;
    cin>>N>>M>>K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char c; cin>>c;
            if(c=='U') {board[i][j]=0;}
            if(c=='R') {board[i][j]=1;}
            if(c=='D') {board[i][j]=2;}
            if(c=='L') {board[i][j]=3;}
        }
    }
    if(K==0) BFS0();
    else BFS1();
    return 0;
}
