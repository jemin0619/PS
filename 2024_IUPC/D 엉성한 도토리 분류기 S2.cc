//https://www.acmicpc.net/problem/31848

//도토리가 분류기를 지날수록 크기가 감소합니다.
//도토리 크기를 줄이는 대신 분류기를 지날수록 분류기의 크기를 증가시킬 수 있습니다.
//Binary Search로 해결했습니다.

//분류기의 크기를 살펴보면 단조증가한다는 것을 알 수 있습니다.
//그러므로 오프라인 쿼리 + 모노톤 큐로 해결이 가능할 것 같습니다.

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
