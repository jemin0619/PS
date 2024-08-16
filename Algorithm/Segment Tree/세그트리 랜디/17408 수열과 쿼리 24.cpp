//큰 값 두 개를 저장하는 세그먼트 트리를 만들어야 한다.
//update에서는 {val,0} 형태로 값을 갱신해서 val값 1개만 넣어지도록 한다.

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ff first 
#define ss second 

vector<pii> Seg;

pii merge(pii left, pii right){
    vector<int> V = {left.ff, left.ss, right.ff, right.ss};
    sort(V.begin(), V.end());
    return {V[2], V[3]};
}

pii update(int idx, int val, int node, int leftNode, int rightNode){
    if(idx<leftNode || rightNode<idx) return Seg[node];
    if(leftNode==rightNode) return Seg[node] = {val, 0};
    int mid = leftNode+rightNode; mid/=2;
    pii leftVal = update(idx, val, node*2, leftNode, mid);
    pii rightVal = update(idx, val, node*2+1, mid+1, rightNode);
    return Seg[node] = merge(leftVal, rightVal);
}

pii query(int left, int right, int node, int leftNode, int rightNode){
    if(rightNode<left || right<leftNode) return {0,0};
    if(left<=leftNode && rightNode<=right) return Seg[node];
    int mid = leftNode+rightNode; mid/=2;
    pii leftVal = query(left, right, node*2, leftNode, mid);
    pii rightVal = query(left, right, node*2+1, mid+1, rightNode);
    return merge(leftVal, rightVal);
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    int N; cin>>N;
    Seg.resize(N*4);
    for(int i=0; i<N; i++){
        int x; cin>>x;
        update(i, x, 1, 0, N-1);
    }
    int M; cin>>M;
    while(M--){
        int q,a,b; cin>>q>>a>>b;
        if(q==1) update(a-1, b, 1, 0, N-1);
        if(q==2){
            pii ans = query(a-1, b-1, 1, 0, N-1);
            cout<<ans.ff+ans.ss<<'\n';
        }
    }
    return 0;
}
