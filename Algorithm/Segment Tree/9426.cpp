#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
const ll MX = 65536;

ll N, K;
vector<ll> SegTree;
vector<ll> V;

ll update(ll idx, ll newValue, ll node, ll leftNode, ll rightNode) {
    if (idx < leftNode || rightNode < idx) return SegTree[node];
    if (leftNode == rightNode) return SegTree[node] += newValue;
    ll mid = leftNode + (rightNode - leftNode) / 2;
    ll leftVal = update(idx, newValue, node * 2, leftNode, mid);
    ll rightVal = update(idx, newValue, node * 2 + 1, mid + 1, rightNode);
    return SegTree[node] = leftVal + rightVal;
}

ll Kth(ll K, ll node, ll leftNode, ll rightNode) {
    if (leftNode == rightNode) return leftNode;
    ll mid = leftNode + (rightNode - leftNode) / 2;
    if (K <= SegTree[node * 2]) return Kth(K, node * 2, leftNode, mid);
    return Kth(K - SegTree[node * 2], node * 2 + 1, mid + 1, rightNode);
}

int main() {
    fastio;
    cin >> N >> K;
    SegTree.resize(65536 * 4);
    V.resize(N+1);
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }
    for (int i = 0; i < K; i++) {
        update(V[i], 1, 1, 0, MX);
    }
    ll Ans = 0;
    for (int i = K; i <= N; i++) {
        Ans += Kth((K + 1) / 2, 1, 0, MX);
        update(V[i - K], -1, 1, 0, MX);
        update(V[i], 1, 1, 0, MX);
    }
    cout << Ans;
    return 0;
}
