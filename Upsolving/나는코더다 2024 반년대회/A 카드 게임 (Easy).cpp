#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, H; cin>>N>>H;
    vector<int> V(N);
    for(int i=0; i<N; i++) cin>>V[i];
    int idx = 0;
    while(H>0 && idx<N){
        H -= V[idx++];
    }
    if(H<=0) cout<<idx;
    else cout<<-1;
    return 0;
}
