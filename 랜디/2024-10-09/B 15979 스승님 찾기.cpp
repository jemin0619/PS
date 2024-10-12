//GCD 문제라는 것은 바로 알 수 있다.
//답은 0에서 2 사이라는 것도 유도할 수 있으므로 case work를 해준다.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    int N, M; cin>>N>>M;
    if(N==0 && M==0) {cout<<0; return 0;}
    if(gcd(N, M)==1) {cout<<1; return 0;}
    else cout<<2;
    return 0;
}
