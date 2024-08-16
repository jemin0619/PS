#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> Segtree;
vector<int> V;

int merge(int left, int right){
    return left*right;
}

int init(int node, int leftNode, int rightNode){
    if(leftNode == rightNode) return Segtree[node] = V[leftNode];
    int mid = leftNode + (rightNode-leftNode)/2;
    int leftVal = init(node*2, leftNode, mid);
    int rightVal = init(node*2 +1, mid+1, rightNode);
    return Segtree[node] = merge(leftVal, rightVal);
}

int query(int left, int right, int node, int leftNode, int rightNode){
    if(rightNode<left || right<leftNode) return 1; //multiply -> default = 1
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
    while(cin>>N>>M){
        Segtree.clear(); V.clear();
        V.resize(N+1); Segtree.resize(4*N);
        for(int i=1;i<=N;i++){
            cin>>V[i];
            if(V[i]>0) V[i]=1;
            else if(V[i]<0) V[i]=-1;
        } init(1,1,N);
        while(M--){
            char q; int a,b; cin>>q>>a>>b;
            if(q=='C'){
                if(b>0) b=1;
                if(b<0) b=-1;
                update(a,b,1,1,N);
            }
            if(q=='P'){
                int val = query(a,b,1,1,N);
                if(val>0) cout<<"+";
                else if(val<0) cout<<"-";
                else cout<<"0";
            }
        }
        cout<<'\n';
    }
    return 0;
}
