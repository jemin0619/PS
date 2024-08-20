#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int N, M; cin>>N>>M;
    if(N<M) cout<<M-N;
    else cout<<N+M;
    return 0;
}
