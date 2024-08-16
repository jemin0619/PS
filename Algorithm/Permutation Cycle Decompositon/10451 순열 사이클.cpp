#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int t; cin>>t;
    while(t--){
        int N; cin>>N;
        vector<int> V(N+1);
        vector<bool> vis(N+1);
        int cnt = 0;
        for(int i=1;i<=N;i++) cin>>V[i];
        for(int i=1;i<=N;i++){
            if(vis[i]) continue;
            cnt++;
            for(int nxt=i; !vis[nxt]; nxt=V[nxt]){
                vis[nxt] = true;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
