#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long;

int main() {
    fastio;
    int t; cin>>t;
    while(t--){
        string A, B; cin>>A>>B;
        reverse(A.begin(), A.end());
        reverse(B.begin(), B.end());
        string C = to_string(stoll(A)+stoll(B));
        reverse(C.begin(), C.end());
        cout<<stoll(C)<<'\n';
    }
    return 0;
}
