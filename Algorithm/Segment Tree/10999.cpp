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
