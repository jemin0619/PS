//1번 방을 제외한 방들이 올라가는 모양으로 구성되어 있을수도 있음
//그러므로 depth에 따라 내려가는 방향으로 간선을 맞춰주고, sparse table을 구성해줘야 함
//sparse table은 {정점, 비용}으로 구성함

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll N;
vector<ll> Energy;
vector<vector<pair<ll,ll>>> H; //Sparse Table
vector<vector<pair<ll,ll>>> adj;
vector<int> depth;

void DFS(int cur, int dep){
    depth[cur] = dep;
    for(auto[nxt, weight] : adj[cur]){
        if(depth[nxt]!=-1) continue;
        H[0][nxt] = {cur, weight};
        DFS(nxt, dep+1);
    }
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    cin>>N;
    Energy.resize(N+3);
    adj.resize(N+3);
    depth.resize(N+3, -1);
    H.resize(18, vector<pair<ll,ll>>(N+3));
    for(int i=1; i<=N; i++) cin>>Energy[i];
    for(int i=1; i<N; i++){
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    DFS(1, 0);

    for(int bit=1; bit<=17; bit++)
        for(int i=1; i<=N; i++)
            H[bit][i] = {H[bit-1][H[bit-1][i].ff].ff, H[bit-1][i].ss + H[bit-1][H[bit-1][i].ff].ss};

    for(int i=1; i<=N; i++){
        int cur = i;
        for(int bit=17; bit>=0; bit--){
            if(Energy[i]>=H[bit][cur].ss && H[bit][cur].ff!=0){
                Energy[i] -= H[bit][cur].ss;
                cur = H[bit][cur].ff;
            }
        }
        cout<<cur<<'\n';
    }
    return 0;
}
