#include <bits/stdc++.h>
using namespace std;

int d[1003][1003]; // [Start idx][End idx] 가 팰린드롬 수인가?

void Palindrome(string a, int len) {
    memset(d, 0, sizeof(d)); // 배열 초기화
    for (int i = 0; i < len; i++) {
        d[i][i] = 1; // 길이가 1이면 모두 팰린드롬 수
        if (i + 1 < len && a[i] == a[i + 1]) d[i][i + 1] = 1; // 같은 수가 연속으로 온 경우 체크
    }

    for (int gap = 2; gap < len; gap++) {
        for (int i = 0; i + gap < len; i++) {
            int s = i, e = i + gap;
            // 시작과 끝이 같고, 그 전 단계가 팰린드롬 수면 팰린드롬 수이다
            if (a[s] == a[e] && d[s + 1][e - 1]) d[s][e] = 1;
        }
    }
}

vector<string> solve(string S) {
    vector<string> ans;
    int len = S.size();
    Palindrome(S, len);

    int mxSize = 0;
    for (int st = len - 1; st >= 0; st--) {
        for (int en = len - 1; en >= st; en--) {
            if (d[st][en]) {
                int currentLength = en - st + 1;
                if (currentLength > 1) { // 길이가 1인 회문 제외
                    if (currentLength > mxSize) {
                        mxSize = currentLength;
                        ans.clear();
                        ans.push_back(S.substr(st, currentLength));
                    } else if (currentLength == mxSize) {
                        ans.push_back(S.substr(st, currentLength));
                    }
                }
            }
        }
    }

    return ans;
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        string s; cin >> s;
        vector<string> ans = solve(s);
        cout << "Case #" << i << ":\n";
        for (string val : ans) cout << val << '\n';
    }
    return 0;
}
