##### [[Range Query] Segment Tree #1/2 - introduction](https://www.youtube.com/watch?v=075fcq7oCC8)
##### [[Range Query] Segment Tree #2/2 - code](https://www.youtube.com/watch?v=ahFB9eCnI6c)
##### lazy propagation도 강의가 있는데 공부하고 추가하겠습니다

# 세그먼트 트리란
  - 특정 구간 내 데이터에 대한 연산(쿼리)을 빠르게 구할 수 있는 트리.
  - ex) 특정 구간 합,최소값,최대값,평균값 등등
  - 시간복잡도
    - Init: O(N)
    - Query: O(logN)
    - Update: O(logN)
    - lazy propagation을 사용하면 '구간 업데이트'를 효율적으로 처리할 수 있다.

###  

## [BOJ 2042 구간 합 구하기](https://www.acmicpc.net/problem/2042)
<details>
<summary> 접기/펼치기 </summary>
    
```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

ll N,M,K;
vector<ll> V;
vector<ll> Segtree;

ll merge(ll left, ll right){ //Sum
    return left + right;
}

ll init(ll node, ll nodeLeft ,ll nodeRight){ //Segtree Init
    if(nodeLeft==nodeRight) return Segtree[node] = V[nodeLeft];
    ll mid = nodeLeft + (nodeRight-nodeLeft) / 2;
    ll leftVal = init(node*2, nodeLeft, mid);
    ll rightVal = init(node*2 +1, mid+1, nodeRight);
    return Segtree[node] = merge(leftVal, rightVal);
}

ll query(ll left, ll right, ll node, ll nodeLeft, ll nodeRight){ //Segtree Query
    if(right<nodeLeft || nodeRight<left) return 0; //return default value
    if(left<=nodeLeft && nodeRight<=right) return Segtree[node];
    ll mid = nodeLeft + (nodeRight-nodeLeft) / 2;
    ll leftVal = query(left, right, node*2, nodeLeft, mid);
    ll rightVal = query(left, right, node*2 +1, mid+1, nodeRight);
    return merge(leftVal, rightVal);
}

ll update(ll index, ll newValue, ll node, ll nodeLeft, ll nodeRight){ //Segtree Update
    if(index<nodeLeft || nodeRight<index) return Segtree[node];
    if(nodeLeft==nodeRight) return Segtree[node]=newValue;
    ll mid = nodeLeft + (nodeRight-nodeLeft) / 2;
    ll leftVal = update(index, newValue, node*2, nodeLeft, mid);
    ll rightVal = update(index, newValue, node*2 +1, mid+1, nodeRight);
    return Segtree[node] = merge(leftVal, rightVal);
}

int main(){
    fastio;
    cin>>N>>M>>K; M+=K;
    V.resize(N+1);
    for(int i=1;i<=N;i++) cin>>V[i];
    Segtree.resize(4*(N+1));
    init(1,1,N);
    while(M--){
        ll a,b,c; cin>>a>>b>>c;
        if(a==1){ //update (b->c)
            update(b,c,1,1,N);
        }
        if(a==2){ //query (sum(b~c))
            cout<<query(b,c,1,1,N)<<'\n';
        }
    }
    return 0;
}
```
</details>

- 1-indexed로 세그먼트 트리를 구현할 수 있다.
- segment tree의 가장 기본적인 구현이다.
- merge에서 sum 연산을 수행한다.

###  

## [BOJ 14427 수열과 쿼리 15](https://www.acmicpc.net/problem/14427)
<details>
<summary> 접기/펼치기 </summary>
    
