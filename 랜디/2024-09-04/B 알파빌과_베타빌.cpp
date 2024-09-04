//앞의 M명 중 친구의 개수를 총 친구의 개수에서 뺀다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int main(){
    fastio;
    int N, M; cin>>N>>M;
    vector<int> V(N+3);
    vector<bool> check(N+3);
    for(int i=0; i<N; i++) cin>>V[i];
    for(int i=0; i<M; i++){
        int x; cin>>x;
        check[x] = true;
    }
    int ans = M;
    for(int i=0; i<M; i++){
        if(check[V[i]]) ans--;
    }
    cout<<ans;
    return 0;
}
