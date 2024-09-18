//간선을 case work로 연결해야 할 줄 알았는데, 조건들을 다 살펴보니 다른 문제와 똑같이 u v가 입력되면 u or v한 것이었다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N, M;
vector<int> order;
vector<int> SccNum;
vector<vector<int>> adj;
stack<int> stk;
int orderCnt, sccCnt;

int oppose(int n){
    if(n<=N) return n+N;
    else return n-N;
}

int SCC(int cur){
    stk.push(cur);
    int ret = order[cur] = orderCnt++;
    for(int nxt : adj[cur]){
        if(order[nxt]==-1) ret = min(ret, SCC(nxt));
        else if(SccNum[nxt]==-1) ret = min(ret, order[nxt]);
    }
    if(ret == order[cur]){
        while(1){
            int x = stk.top(); stk.pop();
            SccNum[x] = sccCnt;
            if(x==cur) break;
        }
        sccCnt++;
    }
    return ret;
}

void solve(){
    order.clear(); order.resize(N*2+3, -1);
    SccNum.clear();  SccNum.resize(N*2+3, -1);
    adj.clear(); adj.resize(N*2+3);
    orderCnt = sccCnt = 0;
    for(int i=0; i<M; i++){
        int u,v; cin>>u>>v;
        if(u<0) u = oppose(-u);
        if(v<0) v = oppose(-v);
        adj[oppose(u)].push_back(v);
        adj[oppose(v)].push_back(u);
    }
    for(int i=1; i<=2*N; i++){
        if(order[i]==-1) SCC(i);
    }
    for(int i=1; i<=N; i++){
        if(SccNum[i]==SccNum[i+N]){
            cout<<"0\n";
            return;
        }
    }
    cout<<"1\n";
    return;
}

int main(){
    fastio;
    while(cin>>N>>M){
        solve();
    }
    return 0;
}
