#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio cin.tie(NULL)->sync_with_stdio(false);

ll N,M;
vector<ll> A,B;
vector<pair<ll,ll>> V;

int main(){
    fastio;
    cin>>N>>M;
    for(int i=0;i<N;i++) {ll x; cin>>x; A.push_back(x);}
    for(int i=0;i<N;i++) {ll x; cin>>x; B.push_back(x);}
    for(int i=0;i<N;i++){
        //pair로 지불 비용과 이익 저장
        //이익이 음수인 경우엔 continue
        ll cost = A[i];
        ll payoff = B[i]-A[i];
        if(payoff<=0) continue;
        V.push_back({cost,payoff});
    }
    sort(V.begin(),V.end());
    for(auto val : V){
        if(M<val.first) break;
        M += val.second;
    }
    cout<<M;
    return 0;
}
