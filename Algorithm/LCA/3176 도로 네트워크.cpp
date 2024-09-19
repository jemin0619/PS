//처음에 문제를 잘못 이해하고, 간선을 포개어 놓아도 되고, 거기에서 최단, 최대거리를 구하는 것인 줄 알았는데 아니었다.
//그냥 단순히 두 도시를 잇는 도로들 중에서 가장 길이가 짧은 도로와 가장 길이가 긴 도로를 구하는 것이었다.
//LCA + Sparse Table로 해결할 수 있다.

//마지막에 한 칸 올리는 과정에서 u만 올리고, H[0][u]로만 Mn, Mx를 업데이트해줘서 한동안 문제를 찾았었다.
//v도 한 칸 올라가야 두 노드 모두 LCA에 도달하기에 H[0][v]도 Mn, Mx를 업데이트하는데 써야 한다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define pii pair<ll,ll>

struct Data{
    ll node, mn, mx;
};

int N;
vector<vector<pii>> adj;
vector<vector<Data>> H;
vector<int> depth;

void DFS(int cur, int dep){
    depth[cur] = dep;
    for(auto[nxt, weight] : adj[cur]){
        if(depth[nxt]!=-1) continue;
        H[0][nxt].node = cur;
        H[0][nxt].mn = H[0][nxt].mx = weight;
        DFS(nxt, dep+1);
    }
}

int main(){
    fastio;
    cin>>N;
    adj.resize(N+3);
    depth.resize(N+3, -1);
    H.resize(18, vector<Data>(N+3));
    for(int i=1; i<N; i++){
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    DFS(1, 0);

    for(int bit=1; bit<=17; bit++){
        for(int i=1; i<=N; i++){
            H[bit][i].node = H[bit-1][H[bit-1][i].node].node;
            H[bit][i].mn = min(H[bit-1][H[bit-1][i].node].mn, H[bit-1][i].mn);
            H[bit][i].mx = max(H[bit-1][H[bit-1][i].node].mx, H[bit-1][i].mx);
        }
    }
    int M; cin>>M;
    while(M--){
        int u,v; cin>>u>>v;
        if(depth[u]<depth[v]) swap(u, v);

        ll Mx=-1, Mn=0x7f7f7f7f;
        ll diff = depth[u] - depth[v];
        for(int i=17; i>=0; i--){
            if(diff&(1LL<<i)){
                Mx = max(Mx, H[i][u].mx);
                Mn = min(Mn, H[i][u].mn);
                u = H[i][u].node;
            }
        }

        if(u != v){
            for(int i=17; i>=0; i--){
                if(H[i][u].node!=0 && H[i][u].node!=H[i][v].node){
                    Mn = min({Mn, H[i][u].mn, H[i][v].mn});
                    Mx = max({Mx, H[i][u].mx, H[i][v].mx});
                    u = H[i][u].node;
                    v = H[i][v].node;
                }
            }
            Mn = min({Mn, H[0][u].mn, H[0][v].mn});
            Mx = max({Mx, H[0][u].mx, H[0][v].mx});
            u = H[0][u].node;
            v = H[0][v].node;
        }

        cout<<Mn<<' '<<Mx<<'\n';
    }
    return 0;
}
