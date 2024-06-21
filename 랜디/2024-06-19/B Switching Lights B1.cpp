#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);

int main(){
    fastio;
    int n,m; cin>>n>>m;
    vector<int> V(n,0);
    while(m--){
        int q,a,b; cin>>q>>a>>b;
        a--; b--;
        if(q==0){
            for(int i=a;i<=b;i++) V[i] = !V[i];
        }
        if(q==1){
            int ans=0;
            for(int i=a;i<=b;i++) ans+=(V[i]==1);
            cout<<ans<<'\n';
        }
    }
    return 0;
}
