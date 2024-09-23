//모든 이동에 드는 가중치가 1이므로 BFS만으로 해결할 수 있다.
//dist 배열을 써서 방문처리 + 큐에 들어가는 값 개수 커팅도 가능하겠지만 굳이 하지 않았다.
//그냥 겹치는 원소 제거만 해줘도 N,M이 작아서 제한시간 내에 충분히 돌아간다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};

int N, M;
vector<string> board;
queue<tuple<int,int,int>> Player;
queue<pair<int,int>> Water;

int main(){
    fastio;
    cin>>N>>M;
    board.resize(N);
    for(int i=0; i<N; i++){
        cin>>board[i];
        for(int j=0; j<M; j++){
            if(board[i][j]=='S'){
                board[i][j] = '.';
                Player.push({i,j,0});
            }
            if(board[i][j]=='*'){
                Water.push({i,j});
            }
        }
    }
    while(!Player.empty() || !Water.empty()){
        //Player, Water 모두 비어있을 경우 종료

        //물을 먼저 퍼뜨림
        queue<pair<int,int>> Wtmp;
        vector<pair<int,int>> Wtmp_Uniue;
        while(!Water.empty()){
            auto[curY, curX] = Water.front(); Water.pop();
            for(int dir=0; dir<4; dir++){
                int ny = curY + dy[dir];
                int nx = curX + dx[dir];
                if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
                if(board[ny][nx]!='.') continue;
                board[ny][nx] = '*';
                Wtmp_Uniue.push_back({ny, nx});
            }
        } 
        sort(Wtmp_Uniue.begin(), Wtmp_Uniue.end());
        Wtmp_Uniue.erase(unique(Wtmp_Uniue.begin(), Wtmp_Uniue.end()), Wtmp_Uniue.end());
        for(auto[a, b] : Wtmp_Uniue) Wtmp.push({a,b});
        Water = Wtmp;

        //고슴도치 이동
        queue<tuple<int,int,int>> Ptmp;
        vector<tuple<int,int, int>> Ptmp_Uniue;
        while(!Player.empty()){
            auto[curY, curX, curW] = Player.front(); Player.pop();
            if(board[curY][curX]=='D'){
                cout<<curW; return 0;
            }
            for(int dir=0; dir<4; dir++){
                int ny = curY + dy[dir];
                int nx = curX + dx[dir];
                if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
                if(board[ny][nx]=='*' || board[ny][nx]=='X') continue;
                Ptmp_Uniue.push_back({ny, nx, curW+1});
            }
        }
        sort(Ptmp_Uniue.begin(), Ptmp_Uniue.end());
        Ptmp_Uniue.erase(unique(Ptmp_Uniue.begin(), Ptmp_Uniue.end()), Ptmp_Uniue.end());
        for(auto[a, b, c] : Ptmp_Uniue) Ptmp.push({a,b,c});
        Player = Ptmp;
    }
    cout<<"KAKTUS";
    return 0;
}
