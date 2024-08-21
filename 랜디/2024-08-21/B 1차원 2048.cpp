#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int main(){
    fastio;
    int N; cin>>N;
    ll mx = 0;
    priority_queue<ll, vector<ll>, greater<ll>> PQ;
    for(int i=0; i<N; i++){
        ll x; cin>>x;
        if(x==0) continue;
        PQ.push(x);
    }
    while(PQ.size()>=2){
        ll pre = PQ.top(); PQ.pop();
        ll cur = PQ.top(); PQ.pop();
        mx = max({pre, cur, mx});
        if(pre==cur) PQ.push(pre+cur);
        else PQ.push(cur);
    }
    while(!PQ.empty()){
        mx = max(PQ.top(), mx);
        PQ.pop();
    }
    cout<<mx;
    return 0;
}