```cpp
//init에서 값들을 배열 번호로 세팅한다.
//merge에서 인덱스에 있는 값이 더 작은 인덱스를 반환하도록 한다.
//구간에서의 최솟값을 찾는 게 아니라 전체의 최솟값의 인덱스를 구하는 것이므로 query가 필요 없다.
//query를 쓰더라도 항상 전체 구간에서의 최솟값을 구하므로 Segtree[1]이 반환된다.
//Segtree[1]만 출력해주면 된다.
//merge에서 V를 사용했으므로 update에서도 V[index]를 업데이트해주면서 Segtree[Node]를 반환하도록 해준다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

ll N,M,K;
vector<ll> V;
vector<ll> Segtree;

ll merge(ll left, ll right){ //Min
    if(V[left]==V[right]) return min(left, right);
    return V[left]>V[right]?right:left; //V[left]가 더 크다면 right를, V[right]가 더 크다면 left를 반환
}

ll init(ll node, ll nodeLeft ,ll nodeRight){ //Segtree Init
    if(nodeLeft==nodeRight) return Segtree[node] = nodeLeft;
    ll mid = nodeLeft + (nodeRight-nodeLeft) / 2;
    ll leftVal = init(node*2, nodeLeft, mid);
    ll rightVal = init(node*2 +1, mid+1, nodeRight);
    return Segtree[node] = merge(leftVal, rightVal);
}

ll update(ll index, ll newValue, ll node, ll nodeLeft, ll nodeRight){ //Segtree Update
    if(index<nodeLeft || nodeRight<index) return Segtree[node];
    if(nodeLeft==nodeRight){V[index]=newValue; return Segtree[node];};
    ll mid = nodeLeft + (nodeRight-nodeLeft) / 2;
    ll leftVal = update(index, newValue, node*2, nodeLeft, mid);
    ll rightVal = update(index, newValue, node*2 +1, mid+1, nodeRight);
    return Segtree[node] = merge(leftVal, rightVal);
}

int main(){
    fastio;
    cin>>N;
    V.resize(N+1);
    for(int i=1;i<=N;i++) cin>>V[i];
    Segtree.resize(4*(N+1));
    init(1,1,N);
    cin>>M;
    while(M--){
        ll q; cin>>q; 
        if(q==2){
            cout<<Segtree[1]<<'\n';
        }
        if(q==1){
            ll a,b; cin>>a>>b;
            update(a,b,1,1,N);
        }
    }
    return 0;
}
```
</details>

- Segment Tree로 Min 연산을 수행할 수 있다.
- Segment Tree의 각 노드에 최솟값 인덱스를 저장할 수 있다. (이에 따라 merge 수정)
- 특정 구간에서의 최솟값이 아닌 전체 구간에서의 최솟값 '인덱스'를 묻는 문제

###  

## [BOJ 2357 최솟값과 최댓값](https://www.acmicpc.net/problem/2357)
<details>
<summary> 접기/펼치기 </summary>
    
```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define pii pair<int,int>
#define MX first
#define MN second

int N,M;
vector<pii> Segtree;
vector<int> V;

pii merge(pii left, pii right){
    int mx = max(left.MX, right.MX);
    int mn = min(left.MN, right.MN);
    return {mx,mn};
}

pii init(int node, int leftNode, int rightNode){
    if(leftNode==rightNode) return Segtree[node] = {V[leftNode],V[leftNode]};
    int mid = leftNode + (rightNode-leftNode) / 2;
    pii leftVal = init(node*2, leftNode, mid);
    pii rightVal = init(node*2 +1, mid+1, rightNode);
    return Segtree[node] = merge(leftVal, rightVal);
}

pii query(int left, int right, int node, int leftNode, int rightNode){
    if(right<leftNode || rightNode<left) return {-1,0x7f7f7f7f};
    if(left<=leftNode && rightNode<=right) return Segtree[node];
    int mid = leftNode + (rightNode-leftNode) / 2;
    pii leftVal = query(left, right, node*2, leftNode, mid);
    pii rightVal = query(left, right, node*2 +1, mid+1, rightNode);
    return merge(leftVal, rightVal);
}

int main(){
    fastio;
    cin>>N>>M;
    V.resize(N+1); 
    Segtree.resize(N*4);
    for(int i=1;i<=N;i++) cin>>V[i];
    init(1,1,N);
    while(M--){
        int a,b; cin>>a>>b;
        pii Ans = query(a,b,1,1,N);
        cout<<Ans.MN<<' '<<Ans.MX<<'\n';
    }
    return 0;
}
```
</details>

- Segtree의 자료형을 pair로 하여 최대, 최소를 모두 저장할 수 있다.

###  

