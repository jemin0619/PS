//한 라운드마다 공격 -> 수비 반복
//라운드마다 넘어뜨린 도미노 개수 세고, 그 개수가 그 라운드의 점수가 됨
//N, M이 컸다면 느갱세 혹은 펜윅 트리로 구간 쿼리를 처리해야 했을 것 같다.

//09:27 WA 
//큐에 모든 값을 저장하다보니 MLE가 났다.
//그래서 큐에 꼭 필요한 값들 (가장 많은 구간을 커버할 수 있는 도미노) 만 넣어놓으면 될 것 같았다.

//10:15 AC
//큐에 필요한 값만 저장하니 AC를 받았다.
//큐에서 pop을 한 뒤, board[curY][curX]가 0이더라도 계속 탐색해야 한다. 
//N, M이 작아 최적화를 시키지 않았으므로 큐에 들어온 원소 자리가 0일 수도 있다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define xx first 
#define yy second

int N, M, K;
int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};

int solve(vector<vector<int>>&board, vector<vector<int>>&original, int Y, int X, char D){
    int ret = 0;
    int dir = (D=='E')?1:((D=='W')?3:((D=='S')?0:2));
    queue<tuple<int,int,int>> Q;
    Q.push({Y, X, board[Y][X]});
    while(!Q.empty()){
        auto[curY, curX, curD] = Q.front(); Q.pop();
        int mx = -1, mx_y, mx_x;
        for(int i=0; i<curD; i++){
            int ny = curY + dy[dir]*i;
            int nx = curX + dx[dir]*i;
            if(ny<0 || nx<0 || ny>=N || nx>=M) break;
            if(board[ny][nx]==0) continue;
            if(mx<board[ny][nx]+i){
                mx = board[ny][nx]+i;
                mx_y = ny;
                mx_x = nx;
            }
            ret++;
            board[ny][nx] = 0;
        }
        if(mx==-1) continue;
        Q.push({mx_y, mx_x, original[mx_y][mx_x]});
    }
    return ret;
}

int main(){
    fastio;
    vector<vector<int>> board;
    cin>>N>>M>>K;
    board.resize(N, vector<int>(M));
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin>>board[i][j];
    vector<vector<int>> original(board);
    int sc = 0;
    while(K--){
        int y,x; char d; cin>>y>>x>>d; y--; x--;

        sc += solve(board, original, y, x, d);

        int a, b; cin>>a>>b; a--; b--;
        board[a][b] = original[a][b];
    }
    cout<<sc<<'\n';
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(board[i][j]==0) cout<<"F ";
            else cout<<"S ";
        } cout<<'\n';
    }
    return 0;
}
