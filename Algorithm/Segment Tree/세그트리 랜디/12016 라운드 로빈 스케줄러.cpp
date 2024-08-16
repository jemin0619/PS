//같은 value를 갖는 값들은 큐에 넣고 한 번에 update를 처리해준다.
//위치에 상관없이 작은 값이 먼저 처리되고, 같은 값이면 앞에 있는 값이 먼저 처리된다는 것을 알 수 있다.
//그러므로 입력을 정렬하고, 작은 값부터 처리하는 오프라인 쿼리의 방식으로 문제를 풀 수 있다.

//세그먼트 트리의 각 노드에는 그 인덱스가 처리되었는지의 유무(1, 0)을 저장하였다.
//이를 통해 인덱스 i에 있는 수의 실제 위치(앞의 수 몇 개가 지워지면 위치가 바뀜)도 구간합으로 구할 수 있다.

//T :이전 바퀴까지 처리하는데 든 총 시간
//cycle :돈 바퀴 수
//pre :이전 값

//이 세 변수만 있으면 처리되는 순서를 구할 수 있는데, 
//Ans[i] = T + (val-cycle-1)*Tree[1] + newIdx
//이전 바퀴까지 처리하는데 든 시간에, 현재 값이 1이 될때가지 (돌아야 하는 바퀴 수 - 현재 돈 바퀴 수)를 더하고,
//현재 값의 실제 인덱스를 더하면 된다.
//왜 이런 식이 도출되는지는 조금만 생각해보면 알 수 있다.

//거의 첫 플레 자력솔이라 뿌듯하다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define ff first 
#define ss second

template <typename T>
struct SegTree{
    int N;
    vector<T> Tree;
    SegTree(int N):N(N){Tree.resize(4*N);}

    T update(int idx, T val, int node, int leftNode, int rightNode){
        if(idx<leftNode || rightNode<idx) return Tree[node];
        if(leftNode==rightNode) return Tree[node]=val;
        ll mid = (leftNode+rightNode)/2;
        T leftVal = update(idx, val, node*2, leftNode, mid);
        T rightVal = update(idx, val, node*2+1, mid+1, rightNode);
        return Tree[node] = leftVal + rightVal;
    }

    T query(int left, int right, int node, int leftNode, int rightNode){
        if(rightNode<left || right<leftNode) return 0;
        if(left<=leftNode && rightNode<=right) return Tree[node];
        ll mid = (leftNode+rightNode)/2;
        T leftVal = query(left, right, node*2, leftNode, mid);
        T rightVal = query(left, right, node*2+1, mid+1, rightNode);
        return leftVal + rightVal;
    }
};

int main(){
    fastio;
    int N; cin>>N;
    vector<ll> V(N+1);
    vector<pair<ll,ll>> Query(N+1);
    vector<ll> Ans(N+1);
    SegTree<ll> Seg(N+1);

    for(int i=1; i<=N; i++){
        cin>>V[i];
        Query[i] = {V[i], i};
        Seg.update(i, 1, 1, 1, N);
    }
    sort(Query.begin()+1, Query.end());
    
    ll T = 0;
    ll cycle = 0;
    ll pre = 0;
    queue<ll> Q;

    for(int i=1; i<=N; i++){
        ll val = Query[i].first;
        ll idx = Query[i].second;
        ll nidx = Seg.query(1, idx, 1, 1, N);
        ll All = Seg.query(1, N, 1, 1, N);
        
        Ans[idx] = T + (val-cycle-1)*All + nidx;

        Q.push(idx);
        if(i+1<=N && Query[i+1].first!=val){
            T += (val-cycle)*All;
            cycle += val-pre;
            pre = val;
            while(!Q.empty()){
                int X = Q.front(); Q.pop();
                Seg.update(X, 0, 1, 1, N);
            }
        }
    }

    for(int i=1; i<=N; i++){
        cout<<Ans[i]<<'\n';
    }
    return 0;
}
