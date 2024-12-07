//dp[i][j] : 공격력 i, 체력 j에 도달하기까지 필요한 방어구 수
//2차원 누적합으로 공격력 i, 체력 j로 잡을 수 있는 몬스터의 수를 관리하는게 인상적이다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int N, M, X, Y, K;
int dp[303][303];
int mob[303][303];

int main(){
    fastio;
    cin>>N>>M>>X>>Y;
    memset(dp, 0x3f, sizeof(dp));
    dp[X][Y] = 0;
    for(int i=0; i<N; i++){
        int x,y; cin>>x>>y;
        for(int j=300; j>=0; j--){
            for(int k=300; k>=0; k--){
                int&val = dp[min(300, j+x)][min(300, k+y)];
                val = min(val, dp[j][k]+1);
            }
        }
    }
    cin>>K;
    while(K--){
        int p,q; cin>>p>>q;
        mob[p][q]++;
    }

    for(int i=1; i<=300; i++)
        for(int j=1; j<=300; j++)
            mob[i][j] = mob[i-1][j] + mob[i][j-1] - mob[i-1][j-1] + mob[i][j];

    int ans = 0;
    for(int i=0; i<=300; i++){
        for(int j=0; j<=300; j++){
            if(dp[i][j]<=M) ans = max(ans, mob[i][j]);
        }
    }

    cout<<ans;
    return 0;
}
