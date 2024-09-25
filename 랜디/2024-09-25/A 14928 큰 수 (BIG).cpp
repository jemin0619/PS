//파이썬이면 딸깍 한번에 풀리는데, 의도는 그게 아니었을 것이다...
//모듈러 연산의 특징을 파악해야 한다.
//https://blog.naver.com/dlscjs8646/222209820247

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
const ll MOD = 20000303;

int main(){
    fastio;
    string S; cin>>S;
    ll ans = 0;
    for(int i=0; i<S.size(); i++){
        ans = (10*ans+(S[i]-'0'))%MOD; 
    }
    cout<<ans;
    return 0;
}
