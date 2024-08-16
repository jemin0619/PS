//애드 훅
//P[i]가 모두 0이면 연쇄가 일어나면 안된다는 의미이므로 최솟값인 1을 출력해준다.
//1이 아니더라도 답이 되는 케이스가 있을 수도 있지만 답이 항상 존재한다는 전제가 있으므로 안전하게 최소값으로 해준다.
//P[i]중 1이 하나라도 있다면, P[i]가 1이면 최댓값인 10^9를 출력하고, 0이면 P[i]가 1인 풍선을 터뜨리지 않는 값들 중 최대값으로 해준다.

//구현을 너무 어렵게 한 것 같다...
//짜면서 실수를 많이 해서 GPT가 도와줬다.

#include <bits/stdc++.h>
using namespace std;

const int MX = 1000000000;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; 
    cin >> N;
    
    vector<int> X(N);
    vector<int> Y(N);
    vector<int> P(N);
    vector<int> Ans(N, MX);
    map<int, set<int>> Mp_X, Mp_Y;
    bool canPopAll = false;

    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> P[i];
        if (P[i] == 1) {
            Mp_X[X[i]].insert(Y[i]);
            Mp_Y[Y[i]].insert(X[i]);
            Ans[i] = MX;
            canPopAll = true;
        }
    }

    if (!canPopAll) {
        for (int i = 0; i < N; i++) {
            cout << 1 << '\n';
        }
        return 0;
    }

    for (int i = 0; i < N; i++) {
        if (P[i] == 1) continue;

        int y_bound = MX;
        int x_bound = MX;

        // Y축 고정
        if (!Mp_Y[Y[i]].empty()) {
            auto it = Mp_Y[Y[i]].lower_bound(X[i]);
            if (it != Mp_Y[Y[i]].end()) {
                x_bound = min(x_bound, abs(*it - X[i]) - 1);
            }
            if (it != Mp_Y[Y[i]].begin()) {
                x_bound = min(x_bound, abs(X[i] - *(--it)) - 1);
            }
        }

        // X축 고정
        if (!Mp_X[X[i]].empty()) {
            auto it = Mp_X[X[i]].lower_bound(Y[i]);
            if (it != Mp_X[X[i]].end()) {
                y_bound = min(y_bound, abs(*it - Y[i]) - 1);
            }
            if (it != Mp_X[X[i]].begin()) {
                y_bound = min(y_bound, abs(Y[i] - *(--it)) - 1);
            }
        }

        Ans[i] = min(y_bound, x_bound);
    }

    for (int val : Ans) cout << val << '\n';

    return 0;
}
