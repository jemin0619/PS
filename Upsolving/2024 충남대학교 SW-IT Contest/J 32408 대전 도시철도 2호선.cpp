//문해력이 떨어진건지 지문을 한참동안 읽고서야 이해했다...
//자세한 풀이는 hhs2003님이 https://hy3ons.tistory.com/38에 정리하셨습니다!!

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

vector<int> adj[10'0001];
bool vis[10'0001];
int par[10'0001];

//자식-부모 관계 만들고, 1~N 연결관계 파악
void DFS1(int cur, int pre){
    par[cur] = pre;
    for(int nxt : adj[cur]){
        if(nxt==pre) continue;
        DFS1(nxt, cur);
    }
}

ll DFS2(int cur){
    ll ret = 0;
    vis[cur] = true;
    for(int nxt : adj[cur]){
        if(vis[nxt]) continue;
        ret += DFS2(nxt)+1;
    }
    return ret;
}

int main(){
    fastio;
    int N; cin>>N;
    for(int i=1; i<N; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);   
        adj[v].push_back(u); 
    }

    DFS1(1, 0);
    
    //1 ~ N 경로를 뽑아낸다.
    int node = N;
    vector<int> path;
    while(node!=0){
        vis[node] = true;
        path.push_back(node);
        node = par[node];
    }
    reverse(path.begin(), path.end());

    //1 ~ N 경로에서 각 노드에 달린 서브트리들에 속한 노드의 개수를 sz에 넣음
    vector<ll> sz;
    for(int val : path){
        for(int nxt : adj[val]){
            if(vis[nxt]) continue;
            sz.push_back(DFS2(nxt)+1);
        }
    }

    //sz에 원소가 없는 경우도 있는건지, ==1로 하면 RTE
    if((int)sz.size()<=1) {cout<<0; return 0;}

    ll ans = 0;
    ll sum = sz[(int)sz.size()-1];
    for(int i=(int)sz.size()-2; i>=0; i--){
        ans += sz[i] * sum;
        sum += sz[i];
    }
    cout<<ans;
    return 0;
}
