#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int a1, a0, c, n0; cin>>a1>>a0>>c>>n0;
    if(a1*n0 + a0 <= c*n0 && a1<=c) cout<<1;
    else cout<<0;
    return 0;
}
