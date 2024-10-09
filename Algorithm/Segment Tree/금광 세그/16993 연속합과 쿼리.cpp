//가장 기본적인 금광세그 문제였다.
//굳이 seg 생성자를 만들지 않아도 tuple처럼 값을 순서대로 할당시킬 수 있다.
//fastio를 빼서 TLE를 수차례 받았었다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
const ll inf = 1e9;

struct seg{
    ll all, left, right, mx;
};

vector<seg> Seg;

seg merge(seg L, seg R){
    seg ret;
    ret.all = L.all + R.all;
    ret.left = max(L.left, L.all+R.left);
    ret.right = max(R.right, R.all+L.right);
    ret.mx = max({L.mx, R.mx, L.right+R.left});
    return ret;
}

seg query(int left, int right, int node, int leftNode, int rightNode){
    if(right<leftNode || rightNode<left) return {0, -inf, -inf, -inf};
    if(left<=leftNode && rightNode<=right) return Seg[node];
    ll mid = (leftNode+rightNode)/2;
    seg leftVal = query(left, right, node*2, leftNode, mid);
    seg rightVal = query(left, right, node*2+1, mid+1, rightNode);
    return merge(leftVal, rightVal);
}

seg update(int idx, ll val, int node, int leftNode, int rightNode){
    if(idx<leftNode || rightNode<idx) return Seg[node];
    if(leftNode==rightNode) return Seg[node] = {val, val, val, val};
    ll mid = (leftNode+rightNode)/2;
    seg leftVal = update(idx, val, node*2, leftNode, mid);
    seg rightVal = update(idx, val, node*2+1, mid+1, rightNode);
    return Seg[node] = merge(leftVal, rightVal);
}

int main(){
    fastio;
    int N; cin>>N;
    Seg.resize(N*4 + 3);
    for(int i=0; i<N; i++){
        ll x; cin>>x;
        update(i, x, 1, 0, N-1);
    }
    int M; cin>>M;
    while(M--){
        int a, b; cin>>a>>b;
        a--; b--;
        seg ans = query(a, b, 1, 0, N-1);
        cout<<ans.mx<<'\n';
    }
    return 0;
}
