//SOL1. SegmentTree + dp
//오른쪽에서 왼쪽으로 나오나 왼쪽에서 오른쪽으로 나오나 결과는 같다.
//그러므로 왼쪽에서 시작해 오른쪽 방향으로 이동한다고 생각하고 스위핑을 하면 된다.
//세그먼트 트리의 리프 노드엔 그 위치에서 나왔을 때 얻을 수 있는 최대 점수를 기록해놓고, 
//max value SegmentTree로 O(lgN)에 구간 최댓값을 골라서 문제를 해결할 수 있다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

template <typename T>
struct SegTree{
    int N; 
    vector<T> Tree;
    SegTree(int N):N(N){Tree.resize(N*4);}
    T init(int node, int leftNode, int rightNode, vector<ll>&V){
        if(leftNode==rightNode) return Tree[node]=V[leftNode];
        ll mid = leftNode+rightNode; mid/=2;
        T leftVal = init(node*2, leftNode, mid, V);
        T rightVal = init(node*2+1, mid+1, rightNode, V);
        return Tree[node] = max(leftVal, rightVal);
    }
    T update(int idx, T val, int node, int leftNode, int rightNode){
        if(idx<leftNode || rightNode<idx) return Tree[node];
        if(leftNode==rightNode) return Tree[node]=max(Tree[node], val);
        ll mid = leftNode+rightNode; mid/=2;
        T leftVal = update(idx, val, node*2, leftNode, mid);
        T rightVal = update(idx, val, node*2+1, mid+1, rightNode);
        return Tree[node] = max(leftVal, rightVal);
    }
    T query(int left, int right, int node, int leftNode, int rightNode){
        if(rightNode<left || right<leftNode) return -0x7f7f7f7f;
        if(left<=leftNode && rightNode<=right) return Tree[node];
        ll mid = leftNode+rightNode; mid/=2;
        T leftVal = query(left, right, node*2, leftNode, mid);
        T rightVal = query(left, right, node*2+1, mid+1, rightNode);
        return max(leftVal, rightVal);
    }
};

int main(){
    fastio;
    ll N, D; cin>>N>>D;
    SegTree<ll> Seg(N);
    vector<ll> V(N);
    for(int i=0; i<N; i++) cin>>V[i];
    Seg.init(1,0,N-1,V);
    for(int i=0; i<N; i++){
        ll val = V[i] + Seg.query(i-D, i-1, 1, 0, N-1);
        Seg.update(i, val, 1, 0, N-1);
    }
    cout<<Seg.query(0, N-1, 1, 0, N-1);
    return 0;
}
