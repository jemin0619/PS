#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int N; cin>>N; N*=2;
    map<string, vector<string>> Mp;
    while(N--){
        string A,B; cin>>A>>B;
        Mp[A].push_back(B);
    }
    for(auto val : Mp){
        cout<<val.second[0]<<' '<<val.second[1]<<'\n';
    }
    return 0;
}
