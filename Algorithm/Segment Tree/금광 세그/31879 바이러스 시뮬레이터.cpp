//처음 이 문제를 볼 땐 금광세그를 몰랐었다.
//2일정도 고민하다가 세그에 left, right, mid가 있으면 되지 않을까 하는 생각을 했는데, 그러다가 예외처리를 못하겠어서 잠시 접어두었다.
//최근에 금광세그를 배우고 생각이 나서 도전했다.

//2849 탭댄스처럼 구간 길이를 저장해서 해당 부분이 노드 전체를 말하는 것인지 확인해주었다.
//merge 함수를 짜는 과정이 쉽지 않았다.
//탭댄스를 풀지 않았더라면 시도도 못했을 것이다...

//한 번 RTE를 받았는데, 바로 예외 Case를 찾아 수정했다.
//1번 쿼리에서 left>right인 경우를 처리하지 않아서 생긴 듯 하다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

struct seg{
    ll mxIdx, mxVal; //Range Maximum Query
    ll left, right, mx; //금광 세그 기본
    ll llen, rlen; //llen: left를 시작으로 0이 나오기까지의 길이 / rlen: right를 시작으로 0이 나오기까지의 길이
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
                if(idx==N-1) continue; //이게 없으면 RTE
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
