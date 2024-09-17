#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N, M;
vector<int> adj[20'003];
vector<int> order(20'003, -1);
vector<int> SccNum(20'003, -1);
stack<int> stk;

int Oppose(int num){
    if(num>N) return num-N; //num>N 이면 num은 not인 노드임
    else return num+N; //num<=N 이면 num은 not이 아닌 노드임
}

int sccCnt = 0;
int orderCnt = 0;
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

int main(){
    fastio;
    cin>>N>>M;
    while(M--){
        int u,v; cin>>u>>v;
        if(u<0) u = Oppose(abs(u));
        if(v<0) v = Oppose(abs(v));
        adj[Oppose(u)].push_back(v);
        adj[Oppose(v)].push_back(u);
    }
    for(int i=1; i<=2*N; i++){
        if(order[i]==-1) SCC(i);
    }
    for(int i=1; i<=N; i++){
        if(SccNum[i]==SccNum[i+N]){
            cout<<"0";
            return 0;
        }
    }
    cout<<"1";
    return 0;
}
