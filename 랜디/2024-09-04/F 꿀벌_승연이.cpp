//구멍을 입력받을 때 좌표를 1-indexed로 유지해서 WA
//MOD를 안해서 WA
//MOD를 빡쎄게 안씌워서 WA
//사실 그냥 long long 박으면 MOD 대충 씌워도 AC가 나온다.

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int N, M, K;
int dp[1003][1003];

int solve(int y, int x){
    if(y<0 || x<0 || y>=N || x>=M) return 0;
    int &ret = dp[y][x];
    if(ret!=-1) return ret;
    if(x%2==0) ret = ((solve(y+1, x)%MOD + solve(y, x+1)%MOD)%MOD + solve(y-1, x+1)%MOD)%MOD;
    else ret = ((solve(y+1, x)%MOD + solve(y, x+1)%MOD)%MOD + solve(y+1, x+1)%MOD)%MOD;
    return ret%=MOD;
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    cin>>N>>M>>K;
    while(K--){
        int y,x; cin>>y>>x;
        dp[--y][--x] = 0;
    }
    dp[N-1][M-1] = 1;
    cout<<solve(0,0);
    return 0;
}
