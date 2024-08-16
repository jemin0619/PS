#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int N, M;
vector<ll> Segtree;
vector<ll> V;

ll merge(ll left, ll right){
    return left+right;
}

ll init(int node, int leftNode, int rightNode){
    if(leftNode == rightNode) return Segtree[node] = V[leftNode];
    int mid = leftNode + (rightNode-leftNode)/2;
    ll leftVal = init(node*2, leftNode, mid);
    ll rightVal = init(node*2 +1, mid+1, rightNode);
    return Segtree[node] = merge(leftVal, rightVal);
}

ll query(int left, int right, int node, int leftNode, int rightNode){
    if(rightNode<left || right<leftNode) return 0; //sum -> deault = 0
    if(left<=leftNode && rightNode<=right) return Segtree[node];
    int mid = leftNode + (rightNode-leftNode)/2;
    ll leftVal = query(left, right, node*2, leftNode, mid);
    ll rightVal = query(left, right, node*2 +1, mid+1, rightNode);
    return merge(leftVal, rightVal);
}

ll update(int idx, int newValue, int node, int leftNode, int rightNode){
    if(idx<leftNode || rightNode<idx) return Segtree[node];
    if(leftNode == rightNode) return Segtree[node] += newValue;
    int mid = leftNode + (rightNode-leftNode)/2;
    ll leftVal = update(idx, newValue, node*2, leftNode, mid);
    ll rightVal = update(idx, newValue, node*2 +1, mid+1, rightNode);
    return Segtree[node] = merge(leftVal, rightVal);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    V.resize(N+1); 
    Segtree.resize(4*N); init(1,1,N);
    while(M--){
        int q,a,b; cin>>q>>a>>b;
        if(q==1){
            update(a,b,1,1,N);
        }
        if(q==2){
            cout<<query(a,b,1,1,N)<<'\n';
        }
    }
    return 0;
}