## [BOJ 2104 부분배열 고르기](https://www.acmicpc.net/problem/2104)
<details>
<summary> 접기/펼치기 </summary>
    
```cpp
//Segment Tree로 range minimun query, range sum query를 처리
//range minimun query로 1~N에서 최소값을 구하고 sum(1,N) * rmq(1,N)을 ans로 갱신
//rmq로 구한 전체 최솟값을 mid라고 했을 때, 1~mid-1과 mid+1~N 두 구역으로 나눠서 생각할 수 있음
//두 구간에서도 이와 같은 방식으로 ans를 갱신한다면 답을 구할 수 있을 것 같다는 생각이 들었음

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tlll tuple<ll,ll,ll> //sum min maxidx
#define fastio cin.tie(NULL)->sync_with_stdio(false)
const ll MX = 101'0101;

int N;
ll Ans = -1;
vector<tlll> SegTree;
vector<ll> V;

tlll merge(tlll left, tlll right){
    auto&[l_sum, l_min, l_idx] = left;
    auto&[r_sum, r_min, r_idx] = right;
    return {l_sum+r_sum, min(l_min, r_min), V[l_idx]>V[r_idx]?r_idx:l_idx};
}

tlll init(int node, int leftNode ,int rightNode){
    if(leftNode==rightNode) return SegTree[node] = {V[leftNode], V[leftNode], leftNode};
    ll mid = leftNode + (rightNode-leftNode)/2;
    tlll leftVal = init(node*2, leftNode, mid);
    tlll rightVal = init(node*2+1, mid+1, rightNode);
    return SegTree[node] = merge(leftVal, rightVal);
}

tlll query(int left, int right, int node, int leftNode, int rightNode){
    if(rightNode<left || right<leftNode) return {0,MX,0};
    if(left<=leftNode && rightNode<=right) return SegTree[node];
    ll mid = leftNode + (rightNode-leftNode)/2;
    tlll leftVal = query(left, right, node*2, leftNode, mid);
    tlll rightVal = query(left, right, node*2+1, mid+1, rightNode);
    return merge(leftVal, rightVal);
}

void solve(int st, int en){
    if(st>en) return;
    auto[sum, mn, mid] = query(st,en,1,1,N);
    Ans = max(Ans, sum*mn);
    solve(st, mid-1);
    solve(mid+1, en);
}

int main(){
    fastio;
    cin>>N;
    V.resize(N+1); V[0]=MX;
    for(int i=1;i<=N;i++) cin>>V[i];
    SegTree.resize(N*4); init(1,1,N);
    solve(1,N);
    cout<<Ans;
    return 0;
}
```
</details>

- Segment Tree + Divide&Conquer
- range minimun query, range sum query, range minimum idx query 세 가지를 tuple로 합쳐서 처리했다. (class나 struct 쓰는게 나을듯)
- 연산에서 곱해지는 단일 값은 구간 최솟값이다.
- 구간 최솟값을 기준으로 분할정복을 수행할 수 있다.
- 분할정복이 올바른 해답을 도출하는 이유는 어느 구간의 최솟값을 사용할 때 점수의 최댓값은 최솟값을 유지하면서 범위가 가장 큰 경우이기 때문이다.
- 예를 들어 전체 구간의 최솟값이 1이라고 가정하자. 음의 정수가 입력되지 않으므로 이때 점수를 최대한으로 먹으려면 범위가 가장 커야 할 것이다.
- 재밌는 문제였다.

### 

###  

###  

# Kth Query
  - 세그먼트 트리에서 K번째 작은 수에 접근하는 쿼리
  - 트리의 각 노드에서는 인덱스의 값이 등장한 횟수를 관리한다.
   
###  
  
## [BOJ 12899 데이터 구조](https://www.acmicpc.net/problem/12899)
<details>
<summary> 접기/펼치기 </summary>
    
