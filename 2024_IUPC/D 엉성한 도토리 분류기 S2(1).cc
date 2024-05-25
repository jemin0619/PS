//이번에는 모노톤 큐 + 오프라인 쿼리로 풀어보았습니다.
//N이 작아 DP 풀이도 존재하지만 굳이 풀어보진 않겠습니다...
//이분탐색이 일반적인 풀이라는 생각이 들지만 이 풀이가 더 재밌습니다.
//앞으로 알고리즘에 "단조성"이 관찰되면 모노톤 큐 풀이를 생각해 볼 수 있겠습니다.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> Pll;
#define X first
#define Y second

deque<Pll> v;
vector<Pll> Query;
ll ans[100'003];
ll N, Q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        ll x; cin>>x;
        x += i;
        if(v.empty() || v.back().first<x) v.push_back({x, i+1});
    }

    cin>>Q;
    for(int i=0;i<Q;i++){
        ll x; cin>>x;
        Query.push_back({x,i});
    }
    sort(Query.begin(),Query.end());

    for(int i=0;i<Q;i++){
        while(!v.empty()&&v.front().X<Query[i].X) v.pop_front();
        ans[Query[i].Y]=v.front().Y;
    }

    for(int i=0;i<Q;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
