#include <bits/stdc++.h>
using namespace std;
#define tiii tuple<int,int,int>
#define fastio cin.tie(NULL)->sync_with_stdio(false)

const int INF = 1e9 + 10;
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

int main(){
    fastio;
    int t; cin>>t;
    while(t--){
        int N, M, C; //세로 가로 @여는데걸리는시간
        priority_queue<tiii,vector<tiii>,greater<tiii>> PQ;
        cin>>N>>M>>C; 
        vector<vector<char>> board(N,vector<char>(M));
        vector<vector<int>> d(N, vector<int>(M, INF));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>board[i][j];
                if(board[i][j]=='S'){
                    d[i][j] = 0;
                    PQ.push({d[i][j],i,j});
                }
            }
        }
        while(!PQ.empty()){
            auto [curW, curY, curX] = PQ.top();
            PQ.pop();

             //맵 밖으로 나가면 종료
            if(curY==0 || curY==N-1 || curX==0 || curX==M-1){
                cout<<d[curY][curX]+1<<'\n';
                break;
            }

            for(int dir=0;dir<4;dir++){
                int ny = curY+dy[dir];
                int nx = curX+dx[dir];
                if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
                if(board[ny][nx]=='#') continue;

                //@면 1+C만큼 기다려야하고, 아니면 이동에 1만큼 걸린다.
                int nw = (board[ny][nx]=='@' ? 1+C : 1);
                if(d[ny][nx]<=d[curY][curX]+nw) continue;
                d[ny][nx]=d[curY][curX]+nw;
                PQ.push({d[ny][nx],ny,nx});
            }
        }
    }
    return 0;
}
