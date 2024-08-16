#include <bits/stdc++.h>
using namespace std;
#define fasio cin.tie(NULL)->sync_with_stdio(false)
#define day first
#define money second

//돈을 안내는 것을 돈을 버는 것으로 바꾸고, 돈의 총 합에서 번 돈을 뺀 금액을 출력하면 답이 나온다.

int N, T; //문제 수, 남은 기간
int dp[1003][1003]; //dp[i][j]: i번째 문제까지 고려한 경우 j일에 얻을 수 있는 최대 점수
vector<pair<int,int>> V;
int sum;

int main(){
    fasio;
    cin>>N>>T;
    V.resize(N+1);
    for(int i=1;i<=N;i++){
        int d,m; cin>>d>>m;
        V[i]={d,m};
        sum += m;
    }
    for(int j=1;j<=T;j++){
        for(int i=1;i<=N;i++){
            if(j - V[i].day >= 0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-V[i].day]+V[i].money);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout<<(sum - dp[N][T]);
    return 0;
}
