//(j-i)*V 를 어떻게 처리할지가 고민되는 문제이다.
//이건 구간에 속하는 원소들의 개수 * V를 의미하므로 따로 처리하지 않고 update 시에 +V를 붙여놓으면 간단해진다.
//이후 query의 결과에서 -V를 해주면 된다.
//switch case를 간만에 써보는데 쿼리 문제에서는 종종 써도 괜찮아보인다.

//K가 입력될 때마다 세그먼트 트리의 해당 인덱스를 U*K + V 로 업데이트
//이렇게 하면 알아서 V 항이 처리된다. 
//query.mx에서 -V를 하면 TC에 알맞은 답이 나온다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
const ll inf = 1e9;

struct seg{
    ll all, left, right, mx;
    seg() : all(0), left(-inf), right(-inf), mx(-inf) {}
    seg(ll a, ll b, ll c, ll d) : all(a), left(b), right(c), mx(d) {}
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

seg update(int idx, ll val, int node, int leftNode, int rightNode){
    if(idx<leftNode || rightNode<idx) return Seg[node];
    if(leftNode==rightNode) return Seg[node] = seg(val, val, val, val);
    ll mid = leftNode+rightNode; mid/=2;
    seg leftVal = update(idx, val, node*2, leftNode, mid);
    seg rightVal = update(idx, val, node*2+1, mid+1, rightNode);
    return Seg[node] = merge(leftVal, rightVal);
}

seg query(int left, int right, int node, int leftNode, int rightNode){
    if(rightNode<left || right<leftNode) return seg();
    if(left<=leftNode && rightNode<=right) return Seg[node];
    ll mid = leftNode+rightNode; mid/=2;
    seg leftVal = query(left, right, node*2, leftNode, mid);
    seg rightVal = query(left, right, node*2+1, mid+1, rightNode);
    return merge(leftVal, rightVal);
}

int main(){
    fastio;
    int N,Q,U,V; cin>>N>>Q>>U>>V;
    Seg.resize(N*4);
    for(int i=0; i<N; i++){
        ll x; cin>>x;
        update(i, x*U+V, 1, 0, N-1);
    }
    while(Q--){
        ll a, b, c;
        cin>>a>>b>>c;
        switch(a){
            case 0:
                b--; c--;
                cout<<query(b, c, 1, 0, N-1).mx - V<<'\n';
                break;
            case 1:
                b--;
                update(b, c*U+V, 1, 0, N-1);
                break;
        }
    }
    return 0;
}
