# Segment Tree 2
### - 구간 트리
[문제집 1 링크](https://www.acmicpc.net/group/workbook/view/20184/71476) | [문제집 2 링크](https://www.acmicpc.net/group/workbook/view/20184/72226) | [문제집 3 링크](https://www.acmicpc.net/group/workbook/view/20184/73929)

챕터 1에서는 update로 한 인덱스의 값만을 업데이트했습니다.

그렇다면 **특정 구간에 값을 update**하려면 어떻게 해야 할까요? naive한 구현으로는 **O(NlogN)**이겠지만, 이번에 배울 **Lazy Propagation**을 익힌다면 **O(logN)**에 그대로 처리 가능합니다!!

그러면 **Lazy Propagation**을 배우고, 이를 활용한 문제와 스위핑 등의 기법을 적용한 일반 세그먼트 트리 문제를 풀어봅시다.

추가로, **Binary Indexed Tree(BIT)**, 혹은 **Fenwick Tree**라고 불리는 트리도 배워봅시다.

+) Merge Sort 과정을 그대로 트리로 옮긴 **Merge Sort Tree**도 다뤄봅시다...

난이도가 좀 있는 내용이고, 코드도 자료구조를 직접 만드는 것이라 지금까지 했던 것에 비해 길고 어렵습니다.

