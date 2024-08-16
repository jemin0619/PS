#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long

const ll INF = 0x7f7f7f7f;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    ll answer = 0;
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, INF));
    for(int i=1;i<=n;i++) dp[i][i] = 0;
    for(int i=0;i<fares.size();i++){
        dp[fares[i][0]][fares[i][1]] = fares[i][2];
        dp[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
    
    answer = dp[s][a] + dp[s][b];
    for(int i=1;i<=n;i++){
        ll D = dp[s][i] + dp[i][a] + dp[i][b];
        answer = min(answer,D);
    }
    return answer;
}
