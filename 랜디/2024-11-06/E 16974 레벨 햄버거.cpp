//재귀가 왜 나올까요...
//자력솔은 실패했습니다.
//솔직히 G3은 가도 되지 않나 싶은데 재귀에 익숙하지 않아서 그런 것 같네요

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

array<ll, 53> dp = {0,}; //dp[i] : i레벨 햄버거가 가지는 패티 수
array<ll, 53> len = {0,}; //len[i] : i레벨 햄버거의 크기(길이)

ll solve(ll N, ll X){
    if(X<=0) return 0; //더 이상 못먹으면 중지
    if(N==0) return 1; //0레벨 햄버거면 패티 1장
    
    if(len[N-1]+2 < X) return dp[N-1] + 1LL + solve(N-1, X-len[N-1]-2); //가운데 부분을 넘겨서 먹는 경우
    else if(len[N-1]+2 == X) return dp[N-1] + 1LL; //가운데 부분까지만 먹는 경우
    else if(len[N-1]+2 > X) return solve(N-1, X-1); //가운데에 미치지 못하는 경우
}

int main(){
    fastio;
    ll N, X; cin>>N>>X;
    dp[0] = 1;
    len[0] = 1;
    for(int i=1; i<=N; i++){
        dp[i] = dp[i-1]*2 + 1;
        len[i] = len[i-1]*2 + 3;
    }
    cout<<solve(N, X);
    return 0;
}
