//단절점들은 답이 될 수 없으므로 단절점부터 제외하고 시작한다.
//단절점을 제외한 정점 중, 그 정점을 제거했을 때 트리가 되면 그 정점은 답이라고 할 수 있다.
//트리가 된다는 말은 V-1 = E라는 의미이므로 해당 정점을 제거했을 때 저 조건을 만족해야 한다.
//그 정점을 제거했을 때 같이 사라질 간선의 개수를 저장해두면 각 칸마다 O(1)에 해당 칸이 답이 되는지 판별할 수 있다.

//처음에 y, x 순서로 출력해야하는데 반대로 해서 틀렸다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

ll dy[] = {1, 0, -1, 0};
ll dx[] = {0, 1, 0, -1};

ll N;
vector<string> board;
vector<vector<ll>> edges;
ll edgeCnt = 0;
ll nodeCnt = 0;

#pragma region 
vector<vector<ll>> order;
vector<vector<bool>> artic;
ll orderCnt = 0;
ll DFS(ll curY, ll curX,  bool isRoot){
    order[curY][curX] = orderCnt++;
    ll ret = order[curY][curX];
    ll child = 0;
    for(int dir=0; dir<4; dir++){
        ll ny = curY + dy[dir];
        ll nx = curX + dx[dir];
        if(ny<0 || nx<0 || ny>=N || nx>=N) continue;
        if(board[ny][nx]=='.') continue;
        edgeCnt++;
        edges[curY][curX]++;
        if(order[ny][nx]!=-1) ret = min(ret, order[ny][nx]);
        else{
            ll earliest = DFS(ny, nx, false);
            if(earliest >= order[curY][curX] && !isRoot) artic[curY][curX] = true;
            ret = min(ret, earliest);
            child++;
        }
    }
    if(isRoot && child>=2) artic[curY][curX] = true;
    return ret;
}
#pragma endregion


int main(){
    fastio;
    cin>>N; 
    board.resize(N);
    order.resize(N+3, vector<ll>(N+3, -1));
    edges.resize(N+3, vector<ll>(N+3, 0));
    artic.resize(N+3, vector<bool>(N+3, false));
    for(int i=0; i<N; i++) cin>>board[i];

    //단절점 판별
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(board[i][j]=='#') nodeCnt++;
            if(board[i][j]=='#' && order[i][j]==-1) DFS(i, j, true); 
        }
    }

    edgeCnt /= 2; //총 간선 수

    vector<pair<ll,ll>> ans;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(artic[i][j] || board[i][j]=='.') continue;
            int val = nodeCnt-1;
            if(nodeCnt-2 == edgeCnt-edges[i][j]) ans.push_back({i+1,j+1});
        } 
    }

    sort(ans.begin(), ans.end());
    cout<<ans.size()<<'\n';
    for(auto[a,b] : ans){
        cout<<a<<' '<<b<<'\n';
    }
    return 0;
}
