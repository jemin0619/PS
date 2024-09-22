//모든 *에 대해서 상하좌우에 길이 x의 *이 존재하는지 확인
//최적해를 구하지 않아도 되므로 다 넣고 봄

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};

int N, M;
int board[103][103];
bool vis[103][103];

int getDist(int y, int x, int dir){
    int ret = 0;
    while(true){
        y += dy[dir];
        x += dx[dir];
        if(y<0 || x<0 || y>=N || x>=M) break;
        if(board[y][x]==0) break;
        ret++;
    }
    return ret;
}

int main(){
    fastio;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char c; cin>>c;
            if(c=='*') board[i][j] = 1;
            else board[i][j] = 0;
        }
    }

    vector<tuple<int,int,int>> ans;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(board[i][j]==0) continue;
            int U = getDist(i, j, 2);
            int D = getDist(i, j, 0);
            int R = getDist(i, j, 1);
            int L = getDist(i, j, 3);
            int mn = min({U, D, R, L});
            if(mn==0) continue;
            vis[i][j] = true;
            for(int dir=0; dir<4; dir++){
                int ny = i; 
                int nx = j;
                for(int k=0; k<mn; k++){
                    ny += dy[dir];
                    nx += dx[dir];
                    vis[ny][nx] = true;
                }
            }
            ans.push_back({i, j, mn});
        }
    }

    bool fin = true;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(board[i][j]==1){
                if(vis[i][j]==false){
                    cout<<-1;
                    return 0;
                }
            }
        }
    }
    cout<<ans.size()<<'\n';
    for(auto[a,b,c] : ans){
        cout<<a+1<<' '<<b+1<<' '<<c<<'\n';
    }
    return 0;
}
