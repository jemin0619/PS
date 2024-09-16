//문제: 각 SCC를 한 정점으로 치환시켜서 그래프를 구성했을 때, Indegree가 없는 SCC의 개수를 구하여라
//SCC 테이블 채운 후, 모든 정점들을 돌면서 그 정점들의 outdegree를 살핀다.
//그 중 자신과 다른 SCC에 속하는 정점이 있다면 그 SCC에 indegree가 존재한다고 표시해준다.
//마지막에 indegree가 없는 SCC의 개수를 구하고 출력한다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int N, M;
vector<int> adj[100'003];
vector<int> order;
vector<int> SccNum;
stack<int> stk;

int sccCnt = 0;
int orderCnt = 0;
int SCC(int cur){
    stk.push(cur);
    order[cur] = orderCnt++;
    int ret = order[cur];
    for(int nxt : adj[cur]){
        if(order[nxt]==-1) ret = min(ret, SCC(nxt));
        else if(SccNum[nxt]==-1) ret = min(ret, order[nxt]);
    }
    if(ret==order[cur]){
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
    order.resize(N+3, -1);
    SccNum.resize(N+3, -1);
    for(int i=1; i<=M; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
    }

    for(int i=1; i<=N; i++){
        if(order[i]!=-1) continue;
        SCC(i);
    }

    vector<int> indegree(sccCnt+3);
    for(int i=1; i<=N; i++){
        for(int nxt : adj[i]){
            if(SccNum[i] != SccNum[nxt]) indegree[SccNum[nxt]]=1;
        }   
    }
    int ans = 0;
    for(int i=0; i<sccCnt; i++){
        if(indegree[i]==0) ans++;
    }
    cout<<ans;
    return 0;
}
