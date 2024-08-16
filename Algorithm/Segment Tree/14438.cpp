#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> Segtree;
vector<int> V;

int merge(int left, int right){
    return min(left, right);
}

int init(int node, int leftNode, int rightNode){
    if(leftNode == rightNode) return Segtree[node] = V[leftNode];
    int mid = leftNode + (rightNode-leftNode)/2;
    int leftVal = init(node*2, leftNode, mid);
    int rightVal = init(node*2 +1, mid+1, rightNode);
    return Segtree[node] = merge(leftVal, rightVal);
}

int query(int left, int right, int node, int leftNode, int rightNode){
    if(rightNode<left || right<leftNode) return 0x7f7f7f7f;
    if(left<=leftNode && rightNode<=right) return Segtree[node];
    int mid = leftNode + (rightNode-leftNode)/2;
    int leftVal = query(left, right, node*2, leftNode, mid);
    int rightVal = query(left, right, node*2 +1, mid+1, rightNode);
    return merge(leftVal, rightVal);
}

int update(int idx, int newValue, int node, int leftNode, int rightNode){
    if(idx<leftNode || rightNode<idx) return Segtree[node];
    if(leftNode == rightNode) return Segtree[node] = newValue;
    int mid = leftNode + (rightNode-leftNode)/2;
    int leftVal = update(idx, newValue, node*2, leftNode, mid);
    int rightVal = update(idx, newValue, node*2 +1, mid+1, rightNode);
    return Segtree[node] = merge(leftVal, rightVal);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N; V.resize(N+1);
    for(int i=1;i<=N;i++) cin>>V[i];
    Segtree.resize(4*N); init(1,1,N);
    cin>>M;
    while(M--){
        int q,a,b; cin>>q>>a>>b;
        if(q==1) update(a,b,1,1,N);
        else cout<<query(a,b,1,1,N)<<'\n';
    }
    return 0;
}
