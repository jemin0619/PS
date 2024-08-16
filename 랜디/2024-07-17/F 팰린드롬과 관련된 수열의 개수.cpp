#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

ll power(ll a, ll b) {
    ll ret = 1LL;
    while (b > 0) {
        if (b & 1) {
            ret = (ret * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

ll solve(ll N, ll M, ll K) {
    if (K == 1 || N < K) return power(M, N);
    if (K == N) {
        if (N % 2 == 0) return power(M, N / 2);
        else return (power(M, N / 2) * M) % MOD;
    }
    if (K < N) {
        if (K % 2 == 0) return M % MOD;
        else return power(M, 2);
    }
    return 0;
}

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    cout << solve(N, M, K);
    return 0;
}

/*
시간제한이 빡세므로 O(1)에 가까운 수식으로 풀어야됨

입력은 N M K로 주어짐
N은 수열의 길이
M은 수열에 사용할 수 있는 수의 개수
수열에서 길이 K의 부분 연속 수열이 모두 팰린드롬이어야 함

- 별도로 팰린드롬을 만들 필요가 없는 경우
    - K=1, N<K
    이 경우엔 팰린드롬을 구성할 필요가 없으므로 M 종류의 수로 길이 N의 수열을 구성하면 된다.
    M^N을 출력한다.

- 팰린드롬을 구성해야 하는 경우 
    - K==N
        - N이 짝수면 M^(N/2) (절반만 수 구성)
        - N이 홀수면 M^(N/2) * M (절반 구성하고 가운데 넣을 수 고름)

    - K<N
        - K가 짝수라면 수열의 모든 수가 같아야하므로 M개의 수열이 이를 만족함
        - K가 홀수라면 수열의 짝수번 수와 홀수번 수가 같아야함.
        - 그러므로 홀수일 땐 M에서 수 두 개를 고르는 것이므로 M^2가 답이 된다.
*/
