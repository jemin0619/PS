//구현은 한 번에 잘 했는데, 게임이 중간에 종료될 수 있다는 것을 보지 못해서 디버깅하느라 힘들었다.
//배경 부분과 보드 부분으로 분리해서 박스 이동을 처리했다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N, M; 
int curY, curX;
int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};

void mv(vector<vector<char>>&board, vector<vector<char>>&bg, int dir){
    int ny = curY + dy[dir];
    int nx = curX + dx[dir];
    int nny = ny + dy[dir];
    int nnx = nx + dx[dir];

    if(ny<0 || nx<0 || ny>=N || nx>=M) {/*cout<<"OOB\n";*/ return;} //OOB
    if(board[ny][nx]=='#') {/*cout<<"#\n";*/ return;} //벽을 만난 경우

    if(board[ny][nx]=='.' || board[ny][nx]=='+'){ //빈칸 (. +)
        curY = ny; curX = nx;
        //cout<<"Empty "<<curY<<' '<<curX<<'\n';
        return;
    }

    if(board[ny][nx]=='b'){
        if(nny<0 || nnx<0 || nny>=N || nnx>=M) {/*cout<<"Box OOB\n";*/ return;} //OOB
        if(board[nny][nnx]=='#' || board[nny][nnx]=='b') {/*cout<<"Box #\n";*/ return;} //다음다음칸에 벽 or 박스
        board[nny][nnx] = 'b';
        board[ny][nx] = bg[ny][nx];
        curY = ny; curX = nx;
        //cout<<"Box "<<curY<<' '<<curX<<'\n';
        return;
    }
}

int main(){
    fastio;
    int tc = 1;
    while(true){
        cin>>N>>M;
        if(N==0 && M==0) break;
        
        vector<vector<char>> board(N+3, vector<char>(M+3));
        vector<vector<char>> backGround(N+3, vector<char>(M+3));
        vector<pair<int,int>> dest;

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                char c; cin>>c;
                board[i][j] = c;
                backGround[i][j] = c;
                
                if(c=='.' || c=='#'){
                    continue;
                }
                if(c=='+'){
                    dest.push_back({i,j});
                }
                if(c=='b'){
                    backGround[i][j] = '.';
                }
                if(c=='B'){
                    dest.push_back({i,j});
                    backGround[i][j] = '+';
                    board[i][j] = 'b';
                }
                if(c=='w'){
                    curY = i; curX = j;
                    backGround[i][j] = '.';
                    board[i][j] = '.';
                }
                if(c=='W'){
                    curY = i; curX = j;
                    dest.push_back({i, j});
                    backGround[i][j] = '+';
                    board[i][j] = '+';
                }
            }
        }

        string S; cin>>S;
        for(char c : S){
            if(c=='U'){
                mv(board, backGround, 2);
            }
            if(c=='D'){
                mv(board, backGround, 0);
            }
            if(c=='R'){
                mv(board, backGround, 1);
            }
            if(c=='L'){
                mv(board, backGround, 3);
            }

            bool complete = true;
            for(auto[y, x] : dest){
                if(board[y][x]!='b') complete=false;
            }
            if(complete) break;
        }

        bool complete = true;
        for(auto[y, x] : dest){
            if(board[y][x]!='b') complete=false;
        }

        board[curY][curX] = 'w'; 

        if(!complete) cout<<"Game "<<tc++<<": incomplete"<<'\n';
        if(complete) cout<<"Game "<<tc++<<": complete"<<'\n';
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(backGround[i][j]=='+' && board[i][j]!='+') cout<<(char)(board[i][j]+('A'-'a'));
                else cout<<board[i][j];
            } cout<<'\n';
        }
    }
    return 0;
}
