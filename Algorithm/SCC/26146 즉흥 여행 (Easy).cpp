//Scc 번호가 0만 존재한다면 true이다.
//지금 생각해보니 sccCnt가 1이라면 true로 볼 수도 있겠다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

vector<int> order;
vector<int> SccNum;
vector<vector<int>> adj;
stack<int> stk;
int orderCnt = 0;
int sccCnt = 0;

int SCC(int cur){
    stk.push(cur);
    int ret = order[cur] = orderCnt++;
    for(int nxt : adj[cur]){
        if(order[nxt]==-1) ret = min(ret, SCC(nxt));
        else if(SccNum[nxt]==-1) ret = min(ret, order[nxt]);
    }
    if(ret == order[cur]){
        while(true){
            int x = stk.top(); stk.pop();
            SccNum[x] = sccCnt;
            if(x==cur) break;
        }
        sccCnt++;
    }
    return ret;
}

int main(){
    fastio;
    int N, M; cin>>N>>M;
    adj.resize(N+3);
    order.resize(N+3, -1);
    SccNum.resize(N+3, -1);
    while(M--){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1; i<=N; i++){
        if(order[i]==-1) SCC(i);
    }

    int idx=1;
    while(idx<=N && SccNum[idx]==0) idx++;
    if(idx==N+1) cout<<"Yes";
    else cout<<"No";
    return 0;
}
