//보자마자 단절점이 떠올랐다.
//N이 작아서 단절점 알고리즘 없이도 풀 수 있겠지만 단절점으로 풀어보려고 한다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};

int N;
vector<string> board;
vector<vector<int>> order;
vector<pair<int,int>> ans;

int orderCnt = 0;
int DFS(int curY, int curX, bool isRoot){
    int ret = order[curY][curX] = orderCnt++;
    int child = 0;
    for(int dir=0; dir<4; dir++){
        int ny = curY + dy[dir];
        int nx = curX + dx[dir];
        if(ny<0 || nx<0 || ny>=N || nx>=N) continue;
        if(board[ny][nx]!='.') continue;

        if(order[ny][nx]!=-1) ret = min(ret, order[ny][nx]);
        else{
            int earliest = DFS(ny, nx, false);
            if(earliest >= order[curY][curX] && !isRoot) ans.push_back({curY, curX});
            ret = min(ret, earliest);
            child++;
        }
    }
    if(isRoot && child>=2) ans.push_back({curY, curX});
    return ret;
}

int main(){
    fastio;
    cin>>N;
    board.resize(N);
    order.resize(N, vector<int>(N, -1));
    for(int i=0; i<N; i++) cin>>board[i];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(board[i][j]=='.' && order[i][j]==-1) DFS(i, j, true);
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout<<ans.size()<<'\n';
    //for(auto[y,x] : ans) cout<<y<<' '<<x<<'\n';
    return 0;
}
