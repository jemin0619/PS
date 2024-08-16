//좌압 + 순싸분 + 그리디
//서로 다른 N개의 원소를 swap으로 정렬하려면 최소 N - cycle개수 번 swap해야 한다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

void compress(vector<int>&V){
    vector<int> tmp(V);
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for(int&val : V) val=lower_bound(tmp.begin(), tmp.end(),val)-tmp.begin();
}

int main(){
    fastio;
    int N; cin>>N;
    vector<int> V(N);
    for(int i=0;i<N;i++) cin>>V[i];
    compress(V);
    vector<bool> vis(N);
    int cycle = 0;
    for(int i=0;i<N;i++){
        if(vis[i]) continue;
        cycle++;
        for(int nxt=i; !vis[nxt]; nxt=V[nxt]){
            vis[nxt] = true;
        }
    }
    cout<<N - cycle;
    return 0;
}
