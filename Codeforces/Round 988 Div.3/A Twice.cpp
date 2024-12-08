#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

void solve(){
    int N; cin>>N;
    vector<int> a(N+1);
    for(int i=0; i<N; i++){
        int x; cin>>x;
        a[x]++;
    }
    int ret = 0;
    for(int i=1; i<=N; i++){
        ret += a[i]/2;
    }
    cout<<ret<<'\n';
}

int main(){
    fastio;
    int tc; cin>>tc;
    while(tc--) solve();
    return 0;
}
