# Segment Tree 1
### - 구간 트리
[문제집 1 링크](https://www.acmicpc.net/group/workbook/view/20184/71476) | [문제집 2 링크](https://www.acmicpc.net/group/workbook/view/20184/72226) | [문제집 3 링크](https://www.acmicpc.net/group/workbook/view/20184/73929)

세그먼트 트리는 PS에서 정말 많이 쓰이는 사기적인 자료구조입니다.

특정 구간에서의 **최대/최소/LCM/GCD/합 등의 쿼리**, **값/구간 update 쿼리**를 모두 **O(logN)**에 처리할 수 있습니다.

문제집 1과 2는 간단한 문제를, 3에는 금광 세그, 혹은 구조체 세그라고 불리는 문제를 모았습니다. 

관련 자료는 너무나 많으므로 생략합니다.

챕터 1에는 **range sum + @**, **Kth Query**, **Couting Inversions** 를 다룹니다. 

자료마다 구현체가 조금씩 다를텐데, 편한거 쓰시고 가능하면 제 구현체를 쓰시는게 좋습니다...

[세그먼트 트리 자료 1](https://www.youtube.com/watch?v=075fcq7oCC8) | [세그먼트 트리 자료 2](https://www.youtube.com/watch?v=ahFB9eCnI6c)

***

[2042 구간 합 구하기 G1](https://www.acmicpc.net/problem/2042)

세그먼트 트리를 사용해 Range sum Query + Point update Query를 날려봅시다!

처음 배울 땐 init 함수도 만들어서 썼는데, 그냥 update로 처리해주는게 더 나은 것 같습니다.

구간 최소, 최대, 등등 다른 것들도 merge 함수와 default 값만 잘 준다면 간단하게 해결할 수 있습니다.
```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int N,M,K;
vector<ll> seg;

ll merge(ll left, ll right){
    return left + right;
}

ll update(ll idx, ll val, ll node, ll leftNode, ll rightNode){
    if(idx<leftNode || rightNode<idx) return seg[node];
    if(leftNode==rightNode) return seg[node] = val;
    ll mid = leftNode+rightNode; mid/=2;
    ll leftVal = update(idx, val, node*2, leftNode, mid);
    ll rightVal = update(idx, val, node*2+1, mid+1, rightNode);
    return seg[node] = merge(leftVal, rightVal);
}

ll query(ll left, ll right, ll node, ll leftNode, ll rightNode){
    if(rightNode<left || right<leftNode) return 0;
    if(left<=leftNode && rightNode<=right) return seg[node];
    ll mid = leftNode+rightNode; mid/=2;
    ll leftVal = query(left, right, node*2, leftNode, mid);
    ll rightVal = query(left, right, node*2+1, mid+1, rightNode);
    return merge(leftVal, rightVal);
}

int main(){
    fastio;
    cin>>N>>M>>K;
    seg.resize(N*4);
    for(int i=0; i<N; i++){
        ll x; cin>>x;
        update(i, x, 1, 0, N-1);
    }
    for(int i=0; i<M+K; i++){
        ll a,b,c; cin>>a>>b>>c;
        if(a==1) update(--b, c, 1, 0, N-1);
        if(a==2) cout<<query(--b, --c, 1, 0, N-1)<<'\n';
    }
    return 0;
}
```
***

[14427 수열과 쿼리 15 G3](https://www.acmicpc.net/problem/14427)
- 구간 최솟값 쿼리를 날려줍시다

[2357 최솟값과 최댓값 G1](https://www.acmicpc.net/problem/2357)
- pair로 최대/최소 모두 저장하게 해봅시다

[10868 최솟값 G1](https://www.acmicpc.net/problem/10868)
- 구간 최솟값 쿼리를 날려봅시다

[11505 구간 곱 구하기 G1](https://www.acmicpc.net/problem/11505)
- 구간 곱도 마찬가지로 구할 수 있어요

[1275 커피숍 2 G1](https://www.acmicpc.net/problem/1275)
- range sum과 point update 쿼리로 해결할 수 있겠죠?

[14428 수열과 쿼리 16 G1](https://www.acmicpc.net/problem/14428)
- min value가 아니라 min Index를 구해야 합니다. 각 값이 갖는 값을 잘 다뤄주면 되겠죠?

[14438 수열과 쿼리 17 G1](https://www.acmicpc.net/problem/14438)
- min value를 구해봅시다

[5676 음주 코딩 G1](https://www.acmicpc.net/problem/5676)
- 구간 곱 쿼리인데, 음수/양수만 잘 처리해주면 되므로, 양수면 1 음수면 -1로 바꿔서 update해줍시다

[12837 가계부 (Hard) G1](https://www.acmicpc.net/problem/12837)
- 마찬가지로 구간 합입니다. 
- 근데, 같은 날에 여러 번 update가 일어날 수 있으니, update에선 값을 + 해주는 식으로 구현해야겠네요

[18436 수열과 쿼리 37 G1](https://www.acmicpc.net/problem/18436)
- 지금 보니까, 구조체 세그 느낌도 나는 문제입니다. 
- pair로 구간의 홀수, 짝수를 같이 관리해줍시다.

***

[6549 히스토그램에서 가장 큰 직사각형 P5](https://www.acmicpc.net/problem/6549)

PS에서는 너무 유명한 문제로, [1725 히스토그램 P5](https://www.acmicpc.net/problem/1725), [12846 무서운 아르바이트 P5](https://www.acmicpc.net/problem/12846)과 같은 문제이다.

해당 문제는 **Stack** 풀이, **Union Find+sort+Greedy** 풀이, **Segment Tree+Divide&Conquer** 풀이가 존재하는 것으로 알고 있다. (Union Find 풀이가 가장 흥미롭다.)

세그먼트 트리와 분할정복을 사용한 풀이를 소개하자면, 세그먼트 트리로 구간 최솟값 인덱스를 저장한다. 

st, en 구간이 있을 때, V[minIdx(st,en)] * (en-st+1)이 그 구간의 가장 큰 직사각형이 된다.

이후 st ~ minIdx(st,en)-1 구간의 답 / minIdx(st,en)+1 ~ en 구간의 답을 구해가면서 가장 큰 값을 답으로 취하면 된다.

분할정복을 할 때, 범외에서 이전에 구한 최솟값을 제외하는 이유는, 그 값이 들어간 상태로 진행하면 그 최솟값이 이번에도 쓰일 것이고, 그렇게 구해진 ans는 그 값을 사용했을 때의 가장 큰 직사각형이 아닐 것이기 때문이다.
```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

vector<ll> V;
vector<ll> seg;

ll merge(ll left, ll right){
    if(left==-1) return right;
    if(right==-1) return left;
    if(V[left]<=V[right]) return left;
    return right;
}

ll update(ll idx, ll val, ll node, ll leftNode, ll rightNode){
    if(idx<leftNode || rightNode<idx) return seg[node];
    if(leftNode==rightNode) return seg[node] = val;
    ll mid = leftNode+rightNode; mid/=2;
    ll leftVal = update(idx, val, node*2, leftNode, mid);
    ll rightVal = update(idx, val, node*2+1, mid+1, rightNode);
    return seg[node] = merge(leftVal, rightVal);
}

ll Min_idx_query(ll left, ll right, ll node, ll leftNode, ll rightNode){
    if(rightNode<left || right<leftNode) return -1;
    if(left<=leftNode && rightNode<=right) return seg[node];
    ll mid = leftNode+rightNode; mid/=2;
    ll leftVal = Min_idx_query(left, right, node*2, leftNode, mid);
    ll rightVal = Min_idx_query(left, right, node*2+1, mid+1, rightNode);
    return merge(leftVal, rightVal);
}

ll query(ll st, ll en, ll N){
    if(st>en) return 0;
    ll mnIdx = Min_idx_query(st, en, 1, 0, N-1);
    ll ret = V[mnIdx] * (en-st+1);
    ret = max({ret, query(st, mnIdx-1, N), query(mnIdx+1, en, N)});
    return ret;
}

bool solve(){
    int N; cin>>N;
    if(N==0) return false;
    V.clear(); V.resize(N);
    seg.clear(); seg.resize(4*N);
    for(int i=0; i<N; i++){
        cin>>V[i];
        update(i, i, 1, 0, N-1);
    }
    cout<<query(0, N-1, N)<<'\n';
    return true;
}

int main(){
    fastio;
    while(solve());
    return 0;
}
```

***

[1989 부분배열 고르기 2 P5](https://www.acmicpc.net/problem/1989)

하위 문제로 [2104 부분배열 고르기 P5](https://www.acmicpc.net/problem/2104)가 있다. 히스토그램과 비슷하게 분할 정복을 활용하여 해결 가능하다. 자세한 풀이는 코드에 작성한다.

```cpp
//히스토그램과 비슷한 아이디어로 풀 수 있다.
//단, 이 문제는 (A[i] + … + A[j]) × min{A[i], …, A[j]}를 최대화해야 하므로, range sum과 range min을 모두 해줘야 한다.
//히스토그램에서의 분할정복 아이디어와 마찬가지로, min{A[i], …, A[j]}이 정해지면 값을 최대화시키기 위한 (A[i] + … + A[j])도 정해진다.
//분할정복 + 세그먼트 트리는 유명한 테크닉이므로 잘 익혀두자

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

struct Node{
    ll sum=0, mnIdx=0;
    Node(ll s, ll m) : sum(s), mnIdx(m){};
    Node() : sum(0), mnIdx(0){};
};

int N;
vector<ll> V;
vector<Node> seg;

Node merge(Node left, Node right){
    if(left.mnIdx==-1) return right;
    if(right.mnIdx==-1) return left;
    Node ret;
    ret.mnIdx = (V[left.mnIdx]<=V[right.mnIdx])?left.mnIdx:right.mnIdx;
    ret.sum = left.sum + right.sum;
    return ret;
}

Node update(ll idx, Node val, ll node, ll leftNode, ll rightNode){
    if(idx<leftNode || rightNode<idx) return seg[node];
    if(leftNode==rightNode) return seg[node] = val;
    ll mid = leftNode+rightNode; mid/=2;
    Node leftVal = update(idx, val, node*2, leftNode, mid);
    Node rightVal = update(idx, val, node*2+1, mid+1, rightNode);
    return seg[node] = merge(leftVal, rightVal);
}

Node query(ll left, ll right, ll node, ll leftNode, ll rightNode){
    if(rightNode<left || right<leftNode) return Node(-1, -1);
    if(left<=leftNode && rightNode<=right) return seg[node];
    ll mid = leftNode+rightNode; mid/=2;
    Node leftVal = query(left, right, node*2, leftNode, mid);
    Node rightVal = query(left, right, node*2+1, mid+1, rightNode);
    return merge(leftVal, rightVal);
}

tuple<ll,ll,ll> solve(ll st, ll en){
    if(st>en) return {-1, -1, -1};
    Node ans = query(st, en, 1, 0, N-1);
    tuple<ll,ll,ll> ret = {V[ans.mnIdx] * ans.sum, st, en};
    //첫 번째 값으로 ans를 저장시켜서, 알아서 가장 큰 값으로 갱신이 됩니다.
    ret = max({ret, solve(st, ans.mnIdx-1), solve(ans.mnIdx+1, en)});
    return ret;
}

int main(){
    fastio;
    cin>>N;
    V.resize(N);
    seg.resize(4*N);
    for(int i=0; i<N; i++){
        cin>>V[i];
        update(i, Node(V[i],i), 1, 0, N-1);
    }
    auto[ans, st, en] = solve(0, N-1);
    cout<<ans<<'\n'<<st+1<<' '<<en+1;
    return 0;
}
```

***

[2243 사탕상자 P5](https://www.acmicpc.net/problem/2243)

![image](https://upload.acmicpc.net/c9a37a08-38ff-4588-ab15-d029259c09fd/)

이런 문제를 통틀어 Kth Query라고 부르겠습니다.

이런 문제는 세그먼트 트리에서의 이분 탐색을 통해 답을 구할 수 있습니다.

위의 그림에서 보는 것과 같이, seg[node\*2]의 값이 K보다 크거나 같다면 seg[node\*2]로 이동합니다.

아니라면 seg[node\*2 + 1]로 이동하고, K에서 seg[node\*2]를 빼줍니다.

이를 재귀적으로 반복하면 됩니다.
```cpp
int Kth(int K, int node, int leftNode, int rightNode){
    if(leftNode==rightNode){
        SegTree[node]-=1;
        return leftNode;
    }
    int mid = leftNode + (rightNode-leftNode)/2;
    int Val = K<=SegTree[node*2]?Kth(K,node*2,leftNode,mid):Kth(K-SegTree[node*2],node*2+1,mid+1,rightNode);
    SegTree[node] = merge(SegTree[node*2], SegTree[node*2+1]);
    return Val;
}
```
***

[12899 데이터 구조 P4](https://www.acmicpc.net/problem/12899)
- 비슷한 Kth Query 문제입니다.

[1572 중앙값 P5](https://www.acmicpc.net/problem/1572)
- Kth Query입니다.  [9426 중앙값 측정 P5](https://www.acmicpc.net/problem/9426)이 문제와 같은 문제입니다.
- K개씩 묶어서 Kth Query를 돌리고, 슬라이딩 윈도우 방식으로 K개의 원소를 유지하기 위해 제일 마지막 원소를 지우고, 새로운 원소를 추가하는 과정이 필요합니다.

***

[1168 요세푸스 문제 2 P3](https://www.acmicpc.net/problem/1168)

큐로 해결했던 요세푸스 문제도, Kth 쿼리를 사용하면 아주 빠르게 해결 가능합니다!

모듈러 연산(%)이 약간의 벽처럼 느껴질 수 있습니다...
```cpp
//N-1개 먼저 Kth로 처리해주고, 나머지 하나는 직접 출력해줬습니다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N, K;
vector<int> seg;

int update(int idx, int val, int node, int leftNode, int rightNode){
    if(idx<leftNode || rightNode<idx) return seg[node];
    if(leftNode==rightNode) return seg[node] = val;
    int mid = leftNode+rightNode; mid/=2;
    int leftVal = update(idx, val, node*2, leftNode, mid);
    int rightVal = update(idx, val, node*2+1, mid+1, rightNode);
    return seg[node] = leftVal + rightVal;
}

int query(int left, int right, int node, int leftNode, int rightNode){
    if(rightNode<left || right<leftNode) return 0;
    if(left<=leftNode && rightNode<=right) return seg[node];
    int mid = leftNode+rightNode; mid/=2;
    int leftVal = query(left, right, node*2, leftNode, mid);
    int rightVal = query(left, right, node*2+1, mid+1, rightNode);
    return leftVal + rightVal;
}

int kth(int K, int node, int leftNode, int rightNode){
    if(leftNode==rightNode){
        seg[node] = 0;
        return leftNode;
    }
    int mid = leftNode+rightNode; mid/=2;
    int val =  (seg[node*2]>=K)?kth(K, node*2, leftNode, mid):kth(K-seg[node*2], node*2+1, mid+1, rightNode);
    seg[node] = seg[node*2] + seg[node*2+1];
    return val;
}

int main(){
    fastio;
    cin>>N>>K;
    seg.resize(N*4);
    for(int i=1; i<=N; i++) update(i, 1, 1, 1, N);
    int idx = K-1;
    cout<<'<';
    for(int i=0; i<N-1; i++){
        cout<<kth(idx+1, 1, 1, N)<<", ";
        idx += K-1;
        idx %= seg[1];
    }
    cout<<kth(1, 1, 1, N)<<'>';
    return 0;
}
```

[31865 수열 만들기 P3](https://www.acmicpc.net/problem/31865)

위의 문제에서 좀 더 심화된 Kth Query입니다.

***

[10090 Counting Inversions P5](https://www.acmicpc.net/problem/10090)
- 문제 제목처럼 Inversions를 카운트하는 문제입니다.
- Inversions란, (1, 0), (4, 1) 처럼 뒷 수가 앞 수보다 작은 쌍들을 말합니다.
- 이것들의 수를 세려면, 순서대로 update 쿼리를 돌려주면서, 동시에 range sum을 해서 이 수보다 큰 수의 개수를 구하고 ans에 더해주면 됩니다.
- 몇 번 그림으로 그려가면서 시뮬레이션해보면 금방 이해될겁니다!!

[1517 버블 소트 P5](https://www.acmicpc.net/problem/1517)
- 좌표압축을 시켜서, 원소들을 0~N-1, 혹은 1~N으로 바꿔준 뒤, 위와 똑같이 처리해주면 됩니다.

[4297 Ultra-QuickSort P5](https://www.acmicpc.net/problem/4297)
- 버블 소트와 같은 문제입니다.

```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

vector<int> seg;

void compress(vector<int>&V){
    vector<int> tmp(V);
    sort(tmp.begin(), tmp.end());
    for(int&val : V) val = lower_bound(tmp.begin(), tmp.end(), val) - tmp.begin();
}

int update(int idx, int val, int node, int leftNode, int rightNode){
    if(idx<leftNode || rightNode<idx) return seg[node];
    if(leftNode==rightNode) return seg[node] = val;
    int mid = leftNode+rightNode; mid/=2;
    int leftVal = update(idx, val, node*2, leftNode, mid);
    int rightVal = update(idx, val, node*2+1, mid+1, rightNode);
    return seg[node] = leftVal+rightVal;
}

int query(int left, int right, int node, int leftNode, int rightNode){
    if(rightNode<left || right<leftNode) return 0;
    if(left<=leftNode && rightNode<=right) return seg[node];
    int mid = leftNode+rightNode; mid/=2;
    int leftVal = query(left, right, node*2, leftNode, mid);
    int rightVal = query(left, right, node*2+1, mid+1, rightNode);
    return leftVal+rightVal;
}

bool solve(){
    int N; cin>>N;
    if(!N) return false;
    vector<int> V(N);
    for(int i=0; i<N; i++) cin>>V[i];
    compress(V);
    seg.clear();
    seg.resize(N*4);
    long long ans = 0;
    for(int val : V){
        ans += query(val+1, N-1, 1, 0, N-1);
        update(val, 1, 1, 0, N-1);
    }
    cout<<ans<<'\n';
    return true;
}

int main(){
    fastio;
    while(solve());
    return 0;
}
```

[7578 공장 P5](https://www.acmicpc.net/problem/7578)
- B의 각 원소들을 A에서 그 원소가 등장한 인덱스로 변경해줍니다.
- 이후 Counting Inversions를 해주면 답을 구할 수 있습니다.
- A와 B를 반대로 해도 풀 수 있습니다!
- 왜 그런진 직접 그림을 그려보면 금방 알 수 있습니다.

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio cin.tie(NULL)->sync_with_stdio(false)

vector<int> Seg;

void compress(vector<int>&A, vector<int>&B){
    map<int,int> Mp;
    for(int i=0;i<(int)A.size(); ++i)  Mp[A[i]] = i;
    for(int &val : B) val = Mp[val];
}

int update(int idx, int node, int leftNode, int rightNode){
    if(idx<leftNode || rightNode<idx) return Seg[node];
    if(leftNode==rightNode) return Seg[node]+=1;
    int mid = leftNode + (rightNode-leftNode)/2;
    int leftVal = update(idx, node*2, leftNode, mid);
    int rightVal = update(idx, node*2+1, mid+1, rightNode);
    return Seg[node] = leftVal + rightVal;
}

int query(int left, int right, int node, int leftNode, int rightNode){
    if(rightNode<left || right<leftNode) return 0;
    if(left<=leftNode && rightNode<=right) return Seg[node];
    int mid = leftNode + (rightNode-leftNode)/2;
    int leftVal = query(left, right, node*2, leftNode, mid);
    int rightVal = query(left, right, node*2+1, mid+1, rightNode);
    return leftVal + rightVal;
}

int main(){
    fastio;
    int N; cin>>N;
    Seg.resize(N*4);
    vector<int> A(N), B(N);
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<N;i++) cin>>B[i];
    compress(A,B);
    long long Ans = 0;
    for(int val : B){
        update(val, 1, 0, N-1);
        Ans += query(val+1, N-1, 1, 0, N-1);
    }
    cout<<Ans;
    return 0;
}
```

[2517 달리기 P4](https://www.acmicpc.net/problem/2517)
- 비슷한 방식으로 해결 가능합니다.

```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

vector<int> Seg;

void compress(vector<int>&V){
    vector<int> tmp(V);
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for(int&val : V) val = lower_bound(tmp.begin(),tmp.end(),val)-tmp.begin();
}

int update(int idx, int node, int leftNode, int rightNode){
    if(idx<leftNode || rightNode<idx) return Seg[node];
    if(leftNode==rightNode) return Seg[node]=1;
    int mid = (leftNode+rightNode)/2;
    int leftVal = update(idx, node*2, leftNode, mid);
    int rightVal = update(idx, node*2+1, mid+1, rightNode);
    return Seg[node] = leftVal + rightVal;
}

int query(int left, int right, int node, int leftNode, int rightNode){
    if(rightNode<left || right<leftNode) return 0;
    if(left<=leftNode && rightNode<=right) return Seg[node];
    int mid = (leftNode+rightNode)/2;
    int leftVal = query(left, right, node*2, leftNode, mid);
    int rightVal = query(left, right, node*2+1, mid+1, rightNode);
    return leftVal + rightVal;
}

int main(){
    fastio;
    int N; cin>>N;
    Seg.resize(4*N);
    vector<int> V(N);
    for(int i=0;i<N;i++) cin>>V[i];
    compress(V);
    for(int i=0; i<N; i++){
        update(V[i], 1, 0, N-1);
        cout<<i+1-query(0, V[i]-1, 1, 0, N-1)<<'\n';
    }
    return 0;
}
```
***
