//우선순위 큐 풀이가 바로 떠올랐다.
//나코더 C번 치고는 쉬웠다는 생각이 든다.

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
