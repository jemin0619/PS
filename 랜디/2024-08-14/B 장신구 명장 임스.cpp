#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    int P, N; cin>>P>>N;
    vector<int> V(N);
    for(int i=0; i<N; i++) cin>>V[i];
    sort(V.begin(), V.end());
    int ans = 0;
    for(int val : V){
        if(P<200) {ans++; P+=val;}
        else break;
    }
    cout<<ans;
    return 0;
}
