//느낌대로 구현했는데 AC를 받았다.
//BOJ에 Sparse Table 문제인 개미와 비슷한 느낌을 받았다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N;
vector<vector<int>> adj;
vector<vector<int>> H;
vector<int> depth;

void DFS(int cur, int dep){
    depth[cur] = dep;
    for(int nxt : adj[cur]){
        if(depth[nxt]!=-1) continue;
        H[0][nxt] = cur;
        DFS(nxt, dep+1);
    }
}

int main(){
    fastio;
    cin>>N;
    adj.resize(N+3);
    depth.resize(N+3, -1);
    H.resize(16, vector<int>(N+3));
    for(int i=1; i<N; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, 0);
    for(int bit=1; bit<=15; bit++)
        for(int i=1; i<=N; i++)
            H[bit][i] = H[bit-1][H[bit-1][i]];
    int M; cin>>M;
    int cur = 1;
    long long ans = 0;
    while(M--){
        int nxt; cin>>nxt;
        
        int u = cur, v = nxt;
        if(depth[u]<depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for(int i=15; i>=0; i--){
            if(diff&(1<<i)) u = H[i][u];
        }
        if(u != v){
            for(int bit=15; bit>=0; bit--){
                if(H[bit][u]!=0 && H[bit][u]!=H[bit][v]){
                    u = H[bit][u];
                    v = H[bit][v];
                }
            }
            u = H[0][u];
        }
        ans += (depth[cur]+depth[nxt]-2*depth[u]);

        cur = nxt;
    }
    cout<<ans;
    return 0;
}
