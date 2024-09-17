//상근이를 진출시키기 위해 간선을 추가해주는 아이디어가 신박했다.
//true -> 진출
//false -> 탈락

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N, M;
vector<vector<int>> adj;
stack<int> stk;
vector<int> order;
vector<int> SccNum;

int oppose(int n){
    if(n <= N) return n+N;
    else return n-N;
}

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
            if(x == cur) break;
        }
        sccCnt++;
    }
    return ret;
}

void solve(){
    adj.clear(); adj.resize(N*2+1);
    order.clear(); order.resize(N*2+1, -1);
    SccNum.clear(); SccNum.resize(N*2+1, -1);
    orderCnt = sccCnt = 0;

    for(int i=0; i<M; i++){
        int u,v; cin>>u>>v;
        if(u<0) u = oppose(-u);
        if(v<0) v = oppose(-v);
        adj[oppose(u)].push_back(v);
        adj[oppose(v)].push_back(u);
    }
    adj[oppose(1)].push_back(1); //상근이를 무조건 합격시키기 위해 1v1 간선을 추가해준다.

    for(int i=1; i<=2*N; i++){
        if(order[i]==-1) SCC(i);
    }

    for(int i=1; i<=N; i++){
        if(SccNum[i] == SccNum[i+N]){
            cout<<"no\n";
            return;
        }
    }
    cout<<"yes\n";
    return;
}   

int main(){
    fastio;
    while(cin>>N>>M){
        solve();
    }
    return 0;
}
