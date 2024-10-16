//N, R이 입력되었을 때, N-R의 약수 중 R보다 큰 수들의 합을 구하면 된다.
//O(sqrt(N-R))

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int main(){
    fastio;
    ll N, R; cin>>N>>R;
    N -= R;
    ll ans = 0;
    for(ll i=1; i<=sqrt(N); i++){
        if(N%i==0){
            if(i>R) ans += i;
            if(i != N/i){
                if(N/i > R) ans += N/i;
            }
        }
    }
    cout<<ans;
    return 0;
}
