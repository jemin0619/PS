//dp[i] : 강아지 i마리를 만드는데 드는 최소비용
//이동 불가능한 구간은 imos법으로 처리, O(N)

//엄청 어려운 문제는 아닌데 실수를 많이 함
//BFS도 되는 것 같은데 DP 연습하려고 DP로 풀었습니다

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

ll N, M, A, B; 
vector<ll> segment(10'0003, 0);
vector<ll> dp(10'0003, -1);

ll solve(ll cur){
    if(cur<0) return LLONG_MAX;
    if(segment[cur]) return LLONG_MAX;
    if(cur==0) return 0;

    ll &ret = dp[cur];
    if(ret != -1) return ret;
    
    ret = LLONG_MAX;
    ll D1 = solve(cur-A);
    ll D2 = solve(cur-B);

    if(D1 != LLONG_MAX) ret = min(ret, D1+1);
    if(D2 != LLONG_MAX) ret = min(ret, D2+1);

    return ret;
}

int main(){
    fastio;
    cin>>N>>M>>A>>B;
    while(M--){
        int a,b; cin>>a>>b;
        segment[a] += 1;
        segment[b+1] -= 1; 
    }
    partial_sum(segment.begin(), segment.end(), segment.begin());

    ll ans = solve(N);
    if(ans==LLONG_MAX) cout<<-1;
    else cout<<ans;
    return 0;
}
