#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    int A, B, C; cin>>A>>B>>C;
    cout<<A+B-C<<'\n';
    string tmp = to_string(A) + to_string(B);
    cout<<stoll(tmp)-C;
    return 0;
}
