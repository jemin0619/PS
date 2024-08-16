#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define pii pair<int,int> 
#define ff first
#define ss second

vector<pii> Seg; //짝수 홀수
vector<int> V;

pii merge(pii left, pii right){
    return {left.ff+right.ff, left.ss+right.ss};
}

pii init(int node, int leftNode, int rightNode){
    if(leftNode==rightNode) return Seg[node] = {V[leftNode]%2==0, V[leftNode]%2==1};
    int mid = leftNode + (rightNode-leftNode)/2;
    pii leftVal = init(node*2, leftNode, mid);
    pii rightVal = init(node*2 +1, mid+1, rightNode);
    return Seg[node] = merge(leftVal, rightVal);
}

pii query(int left, int right, int node, int leftNode, int rightNode){
    if(rightNode<left || right<leftNode) return {0,0};
    if(left<=leftNode && rightNode<=right) return Seg[node];
    int mid = leftNode + (rightNode-leftNode)/2;
    pii leftVal = query(left, right, node*2, leftNode, mid);
    pii rightVal = query(left, right, node*2 +1, mid+1, rightNode);
    return merge(leftVal, rightVal);
}

pii update(int idx, int newValue, int node, int leftNode, int rightNode){
    if(idx<leftNode || rightNode < idx) return Seg[node];
    if(leftNode == rightNode) return Seg[node] = {newValue%2==0, newValue%2==1};
    int mid = leftNode + (rightNode-leftNode)/2;
    pii leftVal = update(idx, newValue, node*2, leftNode, mid);
    pii rightVal = update(idx, newValue, node*2 +1, mid+1, rightNode);
    return Seg[node] = merge(leftVal, rightVal);
}

int main(){
    fastio;
    int N; cin>>N;
    V.resize(N+1);
    Seg.resize(4*N);
    for(int i=1;i<=N;i++) cin>>V[i];
    init(1,1,N);
    int M; cin>>M;
    while(M--){
        int q,a,b; cin>>q>>a>>b;
        if(q==1) update(a,b,1,1,N);
        if(q==2) cout<<query(a,b,1,1,N).ff<<'\n';
        if(q==3) cout<<query(a,b,1,1,N).ss<<'\n';
    }
}
