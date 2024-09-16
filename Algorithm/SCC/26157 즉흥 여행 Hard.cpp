//위상정렬이 오랜만이라 잘못 생각하던 점이 있는데, 위상정렬의 결과가 유일한 것과 indegree의 개수는 관계가 없다.
//관련이 없다고 하는 것은, indegree의 최대값을 1로 두어도 결과가 제대로 나온다고 생각했단 것이다.
//결과가 유일하려면 매 순간 큐에 들어있는 원소의 개수가 2개 이상이면 안된다.

//1 -> 2
//1 -> 3
//2 -> 3
//위의 경우, 1 -> 2 -> 3이 존재한다.
//이 경로가 유일한데, indegree의 개수가 2인 정점이 있는데도 유일한 경로를 뽑아낼 수 있다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int V,E;
vector<int> adj[200'003];
vector<int> order(200'003, -1);
vector<int> SccNum(200'003, -1);
vector<vector<int>> Sccs; //i번 Scc에 속하는 정점들
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
    if(ret==order[cur]){
        vector<int> tmp;
        while(true){
            int x = stk.top(); stk.pop();
            SccNum[x] = sccCnt;
            tmp.push_back(x);
            if(x==cur) break;
        }
        Sccs.push_back(tmp);
        sccCnt++;
    }
    return ret;
}

int main(){
    fastio;
    cin>>V>>E;
    while(E--){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1; i<=V; i++){
        if(order[i]==-1) SCC(i);
    }

    //SCC들을 정점으로 치환하여 DAG 생성
    vector<int> DAG[sccCnt+3];
    vector<int> indegree(sccCnt+3);
    for(int i=1; i<=V; i++){
        for(int nxt : adj[i]){
            if(SccNum[i] != SccNum[nxt]){
                //이렇게 두면 중복되는 간선이 생길 수 있는데, 위상정렬을 수행하므로 문제가 안됨.
                indegree[SccNum[nxt]]++;
                DAG[SccNum[i]].push_back(SccNum[nxt]);
            }
        }
    }

    queue<int> Q;
    int stScc = -1;
    for(int i=0; i<sccCnt; i++){
        if(indegree[i]==0){
            Q.push(i);
            stScc = i;
        }
    }
    while(!Q.empty()){
        if(Q.size()>=2){
            cout<<0;
            return 0;
        }
        int cur = Q.front(); Q.pop();
        for(int nxt : DAG[cur]){
            if(--indegree[nxt]==0) Q.push(nxt);
        }
    }

    sort(Sccs[stScc].begin(), Sccs[stScc].end());
    cout<<Sccs[stScc].size()<<'\n';
    for(int val : Sccs[stScc]){
        cout<<val<<' ';
    }
    return 0;
}
