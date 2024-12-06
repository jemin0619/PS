//T의 약수를 모두 구하고, 이분탐색으로 a의 모든 원소에 대해 가장 가까운 약수와의 차의 합이 ans가 된다.
//대충 구현했는데, TC가 약한 것일 수도 있단 생각이 들긴 한다...

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int main(){
    fastio;
    ll N,T; cin>>N>>T;
    vector<ll> a(N);
    for(int i=0; i<N; i++) cin>>a[i];

    vector<ll> div;
    for(int i=1; i<=T; i++){
        if(T%i==0) div.push_back(i);
    }
    sort(div.begin(), div.end());

    ll ans = 0;
    for(ll val : a){
        auto it = lower_bound(div.begin(), div.end(), val);
        ans += min(abs(val-*it), abs(val-*prev(it)));
    }
    cout<<ans;
    return 0;
}
