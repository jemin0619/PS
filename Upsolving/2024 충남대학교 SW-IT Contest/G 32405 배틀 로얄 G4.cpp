//자신을 제외한 나머지에서 d_i를 빼는 것은, 자기 자신의 체력만 d_i만큼 올리고, 
//전체에서 d_i만큼 빠졌단 처리를 해주는 것과 같다.
//어떤 플레이어의 체력이 0이 된 것을 온라인으로 처리할 필요가 없다는 것은 금방 떠올릴 수 있다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int main(){
    fastio;
    int N; cin>>N;
    vector<ll> d(N);
    vector<ll> h(N);
    for(int i=0; i<N; i++) cin>>d[i];
    for(int i=0; i<N; i++) cin>>h[i];
    queue<ll> Q;
    for(int i=0;i<N;i++) Q.push(i);

    ll minus = 0;
    while(Q.size()>1){
        int cur = Q.front(); Q.pop();
        if(h[cur] - minus <= 0) continue;
        minus += d[cur];
        h[cur] += d[cur];
        Q.push(cur);
    }
    cout<<Q.front()+1;
    return 0;
}
