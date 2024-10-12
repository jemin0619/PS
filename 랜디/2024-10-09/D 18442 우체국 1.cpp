//L이 상당히 커서 기본값을 그냥 1e18로 박았다.
//1e18로 안두고 21억으로 두어서 몇번 WA를 받았고, k==V를 k==V+1로 두어 WA를 받았다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

vector<ll> ans;
vector<ll> arr;
vector<ll> tmp;
ll res=1e18;
ll V,P,L;

void func(int k){
    if(tmp.size()==P){
        ll value = 0;
        for(ll val1 : arr){
            ll mn = 1e18;
            for(ll val2 : tmp) mn = min({mn, abs(val1-val2), L-abs(val1-val2)});
            value += mn;
        }
        if(value<res){
            res = value;
            ans = tmp;
        }
        return;
    }
    if(k==V) return;

    tmp.push_back(arr[k]);
    func(k+1);
    tmp.pop_back();

    func(k+1);
}

int main(){
    fastio;
    cin>>V>>P>>L;
    arr.resize(V);
    for(int i=0; i<V; i++) cin>>arr[i];
    func(0);
    cout<<res<<'\n';
    for(ll val : ans) cout<<val<<' ';
    return 0;
}
