//해 구성하기 + 정수론 + 그리디
//이거 진짜 말이 안된다... 단기간 연습으로는 힘들듯

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define pii pair<ll,ll>
#define tiii tuple<ll,ll,ll>
#define vi vector<ll>

void solve(){
    int N; cin>>N;
    if(N<=4) {cout<<"-1\n"; return;}
    //짝수 + 짝수 = 합성수
    //홀수 + 홀수 = 합성수
    //짝수와 홀수를 분리하고, 둘을 잇는 부분만 잘 설정하면 된다.
    //5부터만 만들 수 있으므로, 4-5로 해주는게 편하다.
    for(int i=1; i<=N; i++){
        if(i%2==0 && i!=4) cout<<i<<' ';
    } cout<<"4 5 ";
    for(int i=1; i<=N; i++){
        if(i%2==1 && i!=5) cout<<i<<' ';
    } cout<<'\n';
}

int main(){
    fastio;
    int tc; cin>>tc;
    while(tc--) solve();
    return 0;
}
