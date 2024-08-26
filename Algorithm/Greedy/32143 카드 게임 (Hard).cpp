//카드를 버리면 그 카드는 이후에도 쓸모가 없다.
//그리디하게 필요한 카드만 남기면서 해결한다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int main(){
    fastio;
    ll H,N,Q; cin>>H>>N>>Q;
    priority_queue<ll, vector<ll>, greater<ll>> PQ;
    ll sum = 0;
    for(int i=1; i<=N; i++){
        ll x; cin>>x;
        sum += x;
        PQ.push(x);
    }
    
    while(!PQ.empty() && sum-PQ.top()>=H){
        sum -= PQ.top();
        PQ.pop();
    }

    if(sum<H) cout<<-1<<'\n';
    else cout<<PQ.size()<<'\n';

    while(Q--){
        ll x; cin>>x;
        sum += x; 
        PQ.push(x);
        while(!PQ.empty() && sum-PQ.top()>=H){
            sum -= PQ.top();
            PQ.pop();
        }
        if(sum<H) cout<<-1<<'\n';
        else cout<<PQ.size()<<'\n';
    }
    return 0;
}
