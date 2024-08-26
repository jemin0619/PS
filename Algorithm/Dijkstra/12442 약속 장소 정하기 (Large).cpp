//각 정점에 가장 늦게 도착한 시간을 기록해야 한다.
//1 - 2 - 3 인 그래프가 있고, 간선들의 가중치가 1, 1과 3에 1초에 거리 1을 이동하는 사람이 있다고 가정한다.
//이때 답은 1과 3이 모두 2에 1초에 도착하므로 1이 된다.
//그러므로 max 연산을 취해서 답을 계산해야 한다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

const ll INF = LLONG_MAX;

ll Solve(){
    ll N, P, M; cin>>N>>P>>M;
    vector<pair<ll,ll>> arr(P);
    vector<pair<ll,ll>> adj[N+3]; //nxt, weight
    vector<ll> ans(N+3, 0);

    //사람 입력
    for(int i=0; i<P; i++){
        ll x,v; cin>>x>>v;
        arr[i] = {x,v};
    }

    //그래프 구성
    while(M--){
        int a,b; cin>>a>>b;
        vector<int> path;
        while(b--){
            int x; cin>>x;
            path.push_back(x);
        }
        for(int i=1; i<path.size(); i++){
            adj[path[i-1]].push_back({path[i], a});
            adj[path[i]].push_back({path[i-1], a});
        }
    }

    
    //모든 사람에 대해 다익스트라 돌리기
    for(auto[Fcur, Fw]:arr){
        vector<ll> d(N+3, INF);
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> PQ;
        d[Fcur] = 0;
        PQ.push({d[Fcur], Fcur});
        while(!PQ.empty()){
            auto[curW, cur] = PQ.top(); PQ.pop();
            if(d[cur] != curW) continue;
            for(auto[nxt, nxtW] : adj[cur]){
                if(d[nxt]<=d[cur]+nxtW) continue;
                d[nxt] = d[cur] + nxtW;
                PQ.push({d[nxt], nxt});
            }
        }
        
        for(int i=1; i<=N; i++){
            if(ans[i]==-1) continue;
            if(d[i]==INF) {ans[i]=-1; continue;}
            ans[i] = max(d[i]*Fw, ans[i]);
        }
    }

    ll answer = INF;
    for(int i=1; i<=N; i++){
        if(ans[i]==-1) continue;
        answer = min(answer, ans[i]);
    }

    if(answer==INF) answer = -1;
    return answer;
}

int main(){
    fastio;
    int tc; cin>>tc;
    for(int i=1; i<=tc; i++){
        cout<<"Case #"<<i<<": "<<Solve()<<'\n';
    }
    return 0;
}
