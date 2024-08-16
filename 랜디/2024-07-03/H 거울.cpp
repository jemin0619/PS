//혹시나 TLE를 받으면 최적화를 어떻게 해야 할지 고민했는데 그럴 필요가 없었다.
//무난하게 AC를 받았다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);

//우 상 좌 하
//0  3  2  1
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

int N,M; //Y X
int board[1003][1003];
vector<tuple<int,int,int>> pos; //dir, y, x
vector<int> Ans;

int solve(tuple<int,int,int> pos){
    auto [dir,y,x] = pos;
    while(true){
        //cout<<y<<' '<<x<<'\n';
        y += dy[dir];
        x += dx[dir];
        if(board[y][x]==1 && x!=0){ //거울을 만나면
            if(dir==3) dir=0;
            else if(dir==0) dir=3;
            else if(dir==1) dir=2;
            else if(dir==2) dir=1;
        }
        if(!((1<=y && y<=N) && (1<=x && x<=M))) break;
    }
    return board[y][x];
}

int main(){
    fastio;
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            cin>>board[i][j];
    for(int i=1;i<=N;i++) {pos.push_back({0,i,0}); board[i][0]=pos.size();}
    for(int i=1;i<=M;i++) {pos.push_back({3,N+1,i}); board[N+1][i]=pos.size();}
    for(int i=N;i>=1;i--) {pos.push_back({2,i,M+1}); board[i][M+1]=pos.size();}
    for(int i=M;i>=1;i--) {pos.push_back({1,0,i}); board[0][i]=pos.size();}
    for(int i=0; i<pos.size(); i++){
        Ans.push_back(solve(pos[i]));
    }
    for(int val : Ans) cout<<val<<' ';
    return 0;
}
