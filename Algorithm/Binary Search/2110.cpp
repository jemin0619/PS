//https://www.acmicpc.net/problem/2110

//Check(mid) 두 공유기 사이의 최소 거리가 mid가 되게 공유기를 C개 이상 배치할 수 있는가?
//C개 이상 배치할 수 있어야하는 이유는 C개를 설치하고 남은 개수는 설치되지 않아도 가장 인접한 두 공유기 사이 거리가 mid로 유지됨
//TTFF로 구성되므로 lo를 출력

//idx를 구할 때 범위가 V.begin()+idx ~ 이므로 무한 루프에 빠지지 않는다.
//lo가 0인 경우는 존재하지 않아 1로 했고, hi는 V의 최댓값이 10^9이므로 그보다 하나 큰 10^9 +1로 해서 Check(hi)=F가 항상 성립하게 한다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

ll N,C;
vector<ll> V;

bool Check(ll x){
    ll cnt=0, idx=0;
    while(idx<N){
        idx = lower_bound(V.begin()+idx, V.end(), V[idx]+x) - V.begin();
        cnt++;
    }
    return cnt >= C;
}

int main(){
    fastio;
    cin>>N>>C;
    for(int i=0;i<N;i++){
        ll x; cin>>x;
        V.push_back(x);
    }
    sort(V.begin(),V.end());

    ll lo=1, hi=1e9+1;
    while(lo+1<hi){
        ll mid = (lo+hi)/2;
        if(Check(mid)) lo=mid;
        else hi=mid;
    }
    cout<<lo;
    return 0;
}
