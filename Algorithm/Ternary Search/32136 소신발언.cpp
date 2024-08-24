//check가 볼록함수이므로 삼분 탐색으로 해결할 수 있다.
//이분탐색 + 매개변수탐색으로 해결할 수 있다곤 하는데, 함수가 unimodal하다는 것이 확인되었으면 바로 삼분탐색으로 접근하는게 빠른 것 같다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int N;
vector<ll> V;

//x에 히터를 설치했을 때 모든 소의 신발을 녹이는 시간
ll check(ll x){
    ll ret = 0;
    for(int i=x-1; i>=1; i--) ret = max(abs(x-i)*V[i], ret);
    for(int i=x+1; i<=N; i++) ret = max(abs(x-i)*V[i], ret);
    return ret;
}

int main(){
    fastio;
    cin>>N;
    V.resize(N+1);
    for(int i=1; i<=N; i++) cin>>V[i];
    
    ll st = 0; ll en = N+1;
    while(st+2<en){
        ll p = (st*2+en)/3;
        ll q = (st+en*2)/3;
        if(check(p) <= check(q)) en=q;
        else st=p;
    }
    ll ans = check(max(1LL, st));
    for(int i=max(1LL,st); i<=en; i++){
        ans = min(check(i), ans);
    }
    cout<<ans;
    return 0;
}
