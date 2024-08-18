#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define ff first
#define ss second
#define pii pair<ll,ll>
#define tiii tuple<ll,ll,ll>
#define pb push_back

int N, M;

int main(){
    fastio;
    cin>>N>>M;
    vector<int> V(N+3);
    for(int i=1; i<=N; i++){
        cin>>V[i]; V[i]+=V[i-1];
        V[i] = max(0, V[i]);
    }
    int ans = 0;
    for(int i=1;i<=N;i++){
        if(V[i]>=M) ans++;
    }
    cout<<ans;
    return 0;
}

//00:05 AC
