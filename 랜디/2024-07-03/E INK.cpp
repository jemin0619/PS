//간단한 시뮬레이션 문제
//많조분까진 갈 필요 없는듯

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define X second 
#define Y first

//BFS
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
bool vis[103][103];

int I,N,K;
string ink;
string command;
char board[103][103];
char board_ink[103][103]; //장애물 칸에 잉크를 칠함
pair<int,int> pos;        //플레이어의 위치
int inks = 0;             //플레이어가 충전한 잉크의 양
int jumpcnt = 0;          //플레이어가 지금까지 점프한 횟수 (mod ink.size())

int main(){
    fastio;
    memset(board_ink,'#',sizeof(board_ink));
    cin>>I>>N>>K>>ink;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>board[i][j];
            if(board[i][j]=='@'){
                board[i][j]='.';
                pos = {i,j};
            }
        }
    }
    cin>>command;
    for(char c : command){
        //이동 커맨드
        if(c=='U' && pos.Y-1>=0 && board[pos.Y-1][pos.X]!='#') pos.Y--;
        if(c=='D' && pos.Y+1<N && board[pos.Y+1][pos.X]!='#') pos.Y++;  
        if(c=='R' && pos.X+1<N && board[pos.Y][pos.X+1]!='#') pos.X++;
        if(c=='L' && pos.X-1>=0 && board[pos.Y][pos.X-1]!='#') pos.X--;

        //잉크 충전 커맨드
        if(c=='j') inks++;

        //점프 커맨드
        if(c=='J'){
            memset(vis,false,sizeof(vis));
            queue<tuple<int,int,int>> Q;
            Q.push({pos.Y,pos.X,0});
            vis[pos.Y][pos.X]=true;
            while(!Q.empty()){
                auto [curY,curX,curD] = Q.front(); Q.pop();
                if(board[curY][curX]=='#'){
                    board_ink[curY][curX] = ink[jumpcnt];
                }
                if(curD >= inks) continue;
                for(int dir=0;dir<4;dir++){
                    int ny = curY + dy[dir];
                    int nx = curX + dx[dir];
                    if(ny<0 || nx<0 || ny>=N || nx>=N) continue;
                    if(vis[ny][nx]) continue;
                    Q.push({ny,nx,curD+1}); vis[ny][nx]=true;
                }
            }
            inks = 0;
            jumpcnt++;
            jumpcnt %= ink.size();
        }
    }
    board[pos.Y][pos.X] = '@';
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]=='#') cout<<board_ink[i][j];
            else cout<<board[i][j];
        } cout<<'\n';
    }
    return 0;
}   
