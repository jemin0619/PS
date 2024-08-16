//수학, 그리디
//모두의 돈을 avg로 맞추고, mod명에게만 1씩 더 갖게 해줍니다
//정렬을 해줘야 mod명에게 1씩 더 갖게 하는 전략을 쉽게 구현할 수 있습니다.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll N; cin>>N;
    vector<ll> V(N);
    ll sum = 0;
    for(int i=0;i<N;i++){
        cin>>V[i]; sum+=V[i];
    }
    ll avg = sum / N;
    ll mod = sum % N;
    ll Ans = 0;
    sort(V.rbegin(),V.rend());
    for(int i=0;i<N;i++){
        ll val = avg + (i<mod);
        if(V[i]>val) Ans += (V[i]-val);
    }
    cout<<Ans;
    return 0;
}
