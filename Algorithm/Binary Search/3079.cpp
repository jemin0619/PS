//hi는 10^18로 잡는다. 
//심사에 10^9 시간이 걸리는 심사대에 10^9명이 심사를 받을 경우
//Max_M(=10^9) * Max_T(=10^9) = 10^18

//Check(mid) : mid 시간 내로 모든 사람(M명)이 입국심사를 마칠 수 있는가?

//N     1 ~ 10^5
//M     1 ~ 10^9
//Tx    1 ~ 10^9

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

ll N,M;
vector<ll> T;

bool Check(ll x){
    ll cnt = 0;
    for(ll val : T){
        cnt += (x/val);
        if(cnt>=M) return true; //오버플로가 발생할 수 있기에 반환을 미리 해준다.
    }
    return false;
}

int main(){
    fastio;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        ll x; cin>>x;
        T.push_back(x);
    }
    
    ll lo=0 ,hi=1e18;
    while(lo+1<hi){
        ll mid = (lo+hi)/2;
        if(Check(mid)) hi=mid;
        else lo=mid;
    }
    cout<<hi;
    return 0;
}