```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
const int MX = 200'0000;

vector<int> SegTree((MX+1)*4);

int merge(int left, int right){
    return left + right;
}

int update(int idx, int node, int leftNode, int rightNode){ //newValue 필요없음
    if(idx<leftNode || rightNode<idx) return SegTree[node];
    if(leftNode == rightNode) return ++SegTree[node];
    int mid = leftNode + (rightNode-leftNode)/2;
    int leftVal = update(idx, node*2, leftNode, mid);
    int rightVal = update(idx, node*2 +1, mid+1, rightNode);
    return SegTree[node] = merge(leftVal, rightVal);
}

//K <= Seg[node*2] -> left 이동
//Seg[node*2] < K  -> right 이동, K -= Seg[node*2]
int Kth(int K, int node, int leftNode, int rightNode){
    SegTree[node]--;
    if(leftNode == rightNode) return leftNode;
    int mid = leftNode + (rightNode-leftNode)/2; 
    if(K <= SegTree[node*2]) return Kth(K, node*2, leftNode, mid);
    else return Kth(K - SegTree[node*2], node*2+1, mid+1, rightNode); 
}

int main(){
    fastio;
    int N; cin>>N;
    while(N--){
        int T,X; cin>>T>>X;
        if(T==1) update(X,1,1,MX);
        else cout<<Kth(X,1,1,MX)<<'\n';
    }
    return 0;
}
```
</details>

- Kth Query를 스스로 구현해보았다.
- right 이동시 K-=Seg[node*2]를 해줘야 한다.
- 이 방법 말고 기존 query처럼 Value를 받아오고 Segtree[node] = Segtree[node*2] + Segtree[node*2+1]을 해줘도 된다.
- 이 경우엔 바로 --를 해서 구현했다.

###  

## [BOJ 2243 사탕상자](https://www.acmicpc.net/problem/2243)
<details>
<summary> 접기/펼치기 </summary>
    
```cpp
// 1 ~ 100'0000
// Query 1: K번째 수를 구하고 -1
// Query 2: A B가 주어지면 맛 A인 사탕을 B만큼 넣음 (음수면 뺌)

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
const int MX = 100'0001;

vector<int> SegTree(MX*4);

int merge(int left, int right){
    return left + right;
}

int update(int idx, int newValue, int node, int leftNode, int rightNode){
    if(idx<leftNode || rightNode<idx) return SegTree[node];
    if(leftNode == rightNode) return SegTree[node]+=newValue; //더해줌
    int mid = leftNode + (rightNode-leftNode)/2;
    int leftVal = update(idx, newValue, node*2, leftNode, mid);
    int rightVal = update(idx, newValue, node*2+1, mid+1, rightNode);
    return SegTree[node] = merge(leftVal, rightVal);
}

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

int main(){
    fastio;
    int N; cin>>N;
    while(N--){
        int A,B,C; cin>>A;
        if(A==1){
            cin>>B;
            cout<<Kth(B,1,1,MX)<<'\n';
        }
        if(A==2){
            cin>>B>>C;
            update(B,C,1,1,MX);
        }
    }
    return 0;
}
```
</details>

- 기존 query 함수와 비슷한 느낌으로 Kth를 구현했다.

###  

## [BOJ 1168 요세푸스 문제 2](https://www.acmicpc.net/problem/1168)
<details>
<summary> 접기/펼치기 </summary>
    
```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N, K;
vector<int> SegTree;

int merge(int left, int right){
    return left + right;
}

int init(int node, int leftNode, int rightNode){
    if(leftNode==rightNode) return SegTree[node]=1;
    int mid = leftNode + (rightNode-leftNode)/2;
    int leftVal = init(node*2, leftNode, mid);
    int rightVal = init(node*2+1, mid+1, rightNode);
    return SegTree[node] = merge(leftVal, rightVal);
}

int Kth(int K, int node, int leftNode, int rightNode){
    if(leftNode==rightNode){
        SegTree[node] = SegTree[node]-1;
        return leftNode;
    }
    int mid = leftNode + (rightNode-leftNode)/2;
    int Val = K<=SegTree[node*2]?Kth(K,node*2,leftNode,mid):Kth(K-SegTree[node*2],node*2+1,mid+1,rightNode);
    SegTree[node] = merge(SegTree[node*2],SegTree[node*2+1]);
    return Val;
}

int main(){
    fastio;
    cin>>N>>K;
    SegTree.resize((N+1)*4);
    init(1,1,N);
    cout<<"<";
    int X = 1;
    while(SegTree[1]>0){
        if(SegTree[1]!=N) cout<<", ";
        X  = ((X-2)+K)%SegTree[1]+1;
        cout<<Kth(X,1,1,N);
    }   
    cout<<">";
    return 0;
}

/*
K = 3

1 2 3 4 5 6 7

1. Seg[1]=7 | 3번째로 작은 수 
2. Seg[1]=6 | 5번째로 작은 수 
3. Seg[1]=5 | 2번째로 작은 수 
4. Seg[1]=4 | 4번재로 작은 수 
5. Seg[1]=3 | 3번째로 작은 수 
6. Seg[1]=2 | 1번째로 작은 수 
7. Seg[1]=1 | 1번째로 작은 수 

X가 0에 도달하면 안되므로 잘 신경써서 식을 세워야 한다.
*/
```
</details>

