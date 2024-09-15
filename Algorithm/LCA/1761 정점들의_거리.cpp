//트리이므로 각 쿼리가 주어질 때마다 u와 v의 LCA를 구하고, 그 LCA로부터 u, v와의 거리 합을 출력하면 된다.
//처음에 틀려서 두 정점간 LCA가 두 정점 중 하나일 때 case work를 해야 한다고 생각했는데, 그럴 필요는 없었다.
//스파스 테이블을 채우는 서순이 문제였다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define pii pair<ll,ll>
#define ff first
#define ss second

int main(){
    fastio;
    ll N; cin>>N;
    vector<vector<int>> H(17, vector<int>(N+3));
    vector<ll> depth(N+3, -1);
    vector<pii> adj[N+3];
    vector<ll> dist(N+3);

    for(int i=1; i<N; i++){
        ll u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    //임의로 1번 노드를 루트로 정함
    dist[1] = 0;
    queue<pair<int, int>> Q;
    Q.push({1, 0});
    while(!Q.empty()){
        auto[cur, D] = Q.front(); Q.pop();
        depth[cur] = D;
        for(auto&[nxt, nw] : adj[cur]){
            if(depth[nxt]!=-1) continue;
            Q.push({nxt, D+1});
            H[0][nxt] = cur;
            dist[nxt] = dist[cur]+nw;
        }
    }

    for(int i=1; i<=16; i++)
        for(int j=1; j<=N; j++)
            H[i][j] = H[i-1][H[i-1][j]];

    ll M; cin>>M;
    while(M--){
        ll u,v; cin>>u>>v;

        if(depth[u]<depth[v]) swap(u,v);
        ll diff = depth[u] - depth[v];
        ll N1=u, N2=v;

        for(int i=16; i>=0; i--){
            if(diff&(1LL<<i)){
                u = H[i][u];
            }
        }

        if(u != v){
            for(int i=16; i>=0; i--){
                if(H[i][u]!=0 && H[i][u]!=H[i][v]){
                    u = H[i][u];
                    v = H[i][v];
                }
            }
            u = H[0][u];
        }
        ll ans = dist[N1]+dist[N2]-(dist[u]*2);
        cout<<ans<<'\n';
    }
    return 0;
}
