#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define ff first
#define ss second
#define pii pair<ll,ll>
#define tiii tuple<ll,ll,ll>
#define pb push_back

int main(){
    fastio;
    int N; cin>>N;
    string A="", B="";
    for(int i=0; i<N; i++){
        string c; cin>>c;
        A+=c;
    }
    for(int i=0; i<N; i++){
        string c; cin>>c;
        B+=c;
    }
    ll a = stoll(A); ll b = stoll(B);
    cout<<min(a,b);
    return 0;
}

//00:12 AC
