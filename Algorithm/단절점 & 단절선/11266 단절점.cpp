#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

vector<int> adj[10'003];
vector<int> order;
vector<int> ans;

int orderCnt = 0;
int DFS(int cur, bool isRoot){
    order[cur] = orderCnt++;
    int ret = order[cur];
    int child = 0;
    for(int nxt : adj[cur]){
        if(order[nxt]!=-1) ret = min(ret, order[nxt]);
        else{
            int earliest = DFS(nxt, false);
            if(earliest >= order[cur] && !isRoot) ans.push_back(cur);
            ret = min(ret, earliest);
            child++;
        }
    }
    if(isRoot && child>=2) ans.push_back(cur);
    return ret;
}

int main(){
    fastio;
    int V,E; cin>>V>>E;
    order.resize(V+3, -1);

    for(int i=0; i<E; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=1; i<=V; i++){
        if(order[i]!=-1) continue;
        DFS(i, true);
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    cout<<ans.size()<<'\n';
    for(int val : ans) cout<<val<<' ';
    return 0;
}
