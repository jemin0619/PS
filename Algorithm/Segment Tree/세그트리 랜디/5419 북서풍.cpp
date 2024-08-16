#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define pii pair<int,int>
#define ff first 
#define ss second

template <typename T>
struct SegmentTree{
    int N;
    vector<T> Tree;
    SegmentTree(int N):N(N){Tree.resize(4*N);}
    T update(int idx, T val, int node, int leftNode, int rightNode){
        if(idx<leftNode || rightNode<idx) return Tree[node];
        if(leftNode==rightNode) return Tree[node]+=val;
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

bool cmpV(pii&A, pii&B){
    if(A.ff == B.ff){
        return A.ss>B.ss;
    }
    return A.ff<B.ff;
}

int main(){
    fastio;
    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        vector<pii> V(N);
        vector<int> X(N);

        //V에 {y축, x축}으로 저장
        for(int i=0; i<N; i++) cin>>V[i].ss>>V[i].ff, X[i]=V[i].ss;

        //X축 좌표압축
        sort(X.begin(), X.end());
        X.erase(unique(X.begin(), X.end()), X.end());
        for(pii&val : V) val.ss = lower_bound(X.begin(), X.end(), val.ss) - X.begin();

        //Y가 작은 순으로, X가 큰 순으로 정렬
        sort(V.begin(), V.end(), cmpV);
        
        int SZ = X.size();
        SegmentTree<ll> Seg(SZ);
        
        ll Ans = 0;
        for(int i=0; i<N; i++){
            auto&[y,x] = V[i];
            Ans += Seg.query(x, SZ, 1, 0, SZ-1);
            Seg.update(x, 1, 1, 0, SZ-1);
        }
        cout<<Ans<<'\n';
    }   
    return 0;
}
