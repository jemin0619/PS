//merge에서 L과 R을 합치는 경우
//L.left가 L 전체인지, R.right가 R 전체인지 확인해주기 위한 변수를 구조체에 추가해줘야함
//또 조건문에 (L.left길이==L길이 && L.left!=0) 으로 해줘야 0을 섞지 않을 수 있다.

//mxval이 0인 경우도 예외처리해줘야할듯

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

struct seg{
    ll mxIdx, mxVal;
    ll left, right, mx;
    ll llen, rlen;
    seg() : mxIdx(-1), mxVal(-1), left(0), right(0), mx(0), llen(0), rlen(0) {}
    seg(ll a, ll b, ll c, ll d, ll e, ll f, ll g) : mxIdx(a), mxVal(b), left(c), right(d), mx(e), llen(f), rlen(g) {}
};

vector<ll> V;
vector<seg> Seg;

seg merge(seg L, seg R, int Lst, int Len, int Rst, int Ren){
    if(L.mxIdx==-1) return R;
    if(R.mxIdx==-1) return L;
    seg ret = seg(-1, -1, L.left, R.right, -1, L.llen, R.rlen);
    if(L.mxVal>=R.mxVal) {ret.mxVal=L.mxVal; ret.mxIdx=L.mxIdx;}
    if(L.mxVal<R.mxVal) {ret.mxVal=R.mxVal; ret.mxIdx=R.mxIdx;}
    int Rsize = Ren-Rst+1;
    int Lsize = Len-Lst+1;
    if(V[Len]>0 && V[Rst]>0){
        if(L.llen==Lsize){
            ret.llen += R.llen;
            ret.left += R.left;
        }
        if(R.rlen==Rsize){
            ret.rlen += L.rlen;
            ret.right += L.right;
        }
        ret.mx = L.right + R.left;
    }
    ret.mx = max({ret.mx, L.mx, R.mx, ret.left, ret.right});
    return ret;
}

seg update(int idx, ll val, int node, int leftNode, int rightNode){
    if(idx<leftNode || rightNode<idx) return Seg[node];
    if(leftNode==rightNode){
        if(val!=0) return Seg[node] = seg(idx, val, val, val, val, 1, 1);
        else return Seg[node] = seg(idx, val, val, val, val, 0, 0);
    }
    ll mid = (leftNode+rightNode)/2;
    seg leftVal = update(idx, val, node*2, leftNode, mid);
    seg rightVal = update(idx, val, node*2+1, mid+1, rightNode);
    return Seg[node] = merge(leftVal, rightVal, leftNode, mid, mid+1, rightNode);
}

seg query(int left, int right, int node, int leftNode, int rightNode){
    if(rightNode<left || right<leftNode) return seg(-1,-1,-1,-1,-1,-1,-1);
    if(left<=leftNode && rightNode<=right) return Seg[node];
    ll mid = (leftNode+rightNode)/2;
    seg leftVal = query(left, right, node*2, leftNode, mid);
    seg rightVal = query(left, right, node*2+1, mid+1, rightNode);
    return merge(leftVal, rightVal, leftNode, mid, mid+1, rightNode);
}

int main(){
    fastio;
    int N, M; cin>>N>>M;
    Seg.resize(N*4);
    V.resize(N);
    for(int i=0; i<N; i++){
        cin>>V[i];
        update(i, V[i], 1, 0, N-1);
    }
    while(M--){
        ll q,i,x; cin>>q>>i>>x;
        if(q==1){
            i--;
            if(V[i]>=x){
                V[i] -= x;
                update(i, V[i], 1, 0, N-1);
            }
            else{
                x -= V[i]; V[i] = 0;
                update(i, V[i], 1, 0, N-1);
                int idx = i;
                if(idx==N-1) continue;
                while(true){
                    idx = query(idx+1, N-1, 1, 0, N-1).mxIdx;
                    if(V[idx]==0) break;
                    if(V[idx]>=x){
                        V[idx]-=x;
                        update(idx, V[idx], 1, 0, N-1);
                        break;
                    }
                    else{
                        x -= V[idx]; V[idx] = 0;
                        update(idx, V[i], 1, 0, N-1);
                    }
                    if(idx==N-1) break;
                }
            }   
        }
        if(q==2){
            i--;   
            V[i] += x;
            update(i, V[i], 1, 0, N-1);
        }
        if(q==3){
            i--; x--;
            cout<<query(i, x, 1, 0, N-1).mx<<'\n';
        }
    }
    return 0;
}
