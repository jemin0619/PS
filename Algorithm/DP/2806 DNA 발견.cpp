//https://www.acmicpc.net/problem/2806

#include <bits/stdc++.h>
using namespace std;

//dp[i][j]: i번째 문자까지 보았을 때 A(j=0) 또는 B(j=1)로 바꾸는데 드는 최소비용 
//Ans는 min(dp[N-1][0], dp[N-1][1]+1)

int main(){
    int N; cin>>N;
    vector<vector<int>> dp(N+3, vector<int>(2, 0x7f7f7f7f)); 
    string S; cin>>S;
    if(S[0]=='A'){
        dp[0][0] = 0;
        dp[0][1] = 1;
    }
    else{
        dp[0][0] = 1;
        dp[0][1] = 0;
    }
    for(int i=1;i<N;i++){
        if(S[i]=='A'){
            //dp[i][0]은 '이전 문자까지 A로 바꾸는데 걸리는 비용'과 
            //'이전 문자까지 B로 바꾸는 비용 + 1(B를 A로 뒤집음)' 중 작은 값이 된다.

            //dp[i][1]은 '이전 문자까지 B로 바꾸는데 걸리는 비용 + 1(S[i]를 B로 변환)'과
            //'이전 문자까지 A로 바꾸는데 걸리는 비용 + 1(A를 다 B로 바꿈)' 중 작은 값이 된다.
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]+1);
            dp[i][1] = min(dp[i-1][0]+1, dp[i-1][1]+1);
        }
        if(S[i]=='B'){
            //dp[i][0]은 '이전 문자까지 A로 바꾸는데 걸리는 비용 + 1(S[i]를 A로 변환)'과 
            //'이전 문자까지 B로 바꾸는 비용 + 1(B를 A로 뒤집음)' 중 작은 값이 된다.

            //dp[i][1]은 '이전 문자까지 A로 바꾸는데 걸리는 비용 + 1(연속된 A를 B로 변환)'과
            //'이전 문자까지 B로 바꾸는데 걸리는 비용' 중 작은 값이 된다.
            dp[i][0] = min(dp[i-1][0]+1, dp[i-1][0]+1);
            dp[i][1] = min(dp[i-1][0]+1, dp[i-1][1]);
        }
    }
    cout<<min(dp[N-1][0], dp[N-1][1]+1);
    return 0;
}
