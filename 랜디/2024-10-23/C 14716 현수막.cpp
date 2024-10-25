#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int dy[] = {1, 1, 1, 0, -1, -1, -1, 0};
int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main(){
    fastio;
    int N, M; cin>>N>>M;
    vector<vector<char>> board(N, vector<char>(M));
    vector<vector<bool>> vis(N, vector<bool>(M));
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin>>board[i][j];
    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(vis[i][j] || board[i][j]=='0') continue;
            queue<pair<int,int>> Q;
            Q.push({i,j}); vis[i][j]=true;
            while(!Q.empty()){
                auto[curY, curX]=Q.front(); Q.pop();
                for(int dir=0; dir<8; dir++){
                    int ny = curY+dy[dir];
                    int nx = curX+dx[dir];
                    if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
                    if(board[ny][nx]=='0' || vis[ny][nx]) continue;
                    vis[ny][nx] = true;
                    Q.push({ny,nx});
                }
            }
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
