//처음에 슬라이딩 윈도우로 가야되나 싶었는데, 생각해보니 연속한 수 3개만 보면 해결된다.
//그리디한 전략이 존재하기에 간단하게 해결 가능했다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int main(){
    fastio;
    int N; cin>>N;
    vector<int> V(N);
    for(int i=0; i<N; i++) cin>>V[i];
    sort(V.begin(), V.end());
    int ans = -1;
    for(int i=2; i<V.size(); i++){
        if(V[i] < V[i-1]+V[i-2]) ans = max(ans, V[i]+V[i-1]+V[i-2]);
    }
    cout<<ans;
    return 0;
}
