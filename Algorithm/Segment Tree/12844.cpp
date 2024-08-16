//XOR + Segment Tree + Lazy Propagation
//어떤 수 X에 대해 X^X는 항상 0이다.
//또, X^0은 항상 X이다.
//그러므로 어떤 수 X, Y가 있을 때, X ^ Y ^ Y 는 항상 X이다.
//X에 Y를 짝수 번 XOR한 값을 XOR하면 X가 나오고, 홀수 번 XOR한 값을 XOR하면 X^Y가 나온다.
//Block 단위로 Merge할 때 주의해야 할 필요가 있던 문제였다.

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
