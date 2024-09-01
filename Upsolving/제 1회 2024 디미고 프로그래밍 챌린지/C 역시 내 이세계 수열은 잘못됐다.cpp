//처음에 1의 경우만 고려해서 틀리고, 2를 떠올리긴 했는데 반례가 쉽게 떠오르지 않았다.
//2의 경우까지 고려해 AC를 받았다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define ff first
#define ss second
#define pii pair<ll,ll>
#define tiii tuple<ll,ll,ll>
#define pb push_back

int main(){ 
    fastio;
    ll N, M; cin>>N>>M;
    vector<ll> V(N);
    for(int i=0; i<N; i++) cin>>V[i];

    ll ans = 0;

    for(int i=0; i<N/2; i++){
        ll A = V[i];
        ll B = V[N-1-i];
        ll gap = abs(A-B);
        //1. +K를 mn이 mx보다 커지기 전까지 반복하고, 남은 차를 +1로 때우기
        //2. +K를 mn이 mx보다 커지기 전까지 반복하고, mn에 +K를 한 번 더 하고 남은 차를 +1로 때우기
        ans += min(gap/M + gap%M, gap/M + (M - gap%M) + 1);
    }
    cout<<ans;
    return 0;
}
