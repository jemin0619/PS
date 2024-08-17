//subtask 1,2만 노리고 짰다.
//단방향 간선이라는 것에 유의
//subtask 3까지 노리려면 도착점은 고정이므로 도착점에서 모든 정점에 대해 최소 몇초에 도달해야하는지 O(N)에 돌면 될거같은데, 시간이 없음...

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define ff first
#define ss second
#define pii pair<ll,ll>
#define tiii tuple<ll,ll,ll>
#define pb push_back


ll N,M,K,Q;
vector<ll> adj[10'0003];
map<pii,vector<pii>> edges;

int main(){
    fastio;
    cin>>N>>M>>K>>Q;
    while(M--){
        ll S,Ts,D,Td; cin>>S>>Ts>>D>>Td;
        adj[S].pb(D);
        edges[{S, D}].push_back({Ts,Td});
    }
    
    while(Q--){
        ll S,T; cin>>S>>T;
        ll Ans = -1;
        queue<pii> que; //위치, 시간
        que.push({S,T});
        while(!que.empty()){
            auto[cur, time]=que.front(); que.pop();
            if(cur==K){
                if(Ans==-1) Ans=time;
                else Ans = min(Ans, time);
                continue;
            }
            for(ll nxt : adj[cur]){
                for(auto[st,en]:edges[{cur,nxt}]){
                    if(time<=st){
                        que.push({nxt,en});
                    }
                }
            }
        }
        cout<<Ans<<'\n';
    }
    return 0;
}
