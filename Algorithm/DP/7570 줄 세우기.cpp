//구현은 DP인데 그리디한 사고가 필요한 문제인 것 같다.
//가장 긴 연속한 증가하는 부분수열만 남겨놓고 나머지를 이동시키는게 최적해이다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int N; cin>>N;
    vector<int> V(N+3);
    vector<int> pos(N+3);
    vector<int> dp(N+3, 1); //dp[i] : i를 마지막 원소로 하는 가장 긴 증가하는 연속한 부분수열의 길이
    for(int i=1; i<=N; i++){
        cin>>V[i];
        pos[V[i]] = i;
    }
    if(N==1) {cout<<0; return 0;}
    int mx = -1;
    for(int i=2; i<=N; i++){
        if(pos[i-1]<pos[i]) dp[i] = dp[i-1]+1;
        mx = max(mx, dp[i]);
    }
    cout<<N-mx;
    return 0;
}
