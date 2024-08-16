//init에서 값들을 배열 번호로 세팅한다.
//merge에서 인덱스에 있는 값이 더 작은 인덱스를 반환하도록 한다.
//구간에서의 최솟값을 찾는 게 아니라 전체의 최솟값의 인덱스를 구하는 것이므로 query가 필요 없다.
//Segtree[1]만 출력해주면 된다.
//merge에서 V를 사용했으므로 update에서도 V[index]를 업데이트해주면서 Segtree[Node]를 반환하도록 해준다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

ll N,M,K;
vector<ll> V;
vector<ll> Segtree;

ll merge(ll left, ll right){ //Min
    if(V[left]==V[right]) return min(left, right);
    return V[left]>V[right]?right:left; //V[left]가 더 크다면 right를, V[right]가 더 크다면 left를 반환
}

ll init(ll node, ll nodeLeft ,ll nodeRight){ //Segtree Init
    if(nodeLeft==nodeRight) return Segtree[node] = nodeLeft;
    ll mid = nodeLeft + (nodeRight-nodeLeft) / 2;
    ll leftVal = init(node*2, nodeLeft, mid);
    ll rightVal = init(node*2 +1, mid+1, nodeRight);
    return Segtree[node] = merge(leftVal, rightVal);
}

ll update(ll index, ll newValue, ll node, ll nodeLeft, ll nodeRight){ //Segtree Update
    if(index<nodeLeft || nodeRight<index) return Segtree[node];
    if(nodeLeft==nodeRight){V[index]=newValue; return Segtree[node];};
    ll mid = nodeLeft + (nodeRight-nodeLeft) / 2;
    ll leftVal = update(index, newValue, node*2, nodeLeft, mid);
    ll rightVal = update(index, newValue, node*2 +1, mid+1, nodeRight);
    return Segtree[node] = merge(leftVal, rightVal);
}

int main(){
    fastio;
    cin>>N;
    V.resize(N+1);
    for(int i=1;i<=N;i++) cin>>V[i];
    Segtree.resize(4*(N+1));
    init(1,1,N);
    cin>>M;
    while(M--){
        ll q; cin>>q; 
        if(q==2){
            cout<<Segtree[1]<<'\n';
        }
        if(q==1){
            ll a,b; cin>>a>>b;
            update(a,b,1,1,N);
        }
    }
    return 0;
}
