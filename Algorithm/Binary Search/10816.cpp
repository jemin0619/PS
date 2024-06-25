//https://www.acmicpc.net/problem/10816

//upperbound - lowerbound -> 개수

#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int m; cin>>m;
    while(m--){
        int t; cin>>t;
        cout<<upper_bound(a,a+n,t)-lower_bound(a,a+n,t)<<' ';
    }
    return 0;
}
