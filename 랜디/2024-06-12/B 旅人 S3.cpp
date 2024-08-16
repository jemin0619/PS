//dp로 누적합 구하기
//각 쿼리 O(1)에 처리

//ll로 풀면 출력에서 MOD를 해도 되는데, int로 풀면 매 쿼리마다 MOD를 해야한다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

const ll MOD = 100000;
ll N, M;
ll pre, cur;
ll ans;
vector<ll> V;

int main(){
    fastio;
    cin>>N>>M;
    V.push_back(0);
    for(ll i=0;i<N-1;i++){
        ll x; cin>>x;
        V.push_back(x);
    }
    partial_sum(V.begin(),V.end(),V.begin());
    while(M--){
        ll Q; cin>>Q;
        cur += Q;
        ans += abs(V[cur]-V[pre]);
        ans%=MOD;
        pre = cur;
    }
    cout<<ans;
    return 0;
}
