//금광세그 변형이다.
//merge는 일단 mx를 제외한 기본 값을 채워넣는다.
//두 노드를 합칠 수 있는 경우엔 left, right, mx를 조건에 따라 갱신해준다.
//마지막으로 mx를 알맞은 값으로 갱신해주고 반환한다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

//L은 0, R은 1

struct seg{
    ll left, right, mx, stidx, enidx; //all은 없어도 되서 제외함
    seg() : left(0), right(0), mx(0), stidx(0), enidx(0) {}
    seg(ll a, ll b, ll c, ll d, ll e) : left(a), right(b), mx(c), stidx(d), enidx(e) {}
};

vector<seg> Seg;
vector<int> V;

seg merge(seg L, seg R){
    seg ret = seg(L.left, R.right, 1, L.stidx, R.enidx);
    ll Lsize = L.enidx-L.stidx+1;
    ll Rsize = R.enidx-R.stidx+1;
    if(V[L.enidx] != V[R.stidx]){ //두 노드를 합칠 수 있는 경우
        if(L.left==Lsize) ret.left += R.left; //기존에 left에 넣었던 값이 L 전체라면 R.left를 합침
        if(R.right==Rsize) ret.right += L.right; //기존에 right에 넣었던 값이 R 전체라면 L.right를 합침
        ret.mx = L.right + R.left; //mx값을 두 노드의 경계선에 걸친 값들의 합으로 세팅
    }
    ret.mx = max({ret.mx, L.mx, R.mx, ret.left, ret.right});
    return ret;
}

seg update(int idx, int val, int node, int leftNode, int rightNode){
    if(idx<leftNode || rightNode<idx) return Seg[node];
    if(leftNode==rightNode) {V[idx]=!V[idx]; return Seg[node] = seg(1, 1, 1, idx, idx);}
    ll mid = leftNode+rightNode; mid/=2;
    seg leftVal = update(idx, val, node*2, leftNode, mid);
    seg rightVal = update(idx, val, node*2+1, mid+1, rightNode);
    return Seg[node] = merge(leftVal, rightVal);
}

int main(){
    fastio;
    int N, M; cin>>N>>M;
    Seg.resize(N*4);
    V.resize(N, 0);

    for(int i=0; i<N; i++){
        update(i, 0, 1, 0, N-1);
    }
  
    while(M--){
        int x; cin>>x; x--;
        update(x, !V[x], 1, 0, N-1);
        cout<<Seg[1].mx<<'\n';
    }
    return 0;
}
