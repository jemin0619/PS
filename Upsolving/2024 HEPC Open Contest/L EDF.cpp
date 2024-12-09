//구현에서 실수가 너무 많았어요...

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define pii pair<ll,ll>
#define tiii tuple<ll,ll,ll>

ll N, M;
priority_queue<pii, vector<pii>, greater<pii>> PQ1;
priority_queue<tiii, vector<tiii>, greater<tiii>> PQ2;

int main(){
    fastio;
    cin>>N;
    while(N--){
        ll t,d; cin>>t>>d;
        PQ1.push({d, t});
    }
    cin>>M;
    while(M--){
        ll w,t,d; cin>>w>>t>>d;
        PQ2.push({w, d, t});
    }
    ll ans = 0;
    while(!PQ1.empty()){
        auto[curD, curT] = PQ1.top(); PQ1.pop();
        ll endT = ans + curT;
        if(endT>curD) {cout<<"NO"; return 0;}
        if(PQ2.empty()) {ans = endT; continue;}
        auto[nxtW, nxtD, nxtT] = PQ2.top();
        if(nxtW >= endT) {ans = endT; continue;}
        curT -= nxtW - ans;
        PQ1.push({curD, curT});
        ans = nxtW;
        PQ1.push({nxtD, nxtT}); PQ2.pop();
    }
    while(!PQ2.empty()){
        auto[curW, curD, curT] = PQ2.top(); PQ2.pop();
        ans = max(curW, ans); //이거 한 줄을 빼서 8 WA...
        ll endT = ans + curT;
        if(endT>curD) {cout<<"NO"; return 0;}
        ans = endT;
    }
    cout<<"YES\n"<<ans;
    return 0;
}
