//https://www.acmicpc.net/problem/31848

//이분탐색 풀이가 정해지만 오프라인 쿼리를 곁들인 모노톤 큐 풀이도 존재합니다.

//도토리의 크기가 점점 줄어드는 것을 구멍의 크기가 점점 커지는 것으로 표현할 수 있습니다.
//그러므로 덱에 pair로 {크기, 인덱스}를 저장해놓습니다. 크기는 점점 커지는 것을 적용한 상태로 넣습니다.

//입력되는 각 쿼리도 {x, 인덱스} 쌍으로 저장해놓습니다.
//쿼리들을 정렬시키면 작은 도토리가 앞에, 큰 도토리가 뒤에 위치하게 됩니다.
//작은 도토리부터 덱의 front와 비교하면서 도토리가 구멍에 들어갈 수 있다면 Ans[쿼리의 인덱스] = 덱.front().인덱스 로 그 쿼리에 대한 답을 Ans 배열에 저장합니다.
//도토리가 구멍에 들어갈 수 없다면 덱의 front를 pop시키고, 구멍에 들어갈때까지 이를 반복합니다.
//문제 조건에 주어진 입력 조건에서는 모든 도토리가 빠져나올 수 있다고 했으므로 덱이 비어버리는 상황을 생각하지 않아도 됩니다.

//이 풀이가 성립하는 이유는 도토리를 크기에 대해 오름차순으로 정렬시켰기에 현재 구멍에 도토리 i가 들어가지 않는다면 도토리 i+1도 들어가지 않기 때문입니다.

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
