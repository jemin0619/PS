//https://pooreumjung.tistory.com/314

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

template <typename T>
struct MergeSortTree{
    int N;
    vector<vector<T>> Tree;
    MergeSortTree(int N):N(N){Tree.resize(4*N);}
    void init(int node, int leftNode, int rightNode, vector<T>&V){
        if(leftNode==rightNode) {Tree[node].push_back(V[leftNode]); return;}
        ll mid = leftNode+rightNode; mid/=2;
        init(node*2, leftNode, mid, V);
        init(node*2+1, mid+1, rightNode, V);
        Tree[node].resize(Tree[node*2].size()+Tree[node*2+1].size());
        merge(Tree[node*2].begin(), Tree[node*2].end(), Tree[node*2+1].begin(), Tree[node*2+1].end(), Tree[node].begin());
    }
    T query(int K, int left, int right, int node, int leftNode, int rightNode){
        if(rightNode<left || right<leftNode) return 0;
        if(left<=leftNode && rightNode<=right) return Tree[node].end() - upper_bound(Tree[node].begin(), Tree[node].end(), K);
        ll mid = leftNode+rightNode; mid/=2;
        return query(K, left, right, node*2, leftNode, mid) + query(K, left, right, node*2+1, mid+1, rightNode);
    }
};

int main(){
    fastio;
    int N; cin>>N;
    vector<ll> V(N+1);
    for(int i=1; i<=N; i++) cin>>V[i];
    MergeSortTree<ll> mst(N);
    mst.init(1, 1, N, V);
    int M; cin>>M;
    ll ans = 0;
    while(M--){
        ll a,b,c; cin>>a>>b>>c;
        ans = mst.query(c^ans, a^ans, b^ans, 1, 1, N);
        cout<<ans<<'\n';
    }
    return 0;
}
