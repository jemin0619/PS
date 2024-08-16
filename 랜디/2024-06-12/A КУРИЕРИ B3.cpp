//문제 번역을 잘못한 것일수도 있는데 2900m 도 2km로 취급해야 풀렸다.
//처음엔 m 단위로 계산하도록 알고리즘을 짰는데 계속 틀리는 이유가 위의 이유였다.
//뭔가 찝찝한 문제였다.
//출력 부분은 printf가 나았을지도 모르겠다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

ll N, M;
pair<ll,ll> ans;

ll Solve(ll X) {
    // 회사 1 요금 계산
    ll val1 = 0;
    if (X <= 5) val1 = 400;
    else if (X <= 10) val1 = 700;
    else if (X <= 20) val1 = 1200;
    else if (X <= 30) val1 = 1700;
    else val1 = X * 57;

    // 회사 2 요금 계산
    ll val2 = 0;
    if (X <= 2) val2 = 90 + 90 * X;
    else if (X <= 5) val2 = 100 + 85 * X;
    else if (X <= 20) val2 = 125 + 80 * X;
    else if (X <= 40) val2 = 325 + 70 * X;
    else val2 = 925 + 55 * X;

    return min(val1, val2);
}

int main() {
    fastio;
    cin >> N >> M;
    N/=1000; M/=1000;

    ll N_st = Solve(N);
    ll M_st = Solve(M);
    ll total_st = N_st + M_st;

    // 레바와 스토틴카로 변환
    ll total_lv = total_st / 100;
    total_st %= 100;

    // 스토틴카가 10보다 작을 때 0을 추가하여 출력
    if (total_st < 10) cout << total_lv << ".0" << total_st << endl;
    else cout << total_lv << '.' << total_st << endl;

    return 0;
}
