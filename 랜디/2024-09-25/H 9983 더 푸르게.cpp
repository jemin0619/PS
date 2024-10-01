//굉장히 쓰레기같던 문제다.
//기물들이 서로를 공격하지 않게 하는 것을 서로 공격하는 기물 쌍을 제거하는 것으로 이해해서 한참 디버깅했다.
//TC 2에서 답이 2가 아니라 5여서 보니 문제를 잘못 이해했던 것이었다...
//애초에 쌍을 제거하는 것이 아니었으면 백트래킹으로 풀어도 될 것 같은데, 코드가 너무 복잡해져서 비트마스킹으로 풀었다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define pii pair<int,int>
#define x second 
#define y first

//12시부터 시계방향으로 넘어감
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

//나이트 이동
int Ndy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int Ndx[] = {1, 2, 2, 1, -1, -2, -2, -1};

//모든 기물이 서로를 공격하지 않는지 확인
bool check(vector<vector<char>> board){
    int N = board.size();
    int M = board[0].size();

    vector<pair<int,int>> V;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(board[i][j]!='E') V.push_back({i, j});
        }
    }

    for(int i=0; i<V.size(); i++){
        auto[curY, curX] = V[i];
        char ch = board[curY][curX];
        if(ch=='K'){
            for(int dir=0; dir<8; dir++){
                int ny = curY + dy[dir];
                int nx = curX + dx[dir];
                if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
                if(board[ny][nx]!='E') return false;
            }
        }
        if(ch=='Q'){
            for(int dir=0; dir<8; dir++){
                for(int k=1; k<=10; k++){
                    int ny = curY + dy[dir]*k;
                    int nx = curX + dx[dir]*k;
                    if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
                    if(board[ny][nx]!='E') return false;
                }
            }
        }
        if(ch=='B'){
            for(int dir : {1, 3, 5, 7}){
                for(int k=1; k<=10; k++){
                    int ny = curY + dy[dir]*k;
                    int nx = curX + dx[dir]*k;
                    if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
                    if(board[ny][nx]!='E') return false;
                }
            }
        }
        if(ch=='R'){
            for(int dir : {0, 2, 4, 6}){
                for(int k=1; k<=10; k++){
                    int ny = curY + dy[dir]*k;
                    int nx = curX + dx[dir]*k;
                    if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
                    if(board[ny][nx]!='E') return false;
                }
            }
        }
        if(ch=='N'){
            for(int dir=0; dir<8; dir++){
                int ny = curY + Ndy[dir];
                int nx = curX + Ndx[dir];
                if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
                if(board[ny][nx]!='E') return false;
            }
        }
    }
    return true;
}

void solve(){
    int w,h; cin>>w>>h;
    int ans = 0x7f7f7f7f;
    vector<vector<char>> board(h, vector<char>(w));

    vector<pii> V;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>board[i][j];
            if(board[i][j]!='E') V.push_back({i, j});
        }
    }
    
    for(int a=0; a<(1LL<<(int)V.size()); a++){
        vector<vector<char>> duplicated(board);
        int del = 0;
        for(int b=0; b<V.size(); b++){
            if(a&(1LL<<b)){
                //cout<<1;
                duplicated[V[b].y][V[b].x] = 'E';
                del++;
            }
            //else cout<<0;
        }
        if(check(duplicated)) {/*cout<<" ok";*/ ans=min(ans, del);}
        //if(del==4 || del==5) cout<<"THISTHISTHISTHISTHSI";
        //cout<<'\n';
    }   

    string End; cin>>End;
    cout<<"Minimum Number of Pieces to be removed: "<<ans<<'\n';
}

int main(){
    fastio;
    string Flag;
    while(cin>>Flag){
        solve();
    }
    return 0;
}
