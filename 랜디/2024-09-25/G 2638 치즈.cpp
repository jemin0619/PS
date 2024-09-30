//시간복잡도에 구애받지 않고 적당히 대충 구현해도 AC를 받을 수 있습니다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N, M;
vector<vector<int>> board;
int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};

bool check(){
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(board[i][j]==2) cnt++;
        }
    }
    return cnt==N*M;
}

int main(){
    fastio;
    cin>>N>>M;
    board.resize(N, vector<int>(M));
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin>>board[i][j];

    queue<pair<int,int>> Q;
    Q.push({0,0});
    while(!Q.empty()){
        auto[curY, curX] = Q.front(); Q.pop();
        board[curY][curX] = 2;
        for(int dir=0; dir<4; dir++){
            int ny = curY + dy[dir];
            int nx = curX + dx[dir];
            if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
            if(board[ny][nx]!=0) continue;
            board[ny][nx] = 2;
            Q.push({ny, nx});
        }
    }
    if(check()) {cout<<"0"; return 0;}
    for(int day=1;;day++){

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(board[i][j]!=1) continue;
                int cnt = 0;
                for(int dir=0; dir<4; dir++){
                    int ny = i + dy[dir];
                    int nx = j + dx[dir];
                    if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
                    if(board[ny][nx]==2) cnt++;
                }
                if(cnt>=2){
                    board[i][j] = 0;
                    Q.push({i, j});
                }
            }
        }

        while(!Q.empty()){
            auto[curY, curX] = Q.front(); Q.pop();
            board[curY][curX] = 2;
            for(int dir=0; dir<4; dir++){
                int ny = curY + dy[dir];
                int nx = curX + dx[dir];
                if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
                if(board[ny][nx]!=0) continue;
                board[ny][nx] = 2;
                Q.push({ny, nx});
            }
        }
        if(check()) {cout<<day; break;}
    }
    return 0;
}
