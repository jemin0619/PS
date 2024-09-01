//스페셜 저지가 없어도 될 것 같긴 하다. 
//그리디, 정렬

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
    int N, M; cin>>N>>M;
    int standard = -1;
    vector<pair<int,int>> V;
    for(int i=0; i<=N; i++){
        int a,b,c; cin>>a>>b>>c;
        if(standard==-1) standard = a+b+c;
        else if(a+b+c<=standard) V.push_back({a+b+c, i});
    }
    sort(V.rbegin(), V.rend());
    vector<int> ans;
    ans.push_back(0);

    for(int i=0; i<M-1; i++){
        if(V.size()==i) break;
        ans.push_back(V[i].ss);
    }

    sort(ans.begin(), ans.end());
    for(int val : ans){
        cout<<val<<' ';
    }
    return 0;
}   
