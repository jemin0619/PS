//dp[i][j] : i번째 막대기까지 보았고, 길이 1인 막대기를 j개 이상 만드는 최소비용
//dp[i][0]은 사용하지 않으므로 주석처리해도 잘 동작한다. (애초에 접근할 수 없는 공간임)
//그리고 풀다가 겪은 억까의 원인은 0x7f7f7f7f였다. 
//얘를 LLONG_MAX로 하니까 잘 동작했음...

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
const ll INF = LLONG_MAX;

int main() {
    fastio;
    ll T; cin>>T;
    while(T--){
        ll N, K, A, B; cin>>N>>K>>A>>B;
        vector<ll> S(1); //1-indexed 설정

        ll cnt = 0; //길이 1의 막대의 개수
        for(int i=1;i<=N;i++){
            ll x; cin>>x;
            if(x==1) cnt++;
            else S.push_back(x);
        }

        //길이 1의 막대만으로 K를 구성할 수 있다면 그게 최적해이므로 0 출력
        K-=cnt;
        if(K<=0){
            cout<<0<<'\n';
            continue;
        }

        N = S.size()-1;
        vector<vector<ll>> dp(N+3, vector<ll>(K+3, INF));
        //dp[0][0] = 0;
        for(int i=1;i<=N;i++){
            ll cost = A*(S[i]-1)*(S[i]-1) + B;
            //dp[i][0] = dp[i-1][0];
            for(int j=1;j<=K;j++){
                //만드려는 막대 길이(=j) 가 막대 길이 이하라면 
                if(j <= S[i]) dp[i][j] = min(dp[i-1][j], cost);

                //만드려는 막대 길이(=j) 가 막대 길이보다 크면 
                else if(j > S[i]){
                    if(dp[i-1][j-S[i]]>=INF) continue;
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-S[i]] + cost);
                }
            }
        }
        cout<<dp[N][K]<<'\n';
    }
    return 0;
}