[imos法 자료](https://driip.me/65d9b58c-bf02-44bf-8fba-54d394ed21e0)

[Lazy Propagation 자료 1](https://www.youtube.com/watch?v=dJpNh7R4LM8) | [Lazy Propagation 자료 2](https://justicehui.github.io/medium-algorithm/2018/08/24/Seg2/)

[펜윅 트리 자료 1](https://ps.mjstudio.net/fenwick-tree) | [펜윅 트리 자료 2](https://nahwasa.com/entry/%ED%8E%9C%EC%9C%85-%ED%8A%B8%EB%A6%ACFenwick-tree-BIT-%EA%B8%B0%EB%B3%B8-2D-lazy-propagationrange-update-point-query-range-update-range-query#%ED%8E%9C%EC%9C%85_%ED%8A%B8%EB%A6%AC%EB%9E%80?)

[머지 소트 트리 자료 1](https://justicehui.github.io/medium-algorithm/2020/02/25/merge-sort-tree/) | [머지 소트 트리 자료 2](https://pooreumjung.tistory.com/314)
***

[2835 인기도 조사 G3](https://www.acmicpc.net/problem/2835)

세그먼트 트리는 솔직히 오버킬이고, 누적 합 풀이가 더 깔끔합니다. 직접 풀어봅시다!

***

[15967 에바쿰 P4](https://www.acmicpc.net/problem/15967)

Tag : **Segment Tree**, **Lazy Propagation**

구간 update를 naive하게 구현하면 N개의 연속된 구간에 같은 수를 더하는 연산을 진행하기에 O(NlogN)입니다. 이를 최적화시키기 위해서, update 연산마다 리프 노드까지 도달하는 것이 아니라 연산에 필요한 노드까지만 전파시키면서 겹치는 계산을 제거하는게 **Lazy Propagation**의 핵심입니다. init 함수 없이 range_update로 세그먼트 트리를 채우게 되면 실행 시간이 조금 느려진다는 것을 기억합시다!! + [10999 구간 합 구하기 2 P4](https://www.acmicpc.net/problem/10999)와 같은 문제입니다. (쿼리 순서만 바뀜)

또 굳이 template으로 안만들고, 그냥 짜도 됩니다. 저는 재사용을 쉽게 하기 위해 template으로 짰습니다.

```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

template <typename T>
struct LazySeg{
    int N;
    vector<ll> V;
    vector<ll> lazy;
    vector<ll> seg;
    LazySeg(int N):N(N){V.resize(N); lazy.resize(N*4); seg.resize(N*4);}
    T merge(T left, T right){
        return left + right;
    }
    T init(int node, int leftNode, int rightNode){
        if(leftNode==rightNode) return seg[node] = V[leftNode];
        ll mid = leftNode+rightNode; mid/=2;
        T leftVal = init(node*2, leftNode, mid);
        T rightVal = init(node*2+1, mid+1, rightNode);
        return seg[node] = merge(leftVal, rightVal);
    }
    void lazy_prop(int node, int leftNode, int rightNode){
        if(!lazy[node]) return;
        seg[node] += (rightNode-leftNode+1)*lazy[node];
        if(rightNode!=leftNode){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    void update_range(int left, int right, T val, int node, int leftNode, int rightNode){
        lazy_prop(node, leftNode, rightNode);
        if(rightNode<left || right<leftNode) return;
        if(left<=leftNode && rightNode<=right){
            seg[node] += (rightNode-leftNode+1)*val;
            if(leftNode!=rightNode){
                lazy[node*2] += val;
                lazy[node*2+1] += val;
            }
            return;
        }
        ll mid = leftNode+rightNode; mid/=2;
        update_range(left, right, val, node*2, leftNode, mid);
        update_range(left, right, val, node*2+1, mid+1, rightNode);
        seg[node] = merge(seg[node*2], seg[node*2+1]);
    }
    T query(int left, int right, int node, int leftNode, int rightNode){
        lazy_prop(node, leftNode, rightNode);
        if(rightNode<left || right<leftNode) return 0;
        if(left<=leftNode && rightNode<=right) return seg[node];
        ll mid = leftNode+rightNode; mid/=2;
        ll leftVal = query(left, right, node*2, leftNode, mid);
        ll rightVal = query(left, right, node*2+1, mid+1, rightNode);
        return merge(leftVal, rightVal);
    }
};

int main(){
    fastio;
    int N,Q1,Q2; cin>>N>>Q1>>Q2;
    LazySeg<ll> seg(N);
    for(int i=0; i<N; i++) cin>>seg.V[i];
    seg.init(1, 0, N-1);
    for(int i=0; i<Q1+Q2; i++){
        int q; cin>>q;
        if(q==1){
            ll a,b; cin>>a>>b;
            cout<<seg.query(--a, --b, 1, 0, N-1)<<'\n';
        }
        if(q==2){
            ll a,b,c; cin>>a>>b>>c;
            seg.update_range(--a, --b, c, 1, 0, N-1);
        }
    }
    return 0;
}
```

***

[12844 XOR P3](https://www.acmicpc.net/problem/12844)
- Range Xor Query를 구현해줍시다.
- 같은 수를 짝수 번 xor 한다면, 0이 된다는 것을 깨달으면 바로 풀 수 있습니다.

[14245 XOR P4](https://www.acmicpc.net/problem/14245)
- 위와 거의 같은 문제입니다.

[1395 스위치 P3](https://www.acmicpc.net/problem/1395)
- Range Not Query를 구현해줍시다. XOR을 풀었으면 충분히 할 수 있습니다!!

[17353 하늘에서 떨어지는 1, 2, ..., R-L+1개의 별 P2](https://www.acmicpc.net/problem/17353)
- 우린 구간에 같은 수를 더하는 연산만 할 수 있습니다. 그러므로 세그먼트 트리에 원소의 수 차이를 저장하게 한 뒤, 구간합을 시키면 됩니다.
- 예를 들어, 3 ~ 5 구간에 update 연산을 한다고 하면, 3 ~ 5에 1을 더해주고, 6에 -3을 해주는 식입니다. 
- 답을 출력할 땐 V[i] + query(1 ~ i)를 해주면 됩니다.
- 코드는 생략합니다.

***

[16975 수열과 쿼리 21 P4](https://www.acmicpc.net/problem/16975)

Tag : **Fenwick Tree (BIT)**

Lazy Propagation으로도 충분히 해결 가능하지만, 펜윅 트리를 사용하면 메모리를 절약하며 짧게 풀 수 있습니다.

또 주의해야 할 점은 구간 update를 적용시킬 경우, sum도 마찬가지로 imos법마냥 사용해야 한다는 점입니다. 여러 번 문제를 풀다 보면 이게 무슨 말인지 이해가 될 것입니다...!
```cpp
//펜윅 트리를 사용해, 구간 update를 imos법처럼 처리할 수 있습니다.
//펜윅 트리 하나만을 사용해 이를 구현하므로, 초기에 수를 update하는 과정에서도 imos법과 같이 처리해주어야 합니다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

template <typename T>
struct fenwick{
    int N;
    vector<T> bit;
    fenwick(int N):N(N){bit.resize(N+1);}
    void update(int i, T val){
        for(;i<=N;i+=i&-i) bit[i]+=val;
    }
    T query(int i){
        T ret = 0;
        for(;i;i-=i&-i) ret+=bit[i];
        return ret;
    }
};

int main(){
    fastio;
    int N; cin>>N;
    fenwick<ll> fw(N);
    for(int i=1; i<=N; i++){
        ll x; cin>>x;
        fw.update(i, x);
        fw.update(i+1, -x);
    }
    int M; cin>>M;
    while(M--){
        int q; cin>>q;
        if(q==1){
            ll a,b,c; cin>>a>>b>>c;
            fw.update(a, c);
            fw.update(b+1, -c);
        }
        else{
            ll a; cin>>a;
            cout<<fw.query(a)<<'\n';
        }
    }
    return 0;
}
```

***

[11658 구간 합 구하기 3 P4](https://www.acmicpc.net/problem/11658)

Tag : **2D Fenwick Tree (BIT)**

2차원 펜윅 트리로 해결이 가능합니다. 

1차원이랑 크게 다르지 않지만, 각 좌표의 값에 접근하는데, query를 통해 접근해야 올바른 값을 가져올 수 있습니다.
```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

template <typename T>
struct fenwick2D{
    int Y, X;
    vector<vector<T>> bit;
    fenwick2D(int Y,int X):Y(Y),X(X){bit.resize(Y+1,vector<T>(X+1));}
    void update(int _y, int _x, T val){
        for(int y=_y; y<=Y; y+=y&-y)
            for(int x=_x; x<=X; x+=x&-x)
                bit[y][x] += val;
    }
    T sum(int _y, int _x){
        if(_y<=0 || _x<=0) return 0;
        T ret = 0;
        for(int y=_y; y; y-=y&-y)
            for(int x=_x; x; x-=x&-x)
                ret += bit[y][x];
        return ret;
    }
    T query(int y1, int x1, int y2, int x2){
        return sum(y2, x2) - sum(y2, x1-1) - sum(y1-1, x2) + sum(y1-1, x1-1);
    }
};

int main(){
    fastio;
    int N,M; cin>>N>>M;
    fenwick2D<ll> fw(N,N);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int x; cin>>x;
            fw.update(i,j,x);
        }
    }
    while(M--){
        int q; cin>>q;
        if(q==0){
            ll a,b,c; cin>>a>>b>>c;
            ll diff = c - fw.query(a,b,a,b); //해당 좌표 값에 직접적으로 접근
            fw.update(a,b,diff);
        }
        else{
            ll a,b,c,d; cin>>a>>b>>c>>d;
            cout<<fw.query(a,b,c,d)<<'\n';
        }
    }
    return 0;
}
```

***

[15646 농부 후안은 바리스타입니다 P4](https://www.acmicpc.net/problem/15646)

Tag : **2D Fenwick Tree (BIT)**

2차원 펜윅 트리로 해결할 수 있습니다. imos법을 적용시킵시다. 
```cpp
//2차원 구간 업데이트가 있으므로, imos법을 적용시킵시다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

template <typename T>
struct fenwick2D{
    int Y,X;
    vector<vector<T>> bit;
    fenwick2D(int Y, int X):X(X),Y(Y){bit.resize(Y+1, vector<T>(X+1));}
    void update(int _y, int _x, T val){
        for(int y=_y; y<=Y; y+=y&-y)
            for(int x=_x; x<=X; x+=x&-x)
                bit[y][x] += val;
    }
    T sum(int _y, int _x){
        T ret = 0;
        for(int y=_y; y; y-=y&-y)
            for(int x=_x; x; x-=x&-x)
                ret += bit[y][x];
        return ret;
    }
};

int main(){
    fastio;
    int N,M,K; cin>>N>>M>>K;
    fenwick2D<ll> fw(N,M);
    while(K--){
        int q; cin>>q;
        if(q==1){
            ll y1,x1,y2,x2,W; cin>>y1>>x1>>y2>>x2>>W;
            fw.update(y1, x1, W);
            fw.update(y2+1, x2+1, W);
            fw.update(y1, x2+1, -W);
            fw.update(y2+1, x1, -W);
        }
        else{
            ll y,x; cin>>y>>x;
            cout<<fw.sum(y,x)<<'\n';
        }
    }
    return 0;
}
```

***

[2820 자동차 공장 P3](https://www.acmicpc.net/problem/2820)

Tag : **2D Fenwick Tree (BIT)**

어려운 문제입니다. 입력이 트리 구조라, 데이터를 약간 변형시켜야 합니다.

DFS로 각 정점마다 커버하는 구간을 left, right로 나눠서 저장해주었습니다.

이후 펜윅 트리로 imos법을 응용하여 각 쿼리에 맞게 구간 update를 해주고, sum도 적당히 해주면 됩니다.
```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

template <typename T>
struct fenwick{
    int N;
    vector<T> bit;
    fenwick(int N):N(N){bit.resize(N+1);}
    void update(int i, T val){
        for(;i<=N;i+=i&-i) bit[i]+=val;
    }
    T sum(int i){
        T ret = 0;
        for(;i;i-=i&-i) ret+=bit[i];
        return ret;
    }
};

int N, M;
vector<ll> salary;
vector<vector<int>> adj;
vector<int> l,r;

int idx = 0;
void DFS(int cur){
    l[cur] = ++idx;
    for(int nxt : adj[cur]) DFS(nxt);
    r[cur] = idx;
}

int main(){
    fastio;
    cin>>N>>M;
    salary.resize(N+1); 
    adj.resize(N+1);
    l.resize(N+1); 
    r.resize(N+1);
    fenwick<ll> fw(N+1);
    cin>>salary[1];
    for(int i=2; i<=N; i++){
        int pa;
        cin>>salary[i]>>pa;
        adj[pa].push_back(i);
    }
    DFS(1);
    while(M--){
        char c; cin>>c;
        if(c=='p'){
            ll a,b; cin>>a>>b;
            fw.update(l[a]+1, b);
            fw.update(r[a]+1, -b);
        }
        if(c=='u'){
            int a; cin>>a;
            cout<<salary[a] + fw.sum(l[a])<<'\n';
        }   
    }
    return 0;
}
```

***

[17353 하늘에서 떨어지는 1, 2, ..., R-L+1개의 별 P2](https://www.acmicpc.net/problem/17353)

Tag : **2D Fenwick Tree (BIT)**

이전엔 **Lazy Propagation**으로 풀었는데, 펜윅 트리로 풀어보겠습니다.

**Lazy Propagation**에서는 무지성으로 구현만 하면 됐지만, **BIT**로 풀려면 약간의 관찰이 필요합니다.

**관찰 1. L~R update 이후 인덱스 x에는 x-L+1이 더해진다.**

**관찰 2. 매 쿼리마다 출력할 답은 update횟수\*(idx+1) - sum(idx) + V[idx] 이다.**
- 이는 -sum(idx)로 -L을 커버해주고, x+1은 update 횟수만큼만 더해져야 하기 때문입니다.
- update 횟수 또한 펜윅 트리로 imos법을 적용시켜 관리해줄 수 있습니다.

```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

template <typename T>
struct fenwick{
    int N;
    vector<T> bit;
    fenwick(int N):N(N){bit.resize(N+1);}
    void update(int i, T val){
        for(;i<=N;i+=i&-i) bit[i]+=val;
    }
    T sum(int i){
        T ret = 0;
        for(;i;i-=i&-i) ret+=bit[i];
        return ret;
    }
};

int main(){
    fastio;
    int N; cin>>N;
    vector<ll> V(N+1);
    fenwick<ll> fw_range(N+1);
    fenwick<ll> fw_cnt(N+1);
    for(int i=1; i<=N; i++) cin>>V[i];
    int M; cin>>M;
    while(M--){
        int q; cin>>q;
        if(q==1){
            int a,b; cin>>a>>b;
            fw_range.update(a, a);
            fw_range.update(b+1, -a);
            fw_cnt.update(a, 1);
            fw_cnt.update(b+1, -1);
        }
        if(q==2){
            int a; cin>>a;
            ll ans = V[a] + fw_cnt.sum(a)*(a+1LL) - fw_range.sum(a);
            cout<<ans<<'\n';
        }   
    }
    return 0;
}
```
***

**Random Hard Problems**

[3006 터보소트 P4](https://www.acmicpc.net/problem/3006)
- Counting inversions 응용입니다. 약간 어려운데 조금만 바꾸면 됩니다.

[3653 영화 수집 P4](https://www.acmicpc.net/problem/3653)
- 뭔가 세그먼트 트리의 크기를 계속 늘려가야 할 것 같습니다.
- 하지만 지금까지 배운 내용에선 그것이 불가능하므로, 초기에 크기를 (N+M)*4만큼 잡아주고, N에서 최댓값을 하나씩 늘려나가는 식으로 구현합시다!!

[17131 여우가 정보섬에 올라온 이유 P4](https://www.acmicpc.net/problem/17131)
- V자를 만들어야 합니다. 그러기 위해서는 가운데 한 점만 정하면 됩니다.
- 일단 가장 위의 Y축부터 X좌표가 증가하는 방향으로 스위핑하며 보겠습니다.
- 그렇게 돌면서 V자의 가운데 점을 선택합니다. 
- 그러면 그 점을 기준으로 이전에 있는 별들의 개수 * 다음에 있는 별들의 개수가 그 점을 선택했을 때 나오는 V자의 개수입니다.
- 이 과정이 끝난 뒤에 현재 보고있는 Y좌표의 값들을 전체 update해줍니다.
- 이제 간단하게 구현하면 끝입니다!!

[22876 츠바메가에시 P4](https://www.acmicpc.net/problem/22876)
- 굉장히 어렵습니다... 자세한 풀이는 에디토리얼을 참고합시다.
- 세로축 3번 / 가로축 3번 / 세로 1번 가로 2번 / 세로 2번 가로 1번
- 총 4가지 경우가 존재하는데, 1번, 2번 하는 경우만 간단하게 알아봅시다.
- 한 번의 참격을 결정지으면, 나머지 두 개의 참격은 첫 번째와 두 번째 최댓값을 뽑아오는 쿼리를 통해 결정지을 수 있습니다.
- 물론 결정지은 후에는 그 줄의 값을 모두 빼주는 작업이 필요합니다. (쿼리 끝나면 돌려놓음)
- 제 코드는 그렇게 4000B가 나왔습니다...

[5419 북서풍 P3](https://www.acmicpc.net/problem/5419)
- 2차원 펜윅, 2차원 세그 모두 MLE입니다.
- 이 문제는 1차원 구간 트리와 스위핑을 곁들여 해결할 수 있습니다.
- 그림을 그려보면 x축만 좌표압축하고, Y와 X에 따라 정렬 후 순서대로 처리해주면 된다는 것을 알 수 있습니다.
- 어렵긴 합니다...

[12016 라운드 로빈 스케줄러 P3](https://www.acmicpc.net/problem/12016)

Tag : **Offline Query, Sort, Segment Tree**

풀이가 길어서 파일로 만들었습니다.

펜윅 트리로 구현했는데, 그냥 세그먼트 트리로도 똑같이 할 수 있다는 것을 아시리라 믿습니다!!

[12016 라운드 로빈 스케줄러 해설](https://upload.acmicpc.net/cb835ecd-f136-4dbb-8ee4-f7daa9417687/)

***

[13544 수열과 쿼리 3 P3](https://www.acmicpc.net/problem/13544)

Tag: **Merge Sort Tree**

머지 소트 트리는 머지 소트 과정을 트리로 나타낸 자료구조로, update는 존재하지 않습니다... 

stl에 있는 merge 함수로 깔끔하게 병합을 구현할 수 있습니다.

머지 소트 트리는 쿼리에서 구간 merge를 하지 않습니다. 그렇게 해버린다면 구간을 벡터에 담고 sort하는 것과 크게 다르지 않기 때문입니다.

그래서 이분 탐색을 사용해야만 구간 병합 없이 K보다 큰 수, 작거나 같은 수... 등의 연산을 수행할 수 있습니다.
```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

template <typename T>
struct MergeSortTree{
    int N;
    vector<vector<T>> Tree;
    MergeSortTree(int N):N(N){Tree.resize(4*N);}
    void init(int node, int leftNode, int rightNode, vector<T>&V){
        if(leftNode==rightNode) {Tree[node].push_back(V[leftNode]); return;}
        ll mid = leftNode+rightNode; mid/=2;
        init(node*2, leftNode, mid, V);
        init(node*2+1, mid+1, rightNode, V);
        Tree[node].resize(Tree[node*2].size()+Tree[node*2+1].size());
        merge(Tree[node*2].begin(), Tree[node*2].end(), Tree[node*2+1].begin(), Tree[node*2+1].end(), Tree[node].begin());
    }
    T query(int K, int left, int right, int node, int leftNode, int rightNode){
        if(rightNode<left || right<leftNode) return 0;
        if(left<=leftNode && rightNode<=right) return Tree[node].end() - upper_bound(Tree[node].begin(), Tree[node].end(), K);
        ll mid = leftNode+rightNode; mid/=2;
        return query(K, left, right, node*2, leftNode, mid) + query(K, left, right, node*2+1, mid+1, rightNode);
    }
};

int main(){
    fastio;
    int N; cin>>N;
    vector<ll> V(N+1);
    for(int i=1; i<=N; i++) cin>>V[i];
    MergeSortTree<ll> mst(N);
    mst.init(1, 1, N, V);
    int M; cin>>M;
    ll ans = 0;
    while(M--){
        ll a,b,c; cin>>a>>b>>c;
        ans = mst.query(c^ans, a^ans, b^ans, 1, 1, N);
        cout<<ans<<'\n';
    }
    return 0;
}
```
***

[7469 K번째 수 P2](https://www.acmicpc.net/problem/7469)

Tag: **Merge Sort Tree**, **Binary Search**

뭔가 Kth Query 느낌이 들어 이분 탐색이란 생각은 했지만, 트리에서의 이분 탐색이 아니라 진짜 이분 탐색이 나올줄은 상상도 못했습니다...

풀이를 보시면 바로 이해가 되실겁니다...!
```cpp
/*
Check(mid) : 구간에 mid보다 작거나 같은 수의 개수가 K보다 작은가?
TTFF로 존재
가장 작은 F인 en 출력
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

template <typename T>
struct MergeSortTree{
    int N;
    vector<vector<T>> seg;
    MergeSortTree(int N):N(N){seg.resize(N*4);}
    void init(int node, int leftNode, int rightNode, vector<T>&V){
        if(leftNode==rightNode){seg[node].push_back(V[leftNode]); return;}
        ll mid = leftNode+rightNode; mid/=2;
        init(node*2, leftNode, mid, V);
        init(node*2+1, mid+1, rightNode, V);
        seg[node].resize(seg[node*2].size()+seg[node*2+1].size());
        merge(seg[node*2].begin(), seg[node*2].end(), seg[node*2+1].begin(), seg[node*2+1].end(), seg[node].begin());
    }
    int query(int K, int left, int right, int node, int leftNode, int rightNode){ //K보다 작거나 같은 수의 개수 반환
        if(rightNode<left || right<leftNode) return 0;
        if(left<=leftNode && rightNode<=right) return upper_bound(seg[node].begin(), seg[node].end(), K) - seg[node].begin();
        ll mid = leftNode+rightNode; mid/=2;
        return query(K, left, right, node*2, leftNode, mid) + query(K, left, right, node*2+1, mid+1, rightNode);
    }
};

int main(){
    fastio;
    int N, M; cin>>N>>M;
    vector<ll> V(N+1);
    for(int i=1; i<=N; i++) cin>>V[i];
    MergeSortTree<ll> m(N);
    m.init(1, 1, N, V);
    while(M--){
        ll a,b,c; cin>>a>>b>>c;
        ll st=-(1e9+2), en=1e9+2;
        while(st+1<en){
            ll mid = (st+en)/2;
            if(m.query(mid, a, b, 1, 1, N) < c) st = mid;
            else en = mid;
        }
        cout<<en<<'\n';
    }
    return 0;
}
```

***

[11012 Egg P2](https://www.acmicpc.net/problem/11012)

Tag: **Merge Sort Tree**, **Persistent Segment Tree**

2차원 공간에서 구간 합을 구하는 문제입니다. 좌표가 작았더라면 펜윅 트리로 바로 해결 가능하지만, 좌표압축을 하더라도 10,000 * 10,000이라 빡빡합니다...

스위핑만으로 풀수 있다곤 하지만, 머지 소트 트리로 풀어봅시다. X나 Y축 하나를 머지 소트 트리의 리프노드에 들어갈 값으로 처리하기 위해 좌표압축을 해줍니다.

이후 init에서 주의할 점은 리프 노드에 두 개 이상의 값이 들어갈 수 있다는 점입니다. 그래서 미리 정렬해둔 vector을 각 리프노드에 넣어주는 방식으로 구현했습니다.

이렇게 머지 소트 트리를 만들 때, Y축을 구간으로 잡고, 들어가는 값으로는 정렬된 X축 값이 들어가게 해주면 모든 준비가 끝났습니다.

이후 쿼리마다 [y1 ~ y2 범위에서 x2보다 작거나 같은 수의 개수]에서 [y1 ~ y2 범위에서 x1-1보다 작거나 같은 수의 개수]를 빼주면 됩니다.
이 쿼리는 위의 K번째 수에서 만들었던 쿼리와 동일합니다.

```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define pii pair<ll,ll>
#define tiiii tuple<ll,ll,ll,ll>
#define yy first 
#define xx second

template <typename T>
struct MergeSortTree{
    int N;
    vector<vector<T>> seg;
    MergeSortTree(int N){seg.resize(N*4);}
    void init(int node, int leftNode, int rightNode, vector<vector<ll>>&V){
        if(leftNode==rightNode){seg[node] = V[leftNode]; return;}
        ll mid = leftNode+rightNode; mid/=2;
        init(node*2, leftNode, mid, V);
        init(node*2+1, mid+1, rightNode, V);
        seg[node].resize(seg[node*2].size() + seg[node*2+1].size());
        merge(seg[node*2].begin(), seg[node*2].end(), seg[node*2+1].begin(), seg[node*2+1].end(), seg[node].begin());
    }
    T query(int K, int left, int right, int node, int leftNode, int rightNode){ //Y축 left ~ right 사이에 K보다 작거나 같은 X값의 개수 반환
        if(rightNode<left || right<leftNode) return 0;
        if(left<=leftNode && rightNode<=right) return upper_bound(seg[node].begin(), seg[node].end(), K) - seg[node].begin();
        ll mid = leftNode+rightNode; mid/=2;
        return query(K, left, right, node*2, leftNode, mid) + query(K, left, right, node*2+1, mid+1, rightNode);
    }
};

void solve(){
    int N,M; cin>>N>>M;
    vector<ll> compY;
    vector<pii> pos(N);
    vector<tiiii> Query(M);
    for(int i=0; i<N; i++){
        cin>>pos[i].yy>>pos[i].xx;
        compY.push_back(pos[i].yy);
    }
    for(int i=0; i<M; i++){
        int a,b,c,d; cin>>a>>b>>c>>d;
        Query[i] = {a,b,c,d};
        compY.push_back(a);
        compY.push_back(b);
    }

    //Y축 기준 좌표압축 (1-indexed로 수정)
    sort(compY.begin(), compY.end());
    compY.erase(unique(compY.begin(), compY.end()), compY.end());
    int mxY = compY.size();
    for(auto&[y,x]:pos) y = lower_bound(compY.begin(), compY.end(), y) - compY.begin() + 1;
    for(auto&[y1,y2,x1,x2]:Query){
        y1 = lower_bound(compY.begin(), compY.end(), y1) - compY.begin() + 1;
        y2 = lower_bound(compY.begin(), compY.end(), y2) - compY.begin() + 1;
    }

    //Y축 기준으로 값들을 저장해두면, init에서 리프 노드에 도달했을 때 그 값들만 쭉 넣어주면 된다.
    vector<vector<ll>> V(mxY+1);
    for(auto[y,x] : pos) V[y].push_back(x);
    for(int i=1; i<=mxY; i++) sort(V[i].begin(), V[i].end());

    MergeSortTree<ll> m(mxY);
    m.init(1, 1, mxY, V);

    ll ans = 0;
    for(auto[y1,y2,x1,x2] : Query){
        ans += m.query(x2, y1, y2, 1, 1, mxY) - m.query(x1-1, y1, y2, 1, 1, mxY);
    }
    cout<<ans<<'\n';
}

int main(){
    fastio;
    int tc; cin>>tc;
    while(tc--) solve();
    return 0;
}
```
***
