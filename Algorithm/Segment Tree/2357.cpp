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
