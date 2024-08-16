//floor : 내림
//수학 함수들을 잘 알지 못해 어려웠던 것 같습니다.
//DP Memoization으로 해결합니다.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000;
ll dp[100'0003];

ll solve(ll x){
    if(x<=0) return 1;
    if(dp[x]!=-1) return dp[x];
    return dp[x] = (solve(floor(x-sqrt(x)))%MOD + solve(floor(log(x)))%MOD + solve(floor(x * sin(x) * sin(x)))%MOD)%MOD;
}

int main(){
    memset(dp,-1,sizeof(dp));
    while(1){
        ll x; cin>>x;
        if(x==-1) break;
        cout<<solve(x)<<'\n';
    }
    return 0;
}
