#include <bits/stdc++.h>
using namespace std;

int N,Q;
string S;
int sc[5003][5003];
int dp[5003][5003];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>N>>S>>Q;
    S = " " + S;

    for(int i=S.size()-2;i>0;i--)
        for(int j=i+1;j<S.size();j++)
            sc[i][j]=(S[i]==S[j])+sc[i+1][j-1];
    
    for(int i=S.size()-2;i>0;i--){
        for(int j=i+1;j<S.size();j++){
            if((j-i+1)%2==0) dp[i][j]=max({sc[i][j],dp[i+1][j],dp[i][j-1]});
            else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
        }
    }

    while(Q--){
        int r,l; cin>>r>>l;
        cout<<dp[r][l]<<'\n';
    }
    return 0;
}