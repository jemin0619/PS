//dp[i][j] : i개 이하의 수로 j를 만드는 경우의 수
//이를 위해 일단 dp[i][j]를 i개의 수로 j를 만드는 경우의 수 로 설정하고 채워준다.
//점화식은 dp[i][j] = dp[i-1][j-1] + dp[i-1][j-2] + dp[i-1][j-3]이라는 것을 알 수 있다.
//이후 누적합을 해주면 된다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
const ll MOD = 1'000'000'009;

int main(){
    fastio;

    vector<vector<ll>> dp(1003, vector<ll>(1003));
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 1;
    for(int i=2; i<=1000; i++){
        for(int j=1; j<=1000; j++){
            for(int k=j-1; k>=max(1, j-3); k--){
                dp[i][j] += dp[i-1][k];
                dp[i][j]%=MOD;
            }
        }
    }

    for(int i=2; i<=1000; i++){
        for(int j=1; j<=1000; j++){
            dp[i][j] += dp[i-1][j];
            dp[i][j]%=MOD;
        }
    }

    int tc; cin>>tc;
    while(tc--){
        ll N, M; cin>>N>>M;
        cout<<dp[M][N]<<'\n';
    }
    return 0;
}
