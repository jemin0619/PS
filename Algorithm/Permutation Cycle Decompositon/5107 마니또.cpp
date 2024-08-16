//map으로 문자열을 숫자로 매핑 후 순싸분

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int tc=1;
    while(true){
        int N; cin>>N;
        if(N==0) break;
        vector<pair<string,string>> query;
        vector<int> V;
        map<string, int> Mp;
        for(int i=0;i<N;i++){
            string u,v; cin>>u>>v;
            Mp[u] = i;
            query.push_back({u,v});
        }
        for(int i=0;i<N;i++){
            V.push_back(Mp[query[i].second]);
        }
        vector<bool> vis(N);
        int cycle = 0;
        for(int i=0;i<N;i++){
            if(vis[i]) continue;
            cycle++;
            for(int nxt=i; !vis[nxt]; nxt=V[nxt]){
                vis[nxt]=true;
            }
        }
        cout<<tc++<<' '<<cycle<<'\n';
    }
    return 0;
}
