//정답 출력을 어떻게 구현할지 고민했는데 간단했다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int V,E;
vector<int> adj[10'003];
vector<int> order;
vector<int> SCCnum;
stack<int> stk;
vector<vector<int>> ans;

int orderCnt = 0;
int sccCnt = 0;
int SCC(int cur){
    order[cur] = orderCnt++;
    int ret = order[cur];
    stk.push(cur);

    for(int nxt : adj[cur]){
        if(order[nxt]==-1) ret = min(ret, SCC(nxt));
        else if(SCCnum[nxt]==-1) ret = min(ret, order[nxt]);
    }

    vector<int> temp;
    if(ret == order[cur]){
        while(true){
            int tmp = stk.top();
            stk.pop();
            temp.push_back(tmp);
            SCCnum[tmp] = sccCnt;
            if(tmp == cur) break;
        }
        sccCnt++;
    }
    if(!temp.empty()){
        sort(temp.begin(), temp.end());
        ans.push_back(temp);
    }

    return ret;
}

int main(){
    fastio;
    cin>>V>>E;
    order.resize(V+3, -1);
    SCCnum.resize(V+3, -1);
    for(int i=0; i<E; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1; i<=V; i++){
        if(order[i] != -1) continue;
        SCC(i);
    }

    sort(ans.begin(), ans.end());
    cout<<ans.size()<<'\n';
    for(int i=0; i<ans.size(); i++){
        for(int val : ans[i]){
            cout<<val<<' ';
        } cout<<"-1\n";
    }
    return 0;
}
