#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int N,M; cin>>N>>M;
    vector<int> Pv(N+3, -1), Mv(N+3, -1);
    while(M--){
        int a, c; char b;
        cin>>a>>b>>c;
        if(b=='P') Pv[a] = c;
        if(b=='M') Mv[a] = c;
    }
    int ans[2] = {0,0};
    for(int i=1; i<=N; i++){
        if(Pv[i]==1 && Mv[i]==0) ans[0]++;
        if((Pv[i]==1 && Mv[i]==0) || (Pv[i]==1 && Mv[i]==-1) || (Pv[i]==-1 && Mv[i]==0) || (Pv[i]==-1 && Mv[i]==-1)) ans[1]++;
    }
    cout<<ans[0]<<' '<<ans[1];
    return 0;
}
