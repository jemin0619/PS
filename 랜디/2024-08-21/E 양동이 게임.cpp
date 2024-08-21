//BFS 접근으로 2 WA 당했다.
//그래프가 간만이라 실수를 한 것 같다.

//BFS로 접근하면 안된다.
//BFS로 접근할 경우 x 노드에서 값 전파를 끝낸 후에 x에 값이 들어온다면 문제가 생긴다.
//그러므로 위상정렬을 사용하거나, 낮은 수에서 높은 수로만 이동 가능하다는 점을 이용해 dp를 사용해도 된다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int N, M; cin>>N>>M;
    vector<int> adj[N+3];
    while(M--){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<double> dp(N+3, 0);
    dp[1] = 100.0;

    for(int i=1; i<=N; i++)
        for(int nxt : adj[i])
            dp[nxt] += dp[i]/adj[i].size();

    double ans = 0;

    for(int i=1; i<=N; i++)
        if(adj[i].empty()) ans = max(dp[i], ans);

    cout<<fixed<<setprecision(10)<<ans;
    return 0;
}
