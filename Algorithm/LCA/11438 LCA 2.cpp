#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    int N; cin>>N;
    vector<vector<int>> H(18, vector<int>(N+3));
    vector<int> adj[N+3];
    vector<int> depth(N+3, -1);

    for(int i=0; i<N-1; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<pair<int,int>> Q;
    Q.push({1, 0});
    while(!Q.empty()){
        auto[cur, D] = Q.front(); Q.pop();
        depth[cur] = D;
        for(int nxt : adj[cur]){
            if(depth[nxt]!=-1) continue;
            Q.push({nxt, D+1});
            H[0][nxt] = cur;
        }
    }

    for(int i=1; i<=17; i++)
        for(int j=1; j<=N; j++)
            H[i][j] = H[i-1][H[i-1][j]];

    int M; cin>>M;
    while(M--){
        int u,v; cin>>u>>v;
        if(depth[u]<depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];

        for(int i=0; i<=17; i++)
            if(diff&(1<<i)) u = H[i][u];
        
        if(u != v){
            for(int i=17; i>=0; i--){
                if(H[i][u]!=0 && H[i][u]!=H[i][v]){
                    u = H[i][u];
                    v = H[i][v];
                }
            }
            u = H[0][u];
        }
        cout<<u<<'\n';
    }
    return 0;
}
