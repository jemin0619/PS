//https://www.acmicpc.net/problem/31848

//이분탐색 풀이가 정해지만 오프라인 쿼리를 곁들인 모노톤 큐 풀이도 존재합니다.
//항상 자료구조 속의 자료가 오름차순/내림차순으로 존재하기에 이런 모습이 단조롭다는 뜻에서 Monotone 이라고 정의한 것 같습니다.

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
