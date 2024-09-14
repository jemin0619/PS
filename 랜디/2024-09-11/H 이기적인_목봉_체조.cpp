//BOJ 11066 파일 합치기처럼 풀 수 있다.
//어려웠다.

//O(N^2) F 테이블 전처리, dp 점화식까지 떠올렸는데 구현에서 막혔었다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define ff first
#define ss second

ll N, M; //훈련병 수, 그룹 수
vector<pair<ll,ll>> V;
vector<vector<ll>> F; //F[i][j]: i~j번 훈련생이 들 수 있는 목봉의 최대 무게
vector<vector<ll>> dp; //dp[i][j]: i번 훈련생까지 총 j개의 그룹을 만들었을 때 들 수 있는 목봉의 최대 무게

int main(){
    fastio;
    cin>>N>>M;
    V.resize(N+3);
    F.resize(N+3, vector<ll>(N+3));
    dp.resize(N+3, vector<ll>(M+3));
    for(int i=1; i<=N; i++) cin>>V[i].ff>>V[i].ss;
    for(int i=1; i<=N; i++){
        ll mxHeight = V[i].ff;
        F[i][i] = V[i].ss;
        for(int j=i+1; j<=N; j++){
            if(V[j].ff>mxHeight) {F[i][j] = V[j].ss; mxHeight=V[j].ff;}
            else if(V[j].ff==mxHeight) F[i][j] = F[i][j-1] + V[j].ss;
            else if(V[j].ff<mxHeight) F[i][j] = F[i][j-1];
        }
    }

    //dp[i][1] 채우기
    for(int i=1; i<=N; i++) dp[i][1] = F[1][i];

    for(int i=2; i<=M; i++){ //그룹 i개
        for(int j=2; j<=N; j++){ //j번째 훈련생
            for(int k=2; k<=j; k++){
                dp[j][i] = max(dp[j][i], dp[k-1][i-1] + F[k][j]);
            }
        }
    }

    cout<<dp[N][M];
    return 0;
}
