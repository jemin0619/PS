//규칙을 찾고 해결했는데, 생각보다 어려웠다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
const ll MOD = 45678;

int main(){
    fastio;
    ll N; cin>>N;
    ll ans = 5;
    for(int i=2; i<=N; i++){
        ans += (4+3*(i-1))%MOD;
        ans %= MOD;
    }
    cout<<ans;
    return 0;
}
