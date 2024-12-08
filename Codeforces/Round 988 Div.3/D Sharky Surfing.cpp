//그리디 + 우선순위 큐
//Jump Power = K로 계속 가다가 가지 못하는 경우, 
//우선순위 큐에 있는 값들 중 가장 큰 값을 골라서 Jump Power을 키우면 된다.

//구간 L~R을 넘기려면, L-1에서 시작해서 R+1로 가야 하므로, R-L+2보다 크거나 같은 K가 필요하다.
//입력은 정렬된 채로 들어오고, 조건도 깔끔해서 맘에 드는 문제였다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define pii pair<ll,ll>
#define tiii tuple<ll,ll,ll>
#define vi vector<ll>

void solve(){
    ll n,m,l; cin>>n>>m>>l;
    priority_queue<ll> PQ;
    queue<pii> Hud;
    queue<pii> Pow;
    for(int i=0; i<n; i++){
        int a,b; cin>>a>>b;
        Hud.push({a, b});
    }
    for(int i=0; i<m; i++){
        int a,b; cin>>a>>b;
        Pow.push({a, b});
    }
    ll ans = 0;
    ll K = 1;
    while(!Hud.empty()){
        auto[L,R] = Hud.front(); Hud.pop();
        while(!Pow.empty() && Pow.front().first<L){
            PQ.push(Pow.front().second);
            Pow.pop();
        }
        while(!PQ.empty() && R-L+2>K){
            K += PQ.top();
            PQ.pop();
            ans++;
        }
        if(R-L+2>K) {cout<<"-1\n"; return;}
    }
    cout<<ans<<'\n';
}

int main(){
    fastio;
    int tc; cin>>tc;
    while(tc--) solve();
    return 0;
}
