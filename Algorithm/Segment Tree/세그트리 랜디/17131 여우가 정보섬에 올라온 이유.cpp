//한 점의 좌표를 X, Y라고 할 때, 그 V자 중 가장 밑의 점으로 해서 만들 수 있는 V자의 개수는 다음과 같다.
// st~X-1의 구간합 * X+1~en의 구간합 (단 y좌표는 Y보다 커야됨)
//이렇게 하단의 점만 고정시켜야 고를 수 있는 부분이 두 개로 나뉘어서 문제를 해결할 수 있다.

//좌표압축을 하면 안되고, 입력의 범위가 작아서 모든 좌표를 양의 정수로 올려서 계산했다.
//북서풍 문제를 풀면서 배운, 정렬을 통해 1차원 세그먼트 트리로 2차원 구간합을 처리하는 테크닉을 사용했다.

//매번 문제를 풀때마다 한 번에 모아서 처리할 게 있으면 큐에 넣어서 해결하는데, 다른 좋은 방법이 있는지 모르겠다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define pii pair<ll,ll>
#define ff first 
#define ss second
const ll SZ = 404040;
const ll MOD = 1e9 + 7;

ll N;
vector<ll> Seg(SZ*4);

//양의 정수가 아닌 좌표를 양의 정수로 변환
ll getPos(ll x){
    return 200001 + x;
}

ll update(int idx, ll val, int node, int leftNode, int rightNode){
    if(idx<leftNode || rightNode<idx) return Seg[node];
    if(leftNode==rightNode) return Seg[node]+=val;
    ll mid = leftNode+rightNode; mid/=2;
    ll leftVal = update(idx, val, node*2, leftNode, mid);
    ll rightval = update(idx, val, node*2+1, mid+1, rightNode);
    return Seg[node] = leftVal + rightval;
}

ll query(int left, int right, int node, int leftNode, int rightNode){
    if(rightNode<left || right<leftNode) return 0;
    if(left<=leftNode && rightNode<=right) return Seg[node];
    ll mid = leftNode+rightNode; mid/=2;
    ll leftVal = query(left, right, node*2, leftNode, mid);
    ll rightval = query(left, right, node*2+1, mid+1, rightNode);
    return leftVal + rightval;
}

int main(){
    fastio;
    cin>>N;
    //Y좌표가 크고, X좌표가 작은 순으로 정렬하고, 같은 Y좌표끼리는 세그먼트 트리에 한번에 업데이트 해주기 (X좌표는 굳이 정렬 안해도 됨)
    //V자에서 가장 하단의 꼭짓점을 기준으로 스위핑하기에 Y좌표 업데이트는 한 Y줄을 다 본 다음에 해준다.

    vector<pii> V(N); //y,x로 저장
    for(int i=0; i<N; i++){
        ll y, x; cin>>x>>y;
        V[i] = {getPos(y), getPos(x)};
    }
    sort(V.begin(), V.end(), greater<pii>());

    ll Ans = 0;
    queue<ll> Q;
    for(int i=0; i<N; i++){
        auto&[curY, curX] = V[i];
        Ans += (query(1, curX-1, 1, 1, SZ)%MOD * query(curX+1, SZ, 1, 1, SZ)%MOD)%MOD;
        Ans %= MOD;
        if(i+1<N){
            if(V[i+1].ff==curY) Q.push(curX);
            else{
                Q.push(curX);
                while(!Q.empty()){
                    int x = Q.front(); Q.pop();
                    update(x, 1, 1, 1, SZ);
                }
            }
        }
    }
    cout<<Ans;
    return 0;
}
