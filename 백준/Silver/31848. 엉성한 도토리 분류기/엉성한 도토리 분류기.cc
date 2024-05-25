#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
int N, Q;

bool cmp(pair<int, int>&a, int value) {
    return a.first < value;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        x += (i - 1);
        if (v.empty() || v.back().first < x) v.push_back({x, i});
    }
    cin >> Q;
    while (Q--) {
        int x; cin >> x;
        auto it = lower_bound(v.begin(), v.end(), x, cmp);
        cout << it->second << ' ';
    }
    return 0;
}