//O(N) or O(NlogN)만 가능

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define pii pair<ll,ll>
#define tiii tuple<ll,ll,ll>
#define vi vector<ll>

void solve(){
    int N; cin>>N;
    vi a(N);
    vi chk(N+1);
    for(int i=0; i<N; i++) {cin>>a[i]; chk[a[i]]++;}
    for(int i=0; i<N; i++){
        if((N-2)%a[i]==0){
            int x = (N-2)/a[i];
            if(a[i]==x){ //edge case : 두 수가 같은 수라면
                if(chk[x]>=2) {cout<<x<<' '<<x<<'\n'; return;}
            }
            else{ //일반적인 경우
                if(chk[x]>=1) {cout<<a[i]<<' '<<x<<'\n'; return;}
            }
        }
    }
}

int main(){
    fastio;
    int tc; cin>>tc;
    while(tc--) solve();
    return 0;
}
