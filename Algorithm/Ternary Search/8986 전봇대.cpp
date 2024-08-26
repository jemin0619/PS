//2013 KOI 문제였는데, 그때 KOI는 다양한 알고리즘 문제를 낸 것 같다...

//만약 0을 고정시키지 않는다면 어떻게 풀 수 있을까?

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
const ll MX = 1'000'000'000;

ll N;
vector<ll> V;

//전봇대 사이의 거리를 x로 할 때 총 이동거리
//함수의 Unimodal함이 관찰되었으므로 삼분탐색으로 풀 수 있다.
ll check(ll x){
    ll ret = 0;
    for(int i=1; i<N; i++){
        ret += abs(V[i] - x*i);
    }
    return ret;
}

int main(){
    fastio;
    cin>>N;
    V.resize(N);
    for(int i=0; i<N; i++) cin>>V[i];

    ll st=0;
    ll en=MX+1;
    while(st+2<en){
        ll p = (st*2+en)/3;
        ll q = (st+en*2)/3;
        if(check(p)>=check(q)) st = p;
        else en = q;
    }

    ll mn = check(st);
    for(int i=st; i<=en; i++) mn = min(mn, check(i));
    cout<<mn;
    return 0;
}
