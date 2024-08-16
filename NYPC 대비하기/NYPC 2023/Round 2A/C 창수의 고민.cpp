//https://flappybird.tistory.com/m/67

//세그먼트 트리 or 펜윅 트리
//좌표압축
//그리디

//구간합 쿼리 값을 담는 변수 타입을 int로 해서 5,6이 WA였는데 해결함
//구간합만 써야하면 펜윅 쓰는게 더 간결하긴 한거같은데, 
//펜윅 쓰면 좌표압축에서 -1, +1 등을 추가로 넣어줘야하는 불편함이 있는듯 하다
//트리 한 개만 쓰려고 했었는데, 두 개로 푸는게 인상깊었다.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio cin.tie(NULL)->sync_with_stdio(false)

vector<ll> compress(vector<ll>&V){
    vector<ll> tmp(V);
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    return tmp;
}

int getIdx(vector<ll>&V, ll num){
    return lower_bound(V.begin(), V.end(), num) - V.begin();
}

template <typename T>
struct SegTree{
    int N;
    vector<T> Tree;
    SegTree(int N):N(N){Tree.resize(4*N);}
    T update(int idx, ll val, int node, int leftNode, int rightNode){
        if(idx<leftNode || rightNode<idx) return Tree[node];
        if(leftNode==rightNode) return Tree[node]+=val;
        ll mid = (leftNode+rightNode)/2;
        ll leftVal = update(idx, val, node*2, leftNode, mid);
        ll rightVal = update(idx, val, node*2+1, mid+1, rightNode);
        return Tree[node] = leftVal + rightVal;
    }
    T query(int left, int right, int node, int leftNode, int rightNode){
        if(rightNode<left || right<leftNode) return 0;
        if(left<=leftNode && rightNode<=right) return Tree[node];
        ll mid = (leftNode+rightNode)/2;
        ll leftVal = query(left, right, node*2, leftNode, mid);
        ll rightVal = query(left, right, node*2+1, mid+1, rightNode);
        return leftVal + rightVal;
    }
};

int main(){ 
    fastio;
    ll N, K; cin>>N>>K;

    bool isKminus = false;
    if(K<0){isKminus=true; K*=-1;}

    vector<ll> V(N);
    vector<ll> cmpres; 
    for(int i=0; i<N; i++){
        cin>>V[i];
        cmpres.push_back(V[i]);
        cmpres.push_back(V[i]+K);
    }
    cmpres = compress(cmpres);
    
    int M = cmpres.size();
    SegTree<ll> Seg1(M);
    SegTree<ll> Seg2(M);

    ll sum = 0;
    for(int i=0; i<N; i++){
        int idx = getIdx(cmpres, V[i]);
        sum += Seg1.query(idx, M-1, 1, 0, M-1);
        Seg1.update(idx, 1LL, 1, 0, M-1);
    }
    
    ll mx = sum;
    int move = 0;
    for(int i=0; i<N; i++){
        int idx1 = getIdx(cmpres, V[i]);
        int idx2 = getIdx(cmpres, V[i]+K);
        Seg1.update(idx1, (ll)-1, 1, 0, M-1);
        sum += Seg1.query(idx1+1, idx2, 1, 0, M-1);
        sum -= Seg2.query(idx1, idx2-1, 1, 0, M-1);
        Seg2.update(idx2, 1LL, 1, 0, M-1);

        if(mx<=sum){
            mx = sum;
            move = i+1;
        }
    }

    if(!isKminus) cout<<"1 "<<move<<'\n';
    else cout<<min((ll)move+1, N)<<" "<<N<<'\n';
    return 0;
}