- Kth Query 응용 문제이다.
- 매 쿼리마다 K를 갱신해야 하는데, 그 식을 구하는데 시간이 좀 걸렸다.

###  

## [BOJ 31865 수열 만들기](https://www.acmicpc.net/problem/31865)
<details>
<summary> 접기/펼치기 </summary>
    
```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);

int N;
vector<int> SegTree;
vector<int> Pos; //Pos[x]: 수 x의 위치
vector<int> Ans; //Ans[x]: x번 자리에 있는 수

int merge(int left, int right){
    return left + right;
}

int init(int node, int leftNode, int rightNode){
    if(leftNode==rightNode) return SegTree[node]=1;
    int mid = leftNode + (rightNode-leftNode)/2;
    int leftVal = init(node*2, leftNode, mid);
    int rightVal = init(node*2+1, mid+1, rightNode);
    return SegTree[node] = merge(SegTree[node*2], SegTree[node*2+1]);
}

int Kth(int K, int node, int leftNode, int rightNode){
    if(leftNode==rightNode){
        SegTree[node]=0;
        return leftNode;
    }
    int mid = leftNode + (rightNode-leftNode)/2;
    int Val = K<=SegTree[node*2]?Kth(K,node*2,leftNode,mid):Kth(K-SegTree[node*2],node*2+1,mid+1,rightNode);
    SegTree[node] = merge(SegTree[node*2], SegTree[node*2+1]);
    return Val;
}

int query(int left, int right, int node, int leftNode, int rightNode){
    if(rightNode<left || right<leftNode) return 0;
    if(left<=leftNode && rightNode<=right) return SegTree[node];
    int mid = leftNode + (rightNode-leftNode)/2;
    int leftVal = query(left, right, node*2, leftNode, mid);
    int rightVal = query(left, right, node*2+1, mid+1, rightNode);
    return merge(leftVal, rightVal);
}

int main(){
    fastio;
    cin>>N;

    SegTree.resize((N+1)*4);
    Pos.resize(N+1);
    Ans.resize(N+1);
    init(1,1,N);
    Kth(1,1,1,N); //수 1은 1번 자리에 미리 놓음
    Pos[1] = 1; //수 1의 위치는 1
    Ans[1] = 1; //1번 자리엔 수 1이 놓여져있음

    for(int i=2;i<=N;i++){
        int P,X; cin>>P>>X;
        int K = (query(1,Pos[P],1,1,N)+X)%SegTree[1];
        if(K==0) K=SegTree[1];
        int Kth_num = Kth(K,1,1,N);
        Pos[i] = Kth_num;
        Ans[Kth_num] = i;
    }

    for(int i=1;i<=N;i++) cout<<Ans[i]<<'\n';
    return 0;
}
```
</details>

- 요세푸스 문제 2 응용 문제이다.
- 처음에 왜 range sum을 써야 하는지 이해가 안갔는데 range sum으로 K에서 지나칠 부분을 구하는 것이다.
- A 다음부터 3칸 떨어진 지점을 구해야 할 때, range_sum으로 1 ~ A 사이에 빈 칸이 몇 개인지 구한 다음, 그 값을 3에 더하면 Kth Query에 사용할 수 있다.
- 물론 적당한 모듈러 연산을 사용해주어야 한다.

