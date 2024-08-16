//SegTree + Lazy + point query

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N, M;
vector<int> SegTree;
vector<int> Lazy;
vector<int> V;

int merge(int left, int right){
    return left^right;
}

int init(int node, int leftNode, int rightNode){
    if(leftNode == rightNode) return SegTree[node] = V[leftNode];
    int mid = leftNode + (rightNode-leftNode)/2;
    int leftVal = init(node*2, leftNode, mid);
    int rightVal = init(node*2+1, mid+1, rightNode);
    return SegTree[node] = merge(leftVal, rightVal);
}

void update_Lazy(int node, int leftNode, int rightNode){
    if(Lazy[node]!=0){
        SegTree[node] = (rightNode-leftNode+1)%2?SegTree[node]^Lazy[node]:SegTree[node];
        if(leftNode != rightNode){
            Lazy[node*2] ^= Lazy[node];
            Lazy[node*2+1] ^= Lazy[node];
        }
        Lazy[node] = 0;
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
    update_Range(left, right, newValue, node*2, leftNode ,mid);
    update_Range(left, right, newValue, node*2+1, mid+1, rightNode);
}

int query(int idx, int node, int leftNode, int rightNode){
    update_Lazy(node, leftNode, rightNode);
    if(idx<leftNode || rightNode<idx) return 0;
    if(leftNode==rightNode) return SegTree[node];
    int mid = leftNode + (rightNode-leftNode)/2;
    int leftVal = query(idx, node*2, leftNode, mid);
    int rightVal = query(idx, node*2+1, mid+1, rightNode);
    return merge(leftVal, rightVal);
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
            int a,b,c; cin>>a>>b>>c;
            update_Range(a,b,c,1,0,N-1);
        }
        if(q==2){
            int a; cin>>a;
            cout<<query(a,1,0,N-1)<<'\n';
        }
    }
    return 0;
}
