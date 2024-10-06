//처음에 x의 제한을 보지 못하고 O(N) 알고리즘을 짰는데, 그러면 안됐다.
//O(sqrt(N)) 알고리즘으로 통과했다.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n; cin>>n;
    n++;
    vector<ll> ans;
    for(int i=1; i<=sqrt(n); i++){
        if(n%i==0){
            ans.push_back(i);
            if(i != n/i) ans.push_back(n/i);
        }
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size()-1; i++) cout<<ans[i]<<' ';
    return 0;
}
