//최단거리는 다익스트라, 소수 전처리는 sieve
//두 알고리즘을 각각 써서 처리해주면 된다.
//시작 정점을 1, 도착 정점을 2로 둔 뒤, 나머지 정점들을 3번부터 추가해주고, 1에서 2까지의 거리를 출력했다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define pii pair<ll,ll>
#define xx first 
#define yy second

int idx = 1;
vector<pair<pii, int>> V;
vector<bool> isPrime(10000, true);
vector<vector<pii>> adj;
priority_queue<pii, vector<pii>, greater<pii>> PQ;
vector<ll> dp;

ll getDist(pii A, pii B){
    ll ret = floor(sqrt((A.xx-B.xx)*(A.xx-B.xx) + (A.yy-B.yy)*(A.yy-B.yy)));
    return ret;
}

void sieve(){
    isPrime[0] = isPrime[1] = 0;
    for(int i=2; i<=10000; i++){
        if(isPrime[i]){
            for(int j=i*2; j<=10000; j+=i){
                isPrime[j] = false;
            }
        }
    }
}

int main(){
    fastio;
    sieve(); //0 ~ 1만까지의 소수 전처리
    pii st, en; cin>>st.xx>>st.yy>>en.xx>>en.yy;
    V.push_back({st, idx++});
    V.push_back({en, idx++});

    int M; cin>>M;
    while(M--){
        pii a; cin>>a.xx>>a.yy;
        V.push_back({a, idx++});
    }

    adj.resize(V.size()+3);
    dp.resize(V.size()+3, 0x7f7f7f7f);

    for(int i=0; i<V.size(); i++){
        for(int j=i+1; j<V.size(); j++){
            auto[A, idx1] = V[i];
            auto[B, idx2] = V[j];
            ll dist = getDist(A, B);
            if(isPrime[dist]){
                adj[idx1].push_back({dist, idx2});
                adj[idx2].push_back({dist, idx1});
            }
        }
    }   

    dp[1] = 0;
    PQ.push({dp[1], 1});
    while(!PQ.empty()){
        auto[curW, curN] = PQ.top(); PQ.pop();
        for(auto[nxtW, nxtN] : adj[curN]){
            if(dp[nxtN]<=dp[curN]+nxtW) continue;
            dp[nxtN] = dp[curN]+nxtW;
            PQ.push({dp[nxtN], nxtN});
        }
    }

    if(dp[2]==0x7f7f7f7f) cout<<-1;
    else cout<<dp[2];
    return 0;
}
