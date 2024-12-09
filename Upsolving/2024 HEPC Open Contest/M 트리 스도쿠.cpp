//에디토리얼 기반으로 급하게 짜서 좀 더럽습니다...

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int n; cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0; i<n; i++){
        int x; cin>>x;
        a[i] = {x, i+1};
    } sort(a.begin(), a.end());
    queue<int> q;
    vector<bool> vis(n+1, false);
    vector<int> adj[n+3];
    for(int i=1; i<n; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } q.push(1); vis[1] = true;
    vector<int> path;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        path.push_back(cur);
        for(int nxt : adj[cur]){
            if(vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
    vector<int> ans(n);
    for(int i=0; i<path.size(); i++){
        ans[path[i]-1] = a[i].second;
    }
    cout<<"YES\n";
    for(int val : ans) cout<<val<<' ';
    return 0;
}
