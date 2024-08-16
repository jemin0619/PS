//이동 가능한 정점이 많을 경우 오름차순으로 이동하라는 조건때문에 set에 담았다.

#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    int N,M,R; cin>>N>>M>>R;
    set<int> adj[N+3];
    for(int i=0; i<M; i++){
        int u,v; cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    vector<int> dist(N+3, 0);
    queue<int> que;
    que.push(R);
    dist[R] = 1;
    int order = 2;
    while(!que.empty()){
        int cur = que.front(); que.pop();
        for(int nxt : adj[cur]){
            if(dist[nxt]!=0) continue;
            dist[nxt] = order++;
            que.push(nxt);
        }
    }
    for(int i=1; i<=N; i++) cout<<dist[i]<<'\n';
    return 0;
}
