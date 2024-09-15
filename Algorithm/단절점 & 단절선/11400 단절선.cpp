//단절점과 달리 이상이 아니라 초과를 사용한다.
//DFS에서 parent 확인을 안해주면 WA가 난다.
//단절점에선 안해도 됐는데 여기선 꼭 해야한다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int V,E;
vector<int> adj[100'003];
vector<int> order;
vector<pair<int,int>> ans;

int orderCnt = 0;
int DFS(int cur, int pa){
    order[cur] = ++orderCnt;
    int ret = order[cur];
    for(int nxt : adj[cur]){
        if(nxt==pa) continue;
        if(order[nxt]!=-1) ret = min(ret, order[nxt]);
        else{
            int earliest = DFS(nxt, cur);
            if(earliest>order[cur]) ans.push_back({min(cur, nxt), max(cur, nxt)});
            ret = min(ret, earliest);
        }
    }
    return ret;
}

int main(){
    fastio;
    cin>>V>>E;
    order.resize(V+3, -1);
    for(int i=0; i<E; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=V; i++){
        if(order[i]!=-1) continue;
        DFS(i, -1);
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    
    cout<<ans.size()<<'\n';
    for(auto[u,v]:ans) cout<<u<<' '<<v<<'\n';
    return 0;
}
