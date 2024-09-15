//티어를 보면 알 수 있겠지만, 애드혹이다.
//연습할겸 단절점 & 단절선 알고리즘으로 풀었다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N;
vector<int> adj[100'003];
vector<pair<int,int>> edges;
vector<int> order1, order2;

vector<int> ArticulationPoint;

map<pair<int,int>,bool> Bridge;

int orderCnt = 0;
int DFS1(int pa, int cur, bool isRoot){
    order1[cur] = ++orderCnt;
    int ret = order1[cur];
    int child = 0;
    for(int nxt : adj[cur]){
        if(nxt==pa) continue;
        if(order1[nxt]!=-1) ret = min(ret, order1[nxt]);
        else{
            int earliest = DFS1(cur, nxt, false);
            if(earliest>=order1[cur]&&!isRoot) ArticulationPoint.push_back(cur);
            ret = min(ret, earliest);
            child++;
        }
    }
    if(isRoot && child>=2) ArticulationPoint.push_back(cur);
    return ret;
}

int DFS2(int pa, int cur){
    order2[cur] = ++orderCnt;
    int ret = order2[cur];
    for(int nxt : adj[cur]){
        if(nxt==pa) continue;
        if(order2[nxt]!=-1) ret = min(ret, order2[nxt]);
        else{
            int earliest = DFS2(cur, nxt);
            if(earliest > order2[cur]) Bridge[{min(cur,nxt),max(cur,nxt)}] = true;
            ret = min(ret, earliest);
        }
    }
    return ret;
}

int main(){
    fastio;
    cin>>N;
    order1.resize(N+3, -1);
    order2.resize(N+3, -1);
    edges.resize(N+3);
    for(int i=1; i<N; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = {min(u,v), max(u,v)};
    }

    for(int i=1; i<=N; i++){
        if(order1[i]!=-1) continue;
        DFS1(-1, i, true);
    }
    orderCnt = 0;
    for(int i=1; i<=N; i++){
        if(order2[i]!=-1) continue;
        DFS2(-1, i);
    }   

    sort(ArticulationPoint.begin(), ArticulationPoint.end());
    ArticulationPoint.erase(unique(ArticulationPoint.begin(), ArticulationPoint.end()), ArticulationPoint.end());

    int Q; cin>>Q;
    while(Q--){
        int t,k; cin>>t>>k;
        if(t==1){ //k가 단절점인가?
            if(binary_search(ArticulationPoint.begin(), ArticulationPoint.end(), k)) cout<<"yes\n";
            else cout<<"no\n";
        }
        if(t==2){ //k번째 간선이 단절선인가?
            if(Bridge[{edges[k].first, edges[k].second}]) cout<<"yes\n";
            else cout<<"no\n";
        }
    }
    return 0;
}
