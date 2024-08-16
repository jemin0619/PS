//입력되는 수가 최소 0이므로 음수가 들어오지 않습니다.
//최댓값을 만들려면 덧셈 연산을 모두 수행한 뒤, 0이 아닌 값들만 곱셈 연산을 수행하면 됩니다.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N,M;
vector<ll> Vn;
vector<ll> Vm;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        ll x; cin>>x;
        Vn.push_back(x);
    }
    for(int j=0;j<M;j++){
        ll x; cin>>x;
        Vm.push_back(x);
    }
    ll ans=0;
    for(ll val : Vn) ans+=val;
    for(ll val : Vm){
        if(val!=0) ans *= val;
    }
    cout<<ans;
    return 0;
}
