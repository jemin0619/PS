//문제를 임의의 세 점을 골라 가장 큰 삼각형을 만들었을 때, 그 넓이를 구하는 문제로 치환할 수 있다.

/*
삼각형의 넓이를 구할 경우엔 두 가지 알고리즘을 사용할 수 있다.

1. 헤론의 공식 (삼각형의 세 변을 통해 넓이를 구함)
S = (a+b+c)/2
A = sqrt(S*(S-a)*(S-b)*(S-c))

2. 신발끈 공식 (삼각형의 세 꼭짓점의 좌표를 통해 넓이를 구함)
x1 x2 x3 x1
y1 y2 y3 y1
1/2 * | x1*y2 + x2*y3 + x3*y1 - x2*y1 - x3*y2 - x1*y3 |
*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second 

long double Ans = -1;

int main(){
    int N; cin >> N;
    vector<pair<int, int>> V;
    while (N--) {
        int x, y; cin >> x >> y;
        V.push_back({x, y});
    }
    for (int i = 0; i < V.size() - 2; i++) {
        for (int j = i + 1; j < V.size() - 1; j++) {
            for (int k = j + 1; k < V.size(); k++) {
                // V[i], V[j], V[k] 세 개의 점을 고른다.
                long double x1 = V[i].X, x2 = V[j].X, x3 = V[k].X;
                long double y1 = V[i].Y, y2 = V[j].Y, y3 = V[k].Y;
                long double val = abs(x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3) / 2;
                Ans = max(val, Ans);
            }
        }
    }
    cout << fixed << setprecision(20) << Ans;
    return 0;
}
