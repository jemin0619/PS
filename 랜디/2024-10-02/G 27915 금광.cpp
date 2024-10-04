//자력솔 실패
//처음에 후위순회로 돌면서 인접한 두 원소가 자식-부모 관계면 묶어주는 식으로 접근하려 했는데 WA를 받았다.

//트리, 이분 그래프
//트리의 1번 노드에서부터 DFS를 하면서 1번 노드와의 거리가 짝수/홀수인지에 따라 이분 그래프로 관찰할 수 있습니다.
//문제 조건에 따라 모든 기업은 두 개 이상의 금광을 캐려면 사이 거리가 홀수여야 하므로,
//각 기업은 최대 홀수 금광과 짝수 금광, 이 두 개를 캘 수 있습니다.
//따라서 두 금광의 개수 중 큰 쪽의 정답이 됩니다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N;
vector<vector<int>> adj;
int cnt[3];

void DFS(int cur, bool flag){
    cnt[flag]++;
    for(int nxt : adj[cur]) DFS(nxt, !flag);
}

int main(){
    fastio;
    cin>>N;
    adj.resize(N+3);
    for(int i=2; i<=N; i++){
        int x; cin>>x;
        adj[x].push_back(i);
    }
    DFS(1, 0);
    cout<<max(cnt[0], cnt[1]);
    return 0;
}
