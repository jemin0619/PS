//12:16 5% TLE
//처음에 그래프를 다 만들고 시작하는게 시간초과의 원인이 아닐까?

//12:26 100% AC
//잘못 짚었다. 그냥 우선순위 큐의 정렬 순서를 건드리지 않아, 오름차순이었던 것이 문제였다.

//역방향 간선을 만들고 0, N+1에서 다익스트라를 돌리는 아이디어가 재밌었다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int main(){
    fastio;
    ll N; cin>>N;
    vector<ll> A(N+1);
    vector<ll> B(N+1);
    vector<vector<pair<ll,ll>>> adj(N+2);
    for(int i=1; i<=N; i++) cin>>A[i];
    for(int i=1; i<=N; i++) cin>>B[i];

    for(int i=1; i<=N; i++){
        ll pre = max(i - A[i], 0LL);
        ll nxt = min(i + A[i], N+1LL);
        adj[pre].push_back({B[i], i});
        adj[nxt].push_back({B[i], i});
    }
    vector<ll> dp1(N+2, LLONG_MAX); //0에서 시작하는 다익스트라 결과
    vector<ll> dp2(N+2, LLONG_MAX); //N+1에서 시작하는 다익스트라 결과
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> PQ1, PQ2;

    PQ1.push({0, 0}); dp1[0] = 0; 
    PQ2.push({0, N+1}); dp2[N+1] = 0;

    while(!PQ1.empty()){
        auto[curW, curN] = PQ1.top(); PQ1.pop();
        for(auto[nxtW, nxtN] : adj[curN]){
            if(dp1[nxtN]<=dp1[curN]+nxtW) continue;
            dp1[nxtN] = dp1[curN]+nxtW;
            PQ1.push({dp1[nxtN], nxtN});
        }
    }

    while(!PQ2.empty()){
        auto[curW, curN] = PQ2.top(); PQ2.pop();
        for(auto[nxtW, nxtN] : adj[curN]){
            if(dp2[nxtN]<=dp2[curN]+nxtW) continue;
            dp2[nxtN] = dp2[curN]+nxtW;
            PQ2.push({dp2[nxtN], nxtN});
        }
    }

    for(int i=1; i<=N; i++){
        cout<<min(dp1[i], dp2[i])<<' ';
    }
    return 0;
}
