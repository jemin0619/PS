//재밌는 문제였다.
//그냥 MST를 만들면 되는 문제였고, 1번에서부터 시작할 필요도 없었다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

vector<int> parent;
vector<int> w;
vector<tuple<int,int,int>> edge;

int find(int u){
    if(u==parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u>v) swap(u,v);
    parent[v] = u;
}

int main(){
    int N, M, t; cin>>N>>M>>t;
    parent.resize(N+1);
    w.resize(N+1);
    for(int i=1; i<=N; i++){
        parent[i] = i;
    }

    while(M--){
        int u, v, g; cin>>u>>v>>g;
        edge.push_back({g,u,v}); 
    }

    sort(edge.begin(), edge.end());

    int Ans = 0;
    int add = 0;
    for(auto [g,u,v] : edge){
        u = find(u);
        v = find(v);
        if(u==v) continue;
        merge(u, v);
        Ans += g+add;
        add += t;
    }   
    cout<<Ans;
    return 0;
}
