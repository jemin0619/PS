//BFS 스타일로 문제를 해결할 수 있음
//O(N*N*4M) BruteForce

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N,M,Ans;
int board[53][53];

int dy[2][4] = {{0,1,0,-1},{1,-1,-1,1}};
int dx[2][4] = {{1,0,-1,0},{1,1,-1,-1}};

int solve(int y, int x, int type){
    int ret = board[y][x]; //일단 폭탄 지점을 터뜨림
    for(int dir=0;dir<4;dir++){ //두 type 모두 4방향임
        for(int i=1;i<=M;i++){ //M번 퍼져나감
            int ny = y+dy[type][dir]*i;
            int nx = x+dx[type][dir]*i;
            if(ny<0 || nx<0 || ny>=N || nx>=N) break;
            ret += board[ny][nx];
        }
    }
    return ret;
}

int main(){
    fastio;
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>board[i][j];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int val1 = solve(i,j,0);
            int val2 = solve(i,j,1);
            Ans = max({Ans,val1,val2});
        }
    }
    cout<<Ans;
    return 0;
}
