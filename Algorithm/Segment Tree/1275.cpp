#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N,M;
vector<ll> V;
vector<ll> Segtree;

ll merge(ll left, ll right){
    return left + right;
}

ll init(int node, int leftNode, int rightNode){
    if(leftNode==rightNode) return Segtree[node] = V[leftNode];
    ll mid = (leftNode + rightNode)/2;
    ll leftVal = init(node*2, leftNode, mid);
    ll rightVal = init(node*2 +1, mid+1, rightNode);
    return Segtree[node] = merge(leftVal, rightVal);
}

ll query(int left, int right, int node, int leftNode, int rightNode){
    if(rightNode<left || right<leftNode) return 0; //deault 값 반환
    if(left<=leftNode && rightNode<=right) return Segtree[node];
    ll mid = (leftNode + rightNode)/2;
    ll leftVal = query(left, right, node*2, leftNode, mid);
    ll rightVal = query(left, right, node*2 +1, mid+1, rightNode);
    return merge(leftVal, rightVal);
}

ll update(int idx, int newValue, int node, int leftNode, int rightNode){
    if(idx<leftNode || rightNode<idx) return Segtree[node];
    if(leftNode==rightNode) return Segtree[node]=newValue;
    ll mid = (leftNode + rightNode)/2;
    ll leftVal = update(idx, newValue, node*2, leftNode, mid);
    ll rightVal = update(idx, newValue, node*2 +1, mid+1, rightNode);
    return Segtree[node] = merge(leftVal, rightVal);
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    cin>>N>>M;
    V.resize(N+1);
    for(int i=1;i<=N;i++) cin>>V[i];
    Segtree.resize(4*N); init(1,1,N);
    while(M--){
        int x,y,a,b; cin>>x>>y>>a>>b;
        int mx = max(x,y);
        int mn = min(x,y);
        cout<<query(mn,mx,1,1,N)<<'\n';
        update(a,b,1,1,N);
    }
    return 0;
}
