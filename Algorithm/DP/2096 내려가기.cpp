//처음엔 메모리제한을 보지 못하고 탑다운으로 풀려고 했는데, 슬라이딩 윈도우로 접근해야 한다.

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mx first
#define mn second

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    int N; cin>>N;
    int a,b,c; cin>>a>>b>>c;
    pii dp[3] = {{a,a}, {b,b}, {c,c}};
    for(int i=0; i<N-1; i++){
        int a,b,c; cin>>a>>b>>c;
        pii tmp[3] = {dp[0], dp[1], dp[2]};

        dp[0].mx = max(tmp[0].mx, tmp[1].mx)+a;
        dp[1].mx = max({tmp[0].mx,tmp[1].mx,tmp[2].mx})+b;
        dp[2].mx = max(tmp[1].mx,tmp[2].mx)+c;

        dp[0].mn = min(tmp[0].mn, tmp[1].mn)+a;
        dp[1].mn = min({tmp[0].mn,tmp[1].mn,tmp[2].mn})+b;
        dp[2].mn = min(tmp[1].mn,tmp[2].mn)+c;
    }
    cout<<max({dp[0].mx, dp[1].mx, dp[2].mx})<<' '<<min({dp[0].mn, dp[1].mn, dp[2].mn});
    return 0;
}
