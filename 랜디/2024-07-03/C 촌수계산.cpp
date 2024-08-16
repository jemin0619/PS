#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N,M;
int st,en;
vector<int> adj[103];
vector<int> dist;

int main(){
    fastio;
    cin>>N>>st>>en>>M;
    dist.resize(N+1,-1);
    while(M--){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int> Q;
    Q.push(st); dist[st]=0;
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        if(cur==en) {cout<<dist[cur]; return 0;}
        for(int nxt : adj[cur]){
            if(dist[nxt]!=-1) continue;
            Q.push(nxt); dist[nxt] = dist[cur]+1;
        }
    }
    cout<<-1;
    return 0;
}
