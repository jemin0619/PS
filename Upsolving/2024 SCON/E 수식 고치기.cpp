#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dp[2003][2]; //dp[i][j]: i번째까지 계산했을 때 T(j==0), F(j==1)이 나오게 하기 위한 최소 변경 횟수

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    int N; cin>>N; string S="";
    for(int i=0; i<N; i++){
        char c; cin>>c;
        S+=c;
    }
    if(S[0]=='T') dp[0][0]=0, dp[0][1]=1;
    else dp[0][0]=1, dp[0][1]=0;

    for(int i=2; i<N; i++){
        dp[i][0] = min({
            dp[i-2][0] + (S[i-1]=='|') + (S[i]=='F'), //T & T
            dp[i-2][0] + (S[i-1]=='&') + (S[i]=='F'), //T | T
            dp[i-2][0] + (S[i-1]=='&') + (S[i]=='T'), //T | F
            dp[i-2][1] + (S[i-1]=='&') + (S[i]=='F') //F | T
        });

        dp[i][1] = min({
            dp[i-2][0] + (S[i-1]=='|') + (S[i]=='T'), //T & F
            dp[i-2][1] + (S[i-1]=='|') + (S[i]=='F'), //F & T
            dp[i-2][1] + (S[i-1]=='|') + (S[i]=='T'), //F & F
            dp[i-2][1] + (S[i-1]=='&') + (S[i]=='T') //F | F
        });
    }

    char Q; cin>>Q;
    cout<<dp[N-1][Q=='F'];
    return 0;
}
