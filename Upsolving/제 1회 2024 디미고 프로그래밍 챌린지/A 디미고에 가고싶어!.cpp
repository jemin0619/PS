//책자의 구성방식을 무시하면 WA를 받는다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define ff first
#define ss second
#define pii pair<ll,ll>
#define tiii tuple<ll,ll,ll>
#define pb push_back

int main(){ 
    fastio;
    int N, M; cin>>N>>M;
    if(N%2==1) cout<<(M-N+1)/2 + (M-N+1)%2;
    else cout<<(M-(N+1)+1)/2 + (M-(N+1)+1)%2 + 1;
    return 0;
}   
