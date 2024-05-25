//https://www.acmicpc.net/problem/31846

//Bruteforce도 가능하지만 DP로 해결했습니다.
//sc[i][j] : i와 j를 끝점으로 문자열을 반으로 접었을 때 얻을 수 있는 점수
//dp[i][j] : i와 j를 끝점으로 해서 접었을 때 얻을 수 있는 최대 점수

//이때 문자열을 길이가 짝수인지 홀수인지에 따라 처리가 달라야 합니다.
//짝수면 문자열을 반으로 접는게 가능하므로 sc[i][j], dp[i+1][j], dp[i][j-1] 중 최댓값이 답이 되고,
//홀수면 문자열을 반으로 접지 못하므로 dp[i+1][j], dp[i][j-1] 중 최댓값이 답이 됩니다.

//for문 범위를 조정해서 문자열 시작 범위를 뒤에서부터 앞으로 오게 설계했습니다.

#include <bits/stdc++.h>
using namespace std;

int N,Q;
string S;
int sc[53][53];
int dp[53][53];

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
