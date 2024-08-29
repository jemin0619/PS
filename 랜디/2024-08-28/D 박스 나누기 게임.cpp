//dp[i] : 어느 한 쪽이 i일때 승리하는가?
//테이블 다 채우고 보니 짝수 / 홀수에 따라 true false가 결졍됨
//예전엔 게임 DP가 그렇게 어려웠는데 생각보다 할만해졌다.

#include <bits/stdc++.h>
using namespace  std;

bool dp[103];

int main(){
    dp[1] = false;
    dp[2] = true;
    for(int i=3; i<=100; i++){
        dp[i] = false;
        for(int j=1; j<=i/2; j++){
            if(!dp[j] && !dp[i-j]){
                dp[i] = true;
                break;
            }
        }
    }
    int N, M; cin>>N>>M;
    if(dp[N] || dp[M]) cout<<"A";
    else cout<<"B";
    return 0;
}
