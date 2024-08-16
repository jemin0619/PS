//원형 연결리스트 구현 문제
//그냥 배열로도 풀린다.
//구현이 조금 힘들었다.

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int nxt;
    int pre;
};

vector<Node> adj(1000'003);

int main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<int> V(N);
    for (int i = 0; i < N; i++) cin >> V[i];

    for (int i = 0; i < N - 1; i++) adj[V[i]].nxt = V[i + 1];
    adj[V[N - 1]].nxt = V[0];

    for (int i = 1; i < N; i++) adj[V[i]].pre = V[i - 1];
    adj[V[0]].pre = V[N - 1];

    while (M--) {
        string Q;
        cin >> Q;
        if (Q == "BN") {
            int a, b;
            cin >> a >> b;
            cout << adj[a].nxt << '\n';
            int S1 = a;
            int S2 = adj[a].nxt;
            adj[S1].nxt = b;
            adj[b].nxt = S2;
            adj[S2].pre = b;
            adj[b].pre = S1;
        }
        if (Q == "BP") {
            int a, b;
            cin >> a >> b;
            cout << adj[a].pre << '\n';
            int S1 = adj[a].pre;
            int S2 = a;
            adj[S1].nxt = b;
            adj[b].nxt = S2;
            adj[S2].pre = b;
            adj[b].pre = S1;
        }
        if (Q == "CP") {
            int a;
            cin >> a;
            cout << adj[a].pre << '\n';
            int prev_node = adj[a].pre;
            int prev_prev_node = adj[prev_node].pre;
            adj[prev_prev_node].nxt = a;
            adj[a].pre = prev_prev_node;
            adj[prev_node].pre = prev_node;
            adj[prev_node].nxt = prev_node;
        }
        if (Q == "CN") {
            int a;
            cin >> a;
            cout << adj[a].nxt << '\n';
            int next_node = adj[a].nxt;
            int next_next_node = adj[next_node].nxt;
            adj[a].nxt = next_next_node;
            adj[next_next_node].pre = a;
            adj[next_node].pre = next_node;
            adj[next_node].nxt = next_node;
        }
    }

    return 0;
}
