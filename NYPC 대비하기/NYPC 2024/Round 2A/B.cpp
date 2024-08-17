//WA
//Subtask 1,2만 노려서 대각선 없이 y, x축에 대한 수평선만 고려했다.
//BFS + Union Find로 접근했는데 왜 틀리는지 모르겠음...
//BIKO에 올라오면 다시 풀어보기

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

ll N, M, Q;

// Union Find
ll coord(ll y, ll x) { return N * (y - 1) + x; }
vector<ll> parent;
ll find(ll u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}
void merge(ll u, ll v) {
    u = find(u); v = find(v);
    if (u == v) return;
    parent[v] = u;
}

int board[2003][2003];
bool vis[2003][2003];
ll dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
ll dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    fastio;
    memset(board, 0, sizeof(board));
    memset(vis, false, sizeof(vis));
    cin >> N >> M >> Q;

    // Union Find init
    parent.resize((N + 1) * (N + 1));
    iota(parent.begin(), parent.end(), 0);
    
    while(M--){
        //y, x (1-indexed)
        //레이저는 무한히 긴 직선임
        ll r1,c1,r2,c2; cin>>r1>>c1>>r2>>c2;
        if(r1==r2){
            board[r1][1]=1; board[r1][N+1]=-1;
            board[r1+1][1]=-1; board[r1+1][N+1]=1;
        }
        else if(c1==c2){
            board[1][c1]=1; board[N+1][c1]=-1;
            board[1][c1+1]=-1; board[N+1][c1+1] = 1;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 2; j <= N; j++) {
            board[i][j] += board[i][j - 1];
            //board[i][j] = min(1LL, board[i][j]);
        }
    }
    for (int j = 1; j <= N; j++) {
        for (int i = 2; i <= N; i++) {
            board[i][j] += board[i - 1][j];
            //board[i][j] = min(1LL, board[i][j]);
        }
    }

    while (Q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (board[a][b] != 0 || board[c][d] != 0) {
            cout << "0\n"; 
            continue;
        }
        memset(vis, false, sizeof(vis));
        queue<pair<int, int>> que;
        que.push({a, b});
        vis[a][b] = true;
        bool flag = false;
        while (!que.empty()) {
            auto [y, x] = que.front(); que.pop();
            if(y==c && x==d) {flag = true; break;}
            for (int dir = 0; dir < 8; dir++) {
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
                if (vis[ny][nx] || board[ny][nx] > 0) continue;
                vis[ny][nx] = true;
                que.push({ny, nx});
            }
        }
        cout<<flag<<'\n';
    }

    return 0;
}
