//C++로 하면 중간에 Break 없어도 되지만, 
//Python의 경우 그걸 빼면 TLE를 받는다
//상수 커팅도 전략입니다...

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int main(){
    fastio;
    ll N, M; cin>>N>>M;
    vector<bool> chk(1003, false);
    for(int i=0; i<M; i++){
        int x; cin>>x;
        chk[x] = true;
    }
    ll ans = 0x7f7f7f7f;
    for(int i=1; i<=1002; i++){
        if(chk[i]) continue;
        for(int j=i; j<=1002; j++){
            if(chk[j]) continue;
            for(int k=j; k<=1002; k++){
                if(chk[k]) continue;
                ans = min(ans, abs(N - i*j*k));
            }
        }
    }
    cout<<ans;
    return 0;
}
