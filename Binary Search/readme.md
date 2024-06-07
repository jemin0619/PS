### [학습자료](https://blog.naver.com/jinhan814/222607789392)

# 이분 탐색 (Binary Search)
- 결정 문제에서 답이 이분적일 때 사용할 수 있는 탐색기법
- 경계를 포함하는 구간 [lo, hi]를 잡은 뒤 구간의 길이를 절반씩 줄여가며 [lo, hi]가 경계에 위치하도록 하는 아이디어를 사용
- 시간복잡도는 check(mid)의 시간복잡도가 O(T)일 때 O(T*log(n))

### [BOJ 2805 나무 자르기](https://www.acmicpc.net/problem/2805)

```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

vector<ll> V;
ll N, M;

bool Check(ll x){
    ll sum = 0;
    for(int v : V){
        if(v > x) sum += (v-x);
    }
    return sum >= M;
}

int main(){
    fastio;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        ll x; cin>>x;
        V.push_back(x);
    }

    ll lo = 0, hi = 1e9;
    while(lo+1 < hi){
        ll mid = (hi+lo)/2;
        if(Check(mid)) lo = mid;
        else hi = mid;
    }
    cout<<lo;
    return 0;
}
```

원래 이분탐색에서의 범위 설정이 어렵게 느껴졌는데 글을 읽고 갈피를 잡을 수 있었다.


lo와 hi가 무엇을 의미하는지 더욱 직관적으로 알 수 있게 되었다.
