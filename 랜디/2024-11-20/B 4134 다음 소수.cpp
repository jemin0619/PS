//처음에 sieve로 풀려 했는데 MLE, TLE가 뻔했다.
//정수론적인 관점으로 보면 브루트포스를 돌려도 각 TC당 O(sqrt(N))이라 괜찮았다.
//풀이 중 상위권 풀이는 밀러-라빈 소수판정법을 사용한 것이었다.
//내 풀이가 0.2초대인 반면, 해당 풀이는 0.004초로 굉장히 빨랐다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

bool isPrime(ll x){
    if(x==0 || x==1) return false;
    for(ll i=2; i*i<=x; i++){
        if(x%i==0) return false;
    }
    return true;
}

void solve(){
    ll N; cin>>N;
    for(ll i=N; i<=4*1e9+10; i++){
        if(isPrime(i)){
            cout<<i<<'\n';
            return;
        }
    }
}

int main(){
    fastio;
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}
