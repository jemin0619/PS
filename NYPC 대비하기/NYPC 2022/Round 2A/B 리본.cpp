//최소 골 4급 DP

//풀이 참고: https://blog.myungwoo.kr/144

//dp[i][j]: 리본 i와 리본 j를 묶었을 때, 얻을 수 있는 최대 점수 (i<j)
//H[i][j]: 리본 i와 리본 j를 묶었을 때의 리본 세로 길이
//세로길이는 2로 나누지 않음. (괜히 0.몇 나오면 애매해짐)

//H[i][j]>=0 인 경우만 묶기 가능
//dp[i][j]가 -1인 경우는 묶으면 안되는 경우임

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int main() {
    fastio;
    ll N; cin>>N;
    vector<ll> X(N+3);
    vector<ll> A(N+3);
    vector<ll> B(N+3);
    vector<vector<ll>> H(N+3, vector<ll>(N+3, -1));
    vector<vector<ll>> dp(N+3, vector<ll>(N+3, -1));
    for(int i=1;i<=N;i++) cin>>X[i];
    for(int i=1;i<=N;i++) cin>>A[i];
    for(int i=1;i<=N;i++) cin>>B[i];

    //gap이 0칸인 DP (묶지 않은 리본)
    //gap이 1인 DP (바로 옆 리본과 묶음)
    //i와 j를 묶었을 때의 높이 (H[i][j])
    //이 세 가지를 다 채우고 시작함
    for(int i=1;i<=N;i++){
        dp[i][i] = B[i];
        for(int j=i;j<=N;j++){
            H[i][j] = A[i]+A[j]-(X[j]-X[i]);
        }
        if(i<N && H[i][i+1]>=0) dp[i][i+1] = B[i]*B[i+1];
    }

    //어쩌면 몇 개의 리본을 묶지 않을 수도 있다.
    //그러므로 그런 경우에 대해 예외처리를 하기보다 
    //0 ~ N+1을 묶는 세로 길이가 무한대인 묶여진 리본이 있다고 생각하는게 편하다.
    //그 경우 DP[0][N+1]은 1 ~ N 사이의 범위에서 리본들을 어떻게 잘 조합해서 만들 수 있는 최댓값이 될 것이다.
    H[0][N+1] = 2e9 + 1;

    for(int gap=2; gap<=N+1; gap++){
        for(int i=0;i+gap<=N+1;i++){
            int j = i+gap;
            if(H[i][j]<0) continue; //묶을 수 없는 경우 (세로길이가 음수)
            
            //subDp[k]: i+1 ~ k까지 리본의 상태를 정했을 때 얻을 수 있는 최대 점수
            //즉, subDp[k]는 dp[i+1][k]를 의미함. (단, H[i][j]가 H[i+1][k]보다 작아야 함. 아닌 경우는 -1)
            vector<ll> subDp(N+3, -1);

            for(int k=i+1; k<=j-1; k++){
                if(H[i+1][k] < H[i][j]){ //리본을 묶을 수 있는 경우에만 묶어줌
                    subDp[k] = dp[i+1][k];
                }
            }

            for(int k=i+1; k<=j-1; k++){
                if(subDp[k]<0) continue; //리본을 묶을 수 없던 경우 (= -1)이면 continue
                for(int l=k+1; l<=j-1; l++){ 
                    if(dp[k+1][l]<0) continue;
                    if(H[k+1][l]>H[i][j]) continue;
                    subDp[l] = max(subDp[l], subDp[k]+dp[k+1][l]);
                }
                if(subDp[j-1] >= 0) dp[i][j] = subDp[j-1] + B[i]*B[j];
            }
        }
    }
    cout<<dp[0][N+1];
    return 0;
}
