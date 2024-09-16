#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

vector<ll> cost;
vector<ll> adj[103];
vector<ll> order;
vector<ll> SccNum;
stack<ll> stk;
ll ans = 0;

ll sccCnt = 0;
ll orderCnt = 0;
ll SCC(ll cur){
    stk.push(cur);
    order[cur] = orderCnt++;
    ll ret = order[cur];
    for(int nxt : adj[cur]){
        if(order[nxt]==-1) ret = min(ret, SCC(nxt)); //방문하지 않았으면 방문함
        else if(SccNum[nxt]==-1) ret = min(ret, order[nxt]); //방문했었는데 아직 SCC 판별이 안난 경우
    }

    ll mnCost = 0x7f7f7f7f;
    if(ret == order[cur]){
        while(true){
            int x = stk.top();
            stk.pop();
            SccNum[x] = sccCnt;
            mnCost = min(mnCost, cost[x]);
            if(x==cur) break;
        }
        sccCnt++;
    }
    if(mnCost!=0x7f7f7f7f) ans += mnCost;
    return ret;
}

int main(){
    fastio;
    int N; cin>>N;
    cost.resize(N+3);
    order.resize(N+3, -1);
    SccNum.resize(N+3, -1);
    for(int i=1; i<=N; i++) cin>>cost[i];
    for(int i=1; i<=N; i++){
        string S; cin>>S;
        for(int j=1; j<=N; j++){
            if(S[j-1]=='1') adj[i].push_back(j);
        }
    }
    for(int i=1; i<=N; i++){
        if(order[i] != -1) continue;
        SCC(i);
    }
    cout<<ans;
    return 0;
}
