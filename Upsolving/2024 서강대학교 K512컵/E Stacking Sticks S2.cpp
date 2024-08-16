//간단한 쿼리형 문제입니다.
//음수 좌표의 높이를 올려야 하기 때문에 Map으로 구현합니다.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll Q;
map<ll,ll> M;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>Q;
    while(Q--){
        ll a,b; cin>>a>>b;
        if(a==1){
            ll mx = max({M[b],M[b+1],M[b+2],M[b+3]});
            M[b] = M[b+1] = M[b+2] = M[b+3] = mx+1;
        }
        if(a==2) M[b]+=4;
        if(a==3) cout<<M[b]<<'\n';
    }
    return 0;
}
