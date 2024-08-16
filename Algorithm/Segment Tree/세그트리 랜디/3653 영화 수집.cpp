#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

template <typename T>
struct Seg{
    int N;
    vector<T> Tree;
    Seg(int N):N(N){Tree.resize(N+3);}
    T update(int idx, T val, int node, int leftNode, int rightNode){
        if(idx<leftNode || rightNode<idx) return Tree[node];
        if(leftNode==rightNode) return Tree[node]=val;
        int mid = (leftNode+rightNode)/2;
        T leftVal = update(idx, val, node*2, leftNode, mid);
        T rightVal = update(idx, val, node*2+1, mid+1, rightNode);
        return Tree[node] = leftVal + rightVal;
    }
    T query(int left, int right, int node, int leftNode, int rightNode){
        if(rightNode<left || right<leftNode) return 0;
        if(left<=leftNode && rightNode<=right) return Tree[node];
        int mid = (leftNode+rightNode)/2;
        T leftVal = query(left, right, node*2, leftNode, mid);
        T rightVal = query(left, right, node*2+1, mid+1, rightNode);
        return leftVal + rightVal;
    }
};

int main(){
    fastio;
    int T; cin>>T;
    while(T--){
        int N, M; cin>>N>>M;
        Seg<ll> SegTree(4*(N+M));
        vector<int> pos(N+1);
        for(int i=1; i<=N; i++){
            SegTree.update(N-i+1, 1, 1, 1, N+M);
            pos[i] = N-i+1;
        }
        int mx=N;
        for(int i=1; i<=M; i++){
            int x; cin>>x;
            SegTree.update(pos[x], 0, 1, 1, N+M);
            cout<<SegTree.query(pos[x]+1, mx, 1, 1, N+M)<<' ';
            mx++;
            pos[x] = mx;
            SegTree.update(pos[x], 1, 1, 1, M+N);
        }
        cout<<'\n';
    }
    return 0;
}
