//Bitmask + Union find
//모든 비트를 켜놓은 뒤에, 하나씩 꺼보면서 비트가 꺼져도 1 -> N이 가능하면 그대로 두고, 필수적이면 다시 켜준다.

//처음엔 BFS돌면 되는거 아닌가 싶었는데, 그 경우 방문처리가 어려워진다.
//일반적인 다익스트라, BFS 등의 최단거리에서 거리는 거리끼리의 덧셈으로 나타내진다.
//이 문제의 경우 OR이기에 이 경우가 아니므로 사용할 수 없다.
//최단거리 알고리즘은 일반적으로 거리 계산이 거리간의 합인 경우에만 사용 가능하다! (플로이드-와셜은 될거같음)

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

ll N, M;
vector<tuple<ll,ll,ll>> edges;
vector<ll> parent(30'0003);

ll find(ll u){
    if(u==parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(ll u, ll v){
    u=find(u), v=find(v);
    if(u==v) return;
    parent[u] = v;
}   

int check(ll R){
    iota(parent.begin(), parent.end(), 0);
    for(auto&[u,v,weight]:edges){
        if((weight&R)==weight) merge(u,v); //weight&R 묶어야 AC를 받음
    }
    return find(1)==find(N);
}

int main(){
    fastio;
    cin>>N>>M;
    while(M--){
        ll u,v,weight;
        cin>>u>>v>>weight;
        edges.push_back({u,v,weight});
    }
    ll R = (1LL<<60) - 1;
    for(int i=59;i>=0;i--){
        R = R & ~(1LL<<i);
        if(!check(R)){ //i번째 비트가 꺼져서 1과 N이 이어지지 않는 경우
            R = R | (1LL<<i);
        }
    }
    cout<<R;
    return 0;
}
