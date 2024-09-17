#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int N; cin>>N;
    vector<int> V(N+3);
    vector<int> dp(N+3, 1); //dp[i] : i를 마지막 원소로 하는 가장 긴 증가하는 부분수열의 길이
    int mx = -1;
    for(int i=1; i<=N; i++){
        cin>>V[i];
        for(int j=1; j<i; j++){
            if(V[j]<V[i]) dp[i] = max(dp[i], dp[j]+1);
        }
        mx = max(mx, dp[i]);
    }
    cout<<N-mx;
    return 0;
}
