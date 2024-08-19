#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ff first 
#define ss second
#define ll long long

ll Ans = -1;
int N, M;
vector<int> adj[13];
ll edge[13][13];
vector<bool> vis(13);

void DFS(int cur, ll time, int depth){
    if(depth!=0 && cur==0){
        //이때 모든 정점 방문하지 않았으면 바로 return해야된다.
        bool flag = true;
        for(int i=1; i<=N; i++){
            if(vis[i]==false) {flag = false; break;}
        }
        if(flag) Ans = max(time, Ans);
        return;
    }
    if(depth>=N+1){
        if(cur==0) Ans = max(time,Ans); 
        return;
    }
    for(int nxt : adj[cur]){
        if(vis[nxt]) continue;
        vis[nxt] = true;
        DFS(nxt, time+edge[cur][nxt], depth+1);
        vis[nxt] = false;
    }
}

int main(){
    fastio;
    cin>>N>>M;
    while(M--){
        ll u,v,w; cin>>u>>v>>w;
        if(u==v) continue;
        if(edge[u][v]==0) adj[u].push_back(v);
        edge[u][v] = max(edge[u][v], w);
    }
    DFS(0,0,0);
    cout<<Ans;
    return 0;   
}

//백트래킹인데 구현 실수로 WA를 많이 받음

//3 TLE : 가장 긴 간선 하나만 남겨놓는게 맞는데, 간선 길이는 갱신해도 간선 추가가 반복되어서 TLE
//2 WA : 0에 도착했는데, 모든 정점을 방문하지 않은 경우를 케어하지 않음
//2 CE : 제출을 잘못함
//01:25 AC
