//n-1번째 짚단을 빼면, 나머지는 원하는대로 골라갈 수 있다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int main(){
    fastio;
    int n; cin>>n;
    int ans = 0;
    vector<int> a(n+1), b(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];
    a[n] += b[n-1];
    b[n] += a[n-1];
    int mx = max(a[n], b[n]);
    int mn = min(a[n], b[n]);
    for(int i=1; i<=n-2; i++){
        mx += max(a[i], b[i]);
        mn += min(a[i], b[i]);
    }
    cout<<abs(mx-mn);
    return 0;
}
