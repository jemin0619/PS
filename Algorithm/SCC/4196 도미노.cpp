#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

vector<vector<int>> adj;
vector<int> order;
vector<int> SCCnum;
stack<int> stk;
int sccCnt = 0;
int orderCnt = 0;

int SCC(int cur){
    stk.push(cur);
    order[cur] = orderCnt++;
    int ret = order[cur];
    for(int nxt : adj[cur]){
        if(order[nxt]==-1) ret = min(ret, SCC(nxt));
        else if(SCCnum[nxt]==-1) ret = min(ret, order[nxt]);
    }
    if(ret == order[cur]){
        while(true){
            int x = stk.top(); stk.pop();
            SCCnum[x] = sccCnt;
            if(x==cur) break;
        } 
        sccCnt++;
    }
    return ret;
}

int main(){
    fastio;
    int tc; cin>>tc;
    while(tc--){
        int N,M; cin>>N>>M;
        adj.clear(); adj.resize(N+3);
        order.clear(); order.resize(N+3, -1);
        SCCnum.clear(); SCCnum.resize(N+3, -1);
        sccCnt = 0;
        orderCnt = 0;
        while(M--){
            int u,v; cin>>u>>v;
            adj[u].push_back(v);
        }
        for(int i=1; i<=N; i++){
            if(order[i] != -1) continue;
            SCC(i);
        }
        vector<int> indegree(sccCnt+3);
        for(int i=1; i<=N; i++){
            for(int nxt : adj[i]){
                if(SCCnum[i] != SCCnum[nxt]){
                    indegree[SCCnum[nxt]] = 1;
                }
            }
        }  
        int ans = 0;
        for(int i=0; i<sccCnt; i++){
            if(indegree[i]==0) ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
