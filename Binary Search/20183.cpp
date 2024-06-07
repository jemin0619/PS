//https://www.acmicpc.net/problem/20183

//아이디어 : 다익스트라 + 매개변수탐색
//Dijkstra(mid) 가 FT로 존재한다. 
//가장 작은 T의 위치(hi)를 구하면 된다.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> Pii;

const ll INF = 0x7f7f7f7f7f;
vector<Pii> adj[100'003];
ll N,M,A,B,C;
ll d[100'003];
ll lo,hi;

bool Dijkstra(ll lim){ //간선의 가중치가 lim 이하인 것만 지나감
    priority_queue<Pii,vector<Pii>,greater<Pii>> PQ;
    memset(d,INF,sizeof(d));
    d[A]=0; PQ.push({d[A],A});
    while(!PQ.empty()){
        auto[curW,curN]=PQ.top(); PQ.pop();
        if(d[curN]!=curW) continue;
        for(auto[nxtW,nxtN]:adj[curN]){
            if(nxtW>lim) continue;
            if(d[nxtN]<=d[curN]+nxtW) continue;
            d[nxtN]=d[curN]+nxtW;
            PQ.push({d[nxtN],nxtN});
        }
    }
    if(d[B]>C) return 0; //가진 돈보다 가는 비용이 많다면 False
    else return 1; //가진 돈으로 갈 수 있다면 True
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N>>M>>A>>B>>C;
    while(M--){
        ll u,v,w; cin>>u>>v>>w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
        hi = max(hi,w);
    }
    while(lo+1<hi){
        ll mid = (lo+hi)/2;
        if(Dijkstra(mid)) hi=mid; // <- 이동
        else lo=mid; // -> 이동
    }
    if(Dijkstra(hi)) cout<<hi;
    else cout<<-1;
    return 0;
}
