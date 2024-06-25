//Check(mid) : 랜선의 크기를 mid로 할 때 N개의 랜선을 만들 수 있는가?
//Check(mid)가 TF로 존재한다.
//T(lo)를 출력하면 된다.

//문제에서 lo=1, hi=2^31 -1로 정의했는데, hi는 대충 0x7f7f7f7f7f로 잡아준다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

ll K,N;
vector<ll> V;

bool Check(ll x){
    ll ans=0;
    for(ll v : V) ans += (v/x);

    if(ans>=N) return true;
    else return false;
}

int main(){
    fastio;
    cin>>K>>N;
    for(int i=0;i<K;i++){
        ll x; cin>>x;
        V.push_back(x);
    }

    ll lo=1, hi=0x7f7f7f7f7f;
    while(lo+1<hi){
        ll mid = (lo+hi)/2;
        if(Check(mid)) lo=mid;
        else hi=mid;
    }

    cout<<lo;
    return 0;
}
