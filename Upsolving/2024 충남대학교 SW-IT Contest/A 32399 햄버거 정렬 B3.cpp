#include <bits/stdc++.h>
using namespace std;

int solve(string S){
    if(S=="(1)") return 0;
    if(S=="()1") return 1;
    if(S=="1()") return 1;
    if(S=="1)(") return 1;
    if(S==")1(") return 2;
    if(S==")(1") return 1;
}

int main(){
    string S; cin>>S;
    cout<<solve(S);
    return 0;
}
