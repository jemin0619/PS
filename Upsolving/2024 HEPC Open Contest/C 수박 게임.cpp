#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int N, K; cin>>N>>K;
    N--;
    while(N--) K /= 2;
    cout<<K;
    return 0;
}

//00:11 WA
//00:12 WA
//00:13 AC
