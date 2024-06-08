### [학습자료](https://blog.naver.com/jinhan814/222607789392)

# 이분 탐색 (Binary Search)
- 결정 문제에서 답이 이분적일 때 사용할 수 있는 탐색기법
- 경계를 포함하는 구간 [lo, hi]를 잡은 뒤 구간의 길이를 절반씩 줄여가며 [lo, hi]가 경계에 위치하도록 하는 아이디어를 사용
- 시간복잡도는 check(mid)의 시간복잡도가 O(T)일 때 O(T*log(n))

## [BOJ 2805 나무 자르기](https://www.acmicpc.net/problem/2805)

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

## [BOJ 2792 보석 상자](https://www.acmicpc.net/problem/2792)

```cpp
//모든 보석을 나눠줘야 하고, 한 사람은 같은 색의 보석만 가져갈 수 있음
//Check(Mid) : 한 사람이 가져갈 수 있는 최대 보석 개수(질투심)를 Mid개로 정할 수 있는가?
//FT로 존재하므로 hi를 출력한다. (질투심 제한을 늘릴수록 모든 보석을 사람들에게 나눠줄 수 있음 (못받는사람도 존재) , M<=N)

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

ll N,M; //사람수 보석수
vector<ll> V;

bool Check(ll x){ 
    ll num = 0; //나누어진 보석 묶음의 개수
    for(ll val : V){
        num += (val/x + (val%x!=0));
    }
    //보석 묶음의 개수가 사람들 수보다 작거나 같으면 모든 보석을 나눠줄 수 있다.
    return num<=N;
}

int main(){
    fastio;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        ll x; cin>>x;
        V.push_back(x);
    }
    
    ll lo=0, hi=1e9;
    while(lo+1<hi){
        ll mid = (lo+hi)/2;
        if(Check(mid)) hi=mid;
        else lo=mid;
    }
    cout<<hi;
    return 0;
}
```
+ lo, hi 범위 구하기
    - 처음 풀 때 lo를 1로 해서 틀렸었다.
    - lo와 hi를 잡을 땐 파라미터가 FFTT로 존재한다면 Check(lo)=F Check(hi)=T로, TTFF라면 반대로 잡아야 한다.
    - lo가 1이면 3 3 1 1 1 같은 TC에선 1로도 모든 보석을 나눠줄 수 있기에 TTTT가 되어서 잘못된 답을 출력한다.
