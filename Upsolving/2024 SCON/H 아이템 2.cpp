//처음에 점화식조차 도출이 안됐는데 해설을 보고 완전히 이해했다.
//DP...

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    ll N, K; cin>>N>>K;
    vector<ll> S(N+2*K+3);
    vector<ll> DP(N+2*K+3);
    vector<ll> M(N+2*K+3);
    for(int i=K+1; i<=K+N; i++) cin>>S[i];
    partial_sum(S.begin(), S.end(), S.begin());
    for(int i=1; i<=N+2*K; i++){
        DP[i] = DP[i-1];
        if(i-K>0) DP[i] = max(DP[i-1], M[i-K]+S[i]);
        M[i] = max(M[i-1], DP[i]-S[i]);
    }
    cout<<DP[N+2*K];
    return 0;
}

/*
해설 출처: 2024 SCON editorial

DP[i]를 i까지 보았을 때 얻을 수 있는 최대 점수라고 정의 

점화식은 다음과 같이 도출된다.
DP[i] = max(DP[i-1], max(DP[j] + sum(j+1 ~ i))) (단 j <= i-K)

DP[i-1]은 재쳐두고 max(DP[j] + sum(j+1 ~ i)) (단 j <= i-K)만 관찰한다.

구간합 배열 A가 있을때, max(DP[j] + A[i]-A[j])로 치환할 수 있다.
j에 대한 식을 분리하면 max(A[i] + DP[j]-A[j])가 된다.

W[i]를 j<=i일때 DP[j]-A[j]의 최댓값으로 정의한다.
이전에 DP[i-1]에 대해 구한 점화식에서 W[i-K]를 써주면 O(N)에 문제를 해결할 수 있다.
*/
