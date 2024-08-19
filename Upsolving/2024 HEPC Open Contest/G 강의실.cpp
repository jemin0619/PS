#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ff first 
#define ss second
#define ll long long

int main(){
    fastio;
    ll N, K;
    cin>>N>>K;
    vector<ll> V(N);
    for(int i=0; i<N; i++) cin>>V[i];
    sort(V.begin(), V.end());

    vector<ll> gap;
    ll pre = 0;

    for(ll val : V){
        gap.push_back(val-pre);
        pre = val;
    }

    sort(gap.begin(), gap.end());

    while(!gap.empty() && K--){
        gap.pop_back();
    }

    ll Ans = 0;
    for(ll val : gap){
        Ans += val;
    }

    cout<<Ans;
    return 0;   
}

//먼 길을 이동하는데 순간이동을 쓰는 것이 항상 이득이다.
//그러므로 강의실 간 거리의 차를 gap 배열에 전부 담은 뒤, 정렬 후 큰 값부터 K개 골라 빼준다.
//그 이후 gap 배열 내 원소의 총합이 답이 된다.

//01:35 AC
