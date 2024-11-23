//GPT...

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define pii pair<int,int>
#define x first
#define y second

void solve() {
    pii A, B, C, D; 
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;

    // 직선 1의 계수 계산
    double a1 = B.y - A.y;
    double b1 = A.x - B.x;
    double c1 = a1 * A.x + b1 * A.y;

    // 직선 2의 계수 계산
    double a2 = D.y - C.y;
    double b2 = C.x - D.x;
    double c2 = a2 * C.x + b2 * C.y;

    // 두 직선의 평행 여부 확인
    double det = a1 * b2 - a2 * b1;

    if (fabs(det) < 1e-9) { // 두 직선이 평행하거나 일치
        // c1과 c2의 비율로 동일 여부 확인
        if (fabs(a1 * c2 - a2 * c1) < 1e-9 && fabs(b1 * c2 - b2 * c1) < 1e-9) {
            cout << "LINE\n"; // 직선이 동일
        } else {
            cout << "NONE\n"; // 직선이 평행하지만 만나지 않음
        }
    } else { // 교점이 존재하는 경우
        double x = (b2 * c1 - b1 * c2) / det;
        double y = (a1 * c2 - a2 * c1) / det;
        cout << fixed << setprecision(2) << "POINT " << x << " " << y << "\n";
    }
}

int main() {
    fastio;
    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