### 

###  

###  

# Lazy Propagation
  - 세그먼트 트리에서 구간 업데이트를 빠르게 하기 위한 테크닉
  - 기존엔 update시 리프 노드에 꼭 접근해야만 했다.
  - 리프 노드에는 query에서도 접근한다.
  - 그러므로 update마다 리프노드까지 들어가지 않고, 범위에 걸리면 그 Block 단위로 update를 해주는 것이다.
  - 이후 query나 update에서 필요할 때만 그 아래로 update를 뻗어나가며 Lazy하게 update를 전파해나가는 테크닉이다.
   
###  

## [BOJ 10999 구간 합 구하기 2](https://www.acmicpc.net/problem/10999)
<details>
<summary> 접기/펼치기 </summary>
    
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio cin.tie(NULL)->sync_with_stdio(false)

ll N,M,K;
vector<ll> SegTree;
vector<ll> lazy;
vector<ll> V;

ll merge(ll left, ll right){
    return left + right;
}

ll init(int node, int leftNode, int rightNode){
    if(leftNode==rightNode) return SegTree[node] = V[leftNode];
    ll mid = (leftNode+rightNode)/2;
    ll leftVal = init(node*2, leftNode, mid);
    ll rightVal = init(node*2+1, mid+1, rightNode);
    return SegTree[node] = merge(leftVal, rightVal);
}

