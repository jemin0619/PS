//출력, 선택, 복사, 붙여넣기

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

using ll = long long;

int main(){
    fastio;
    vector<ll> dp(101, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i=4; i<=100; i++){
        dp[i] = dp[i-1]+1;
        for(int j=3; j<i; j++){
            //전체선택, 복사, 붙여넣기로 최소 비용이 3이다.
            //붙여넣기를 j-2번 하면 dp[i-j]에서 j-1배가 된다.
            dp[i] = max(dp[i], dp[i-j]*(j-1));
        }
    }
    int N; cin>>N;
    cout<<dp[N];
    return 0;
}
