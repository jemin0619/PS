#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    vector<int> V(3);
    V[0] = 1;

    string S; cin>>S;
    for(char c : S){
        if(c=='A') swap(V[0], V[1]);
        if(c=='B') swap(V[1], V[2]);
        if(c=='C') swap(V[0], V[2]);
    }
    for(int i=0; i<3; i++){
        if(V[i]==1) {cout<<i+1; return 0;}
    }
    return 0;
}