void update_Lazy(int node, int leftNode, int rightNode){
    if(lazy[node] != 0){
        SegTree[node] += (rightNode-leftNode+1) * lazy[node];
        if(leftNode != rightNode){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_Range(int left, int right, ll newValue, int node, int leftNode ,int rightNode){
    update_Lazy(node, leftNode, rightNode);
    if(rightNode<left || right<leftNode) return;
    if(left<=leftNode && rightNode<=right){
        SegTree[node] += (rightNode-leftNode+1)*newValue;
        if(leftNode != rightNode){
            lazy[node*2] += newValue;
            lazy[node*2+1] += newValue;
        }
        return;
    }
    ll mid = (leftNode + rightNode)/2;
    update_Range(left, right, newValue, node*2, leftNode, mid);
    update_Range(left, right, newValue, node*2+1, mid+1, rightNode);
    SegTree[node] = SegTree[node*2] + SegTree[node*2+1];
}

ll query(int left, int right, int node, int leftNode, int rightNode){
    update_Lazy(node, leftNode, rightNode);
    if(rightNode<left || right<leftNode) return 0;
    if(left<=leftNode && rightNode<=right) return SegTree[node];
    ll mid = (leftNode+rightNode)/2;
    ll leftVal = query(left, right, node*2, leftNode, mid);
    ll rightVal = query(left, right, node*2+1, mid+1, rightNode);
    return merge(leftVal, rightVal);
}

int main(){
    fastio;
    cin>>N>>M>>K; M+=K;
    V.resize(N+1); SegTree.resize((N+1)*4); lazy.resize((N+1)*4);
    for(int i=1;i<=N;i++) cin>>V[i];
    init(1,1,N);
    while(M--){
        int q; cin>>q;
        if(q==1){ //update
            ll a,b,c; cin>>a>>b>>c;
            update_Range(a,b,c,1,1,N);
        }
        if(q==2){
            ll a,b; cin>>a>>b;
            cout<<query(a,b,1,1,N)<<'\n';
        }
    }
    return 0;
}
```
</details>

- Lazy Sum

###  

## [BOJ 12844 XOR](https://www.acmicpc.net/problem/12844)
<details>
<summary> 접기/펼치기 </summary>
    
```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N,M;
vector<int> V;
vector<int> SegTree;
vector<int> Lazy;

int merge(int left, int right){
    return left^right;
}

int init(int node, int leftNode, int rightNode){
    if(leftNode==rightNode) return SegTree[node]=V[leftNode];
    int mid = leftNode + (rightNode-leftNode)/2;
    int leftval = init(node*2, leftNode, mid);
    int rightVal = init(node*2+1, mid+1, rightNode);
    return SegTree[node] = merge(leftval, rightVal);
}

void update_Lazy(int node, int leftNode, int rightNode){
    if(Lazy[node]!=0){
        SegTree[node] = (rightNode-leftNode+1)%2?SegTree[node]^Lazy[node]:SegTree[node];
        if(leftNode!=rightNode){
            Lazy[node*2] ^= Lazy[node];
            Lazy[node*2+1] ^= Lazy[node];
        }
        Lazy[node]=0;
    }
}

void update_Range(int left, int right, int newValue, int node, int leftNode, int rightNode){
    update_Lazy(node, leftNode, rightNode);
    if(rightNode<left || right<leftNode) return;
    if(left<=leftNode && rightNode<=right){
        SegTree[node] = (rightNode-leftNode+1)%2?SegTree[node]^newValue:SegTree[node];
        if(leftNode != rightNode){
            Lazy[node*2] ^= newValue;
            Lazy[node*2+1] ^= newValue;
        }
        return;
    }
    int mid = leftNode + (rightNode-leftNode)/2;
    update_Range(left, right, newValue, node*2, leftNode, mid);
    update_Range(left, right, newValue, node*2+1, mid+1, rightNode);
    SegTree[node] = SegTree[node*2] ^ SegTree[node*2+1];
}

int query(int left, int right, int node, int leftNode, int rightNode){
    update_Lazy(node, leftNode, rightNode);
    if(rightNode<left || right<leftNode) return 0;
    if(left<=leftNode && rightNode<=right) return SegTree[node];
    int mid = leftNode + (rightNode-leftNode)/2;
    int leftval = query(left, right, node*2, leftNode, mid);
    int rightVal = query(left, right, node*2+1, mid+1, rightNode);
    return merge(leftval, rightVal);
}

int main(){
    fastio;
    cin>>N; V.resize(N);
    for(int i=0;i<N;i++) cin>>V[i];
    SegTree.resize(N*4); Lazy.resize(N*4);
    init(1,0,N-1);
    cin>>M;
    while(M--){
        int q; cin>>q;
        if(q==1){
            int i,j,k; cin>>i>>j>>k;
            update_Range(i,j,k,1,0,N-1);
        }
        if(q==2){
            int i,j; cin>>i>>j;
            cout<<query(i,j,1,0,N-1)<<'\n';
        }
    }
    return 0;
}
```
</details>

- Lazy XOR
- [BOJ 14245](https://www.acmicpc.net/problem/14245)는 같은 문젠데 Point query.

###  

## [BOJ 1395 스위치](https://www.acmicpc.net/problem/1395)
<details>
<summary> 접기/펼치기 </summary>
    
```cpp
//Range 'Not' update Query

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N, M;
vector<int> SegTree;
vector<int> Lazy;

void init(){
    SegTree.resize(4*N);
    Lazy.resize(4*N);
}

void update_Lazy(int node, int leftNode, int rightNode){
    if(Lazy[node]!=0){
        SegTree[node] = (leftNode-rightNode+1)-SegTree[node];
        if(leftNode != rightNode){
            Lazy[node*2] = !Lazy[node*2];
            Lazy[node*2+1] = !Lazy[node*2+1];
        }
        Lazy[node] = 0;
    }
}

void update_Range(int left, int right, int node, int leftNode, int rightNode){
    update_Lazy(node, leftNode, rightNode);
    if(rightNode<left || right<leftNode) return;
    if(left<=leftNode && rightNode<=right){
        SegTree[node] = (leftNode-rightNode+1)-SegTree[node];
        if(leftNode != rightNode){
            Lazy[node*2] = !Lazy[node*2];
            Lazy[node*2+1] = !Lazy[node*2+1]; 
        }
        return;
    }
    int mid = leftNode + (rightNode-leftNode)/2;
    update_Range(left, right, node*2, leftNode, mid);
    update_Range(left, right, node*2+1, mid+1, rightNode);
    SegTree[node] = SegTree[node*2] + SegTree[node*2+1];
}

int query(int left, int right, int node, int leftNode, int rightNode){
    update_Lazy(node, leftNode, rightNode);
    if(rightNode<left || right<leftNode) return 0;
    if(left<=leftNode && rightNode<=right) return SegTree[node];
    int mid = leftNode + (rightNode-leftNode)/2;
    int leftVal = query(left, right, node*2, leftNode, mid);
    int rightVal = query(left, right, node*2+1, mid+1, rightNode);
    return leftVal + rightVal;
}

int main(){
    fastio;
    cin>>N>>M;
    init();
    while(M--){
        int q,a,b; cin>>q>>a>>b;
        if(q==0) update_Range(a,b,1,1,N);
        if(q==1) cout<<query(a,b,1,1,N)<<'\n';
    }
    return 0;
}
```
</details>

- Range Not Update, Range Sum Query
- Lazy Seg는 연산에 따라 쿼리가 조금씩 바뀌어서 조금 어려운 듯 하다.

###  

###  

# imos법
  - imos라는 유저가 만든 것으로 알고 있다.
  - 구간 덧셈 업데이트를 빠르게 하는 테크닉이다.
  - 스위핑, 누적합 등 다양한 곳에서 쉽게 사용될 수 있다.
  - [관련 링크](https://driip.me/65d9b58c-bf02-44bf-8fba-54d394ed21e0)
   
###  

## [BOJ 17353 하늘에서 떨어지는 1, 2, ..., R-L+1개의 별](https://www.acmicpc.net/problem/17353)
<details>
<summary> 접기/펼치기 </summary>
    
```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

ll N, M;
vector<ll> V;
vector<ll> Seg;
vector<ll> Lazy;

void update_Lazy(ll node, ll leftNode, ll rightNode){
    if(Lazy[node]){
        Seg[node] += (rightNode-leftNode+1)*Lazy[node];
        if(leftNode != rightNode){
            Lazy[node*2] += Lazy[node];
            Lazy[node*2+1] += Lazy[node];
        }
        Lazy[node] = 0;
    }
}

//imos법을 사용하기에, a~b는 value를 1로, b+1은 value를 -(b-a+1)로 설정
void update_Range(int left, int right, int value, int node, int leftNode, int rightNode){
    update_Lazy(node, leftNode, rightNode);
    if(rightNode<left || right<leftNode) return;
    if(left<=leftNode && rightNode<=right){
        Seg[node] += (rightNode-leftNode+1)*value;
        if(leftNode != rightNode){
            Lazy[node*2] += value;
            Lazy[node*2+1] += value;
        }
        return;
    }
    ll mid = (leftNode+rightNode)/2;
    update_Range(left, right, value, node*2, leftNode, mid);
    update_Range(left, right, value, node*2+1, mid+1, rightNode);
    Seg[node] = Seg[node*2] + Seg[node*2+1];
}

ll query(int left, int right, int node, int leftNode, int rightNode){
    update_Lazy(node, leftNode, rightNode);
    if(rightNode<left || right<leftNode) return 0;
    if(left<=leftNode && rightNode<=right) return Seg[node];
    ll mid = (leftNode+rightNode)/2;
    ll leftVal = query(left, right, node*2, leftNode, mid);
    ll rightVal = query(left, right, node*2+1, mid+1, rightNode);
    return leftVal + rightVal;
}

int main(){
    fastio;
    cin>>N;
    V.resize(N+1); Seg.resize(4*N); Lazy.resize(4*N);
    for(int i=1;i<=N;i++) cin>>V[i];
    cin>>M;
    while(M--){
        ll Q; cin>>Q;
        if(Q==1){ //update
            ll a, b; cin>>a>>b;
            update_Range(a,b,1,1,1,N);
            update_Range(b+1,b+1,-(b-a+1),1,1,N);
        }
        if(Q==2){ //Point Query
            ll a; cin>>a;
            cout<<query(1,a,1,1,N)+V[a]<<'\n';
        }
    }
    return 0;
}
```
</details>

- 구간에 1을 더해주고 누적합을 해서 등차수열을 만들어낼 수 있다.
- 세그먼트 트리의 리프노드에 차이 (1)을 저장시키고, R+1에 imos법으로 -값을 넣어준다.
