#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

ll N,M,K;
vector<ll> V;
vector<ll> Segtree;

ll merge(ll left, ll right){ //Sum
    return left + right;
}

ll init(ll node, ll nodeLeft ,ll nodeRight){ //Segtree Init
    if(nodeLeft==nodeRight) return Segtree[node] = V[nodeLeft];
    ll mid = nodeLeft + (nodeRight-nodeLeft) / 2;
    ll leftVal = init(node*2, nodeLeft, mid);
    ll rightVal = init(node*2 +1, mid+1, nodeRight);
    return Segtree[node] = merge(leftVal, rightVal);
}

ll query(ll left, ll right, ll node, ll nodeLeft, ll nodeRight){ //Segtree Query
    if(right<nodeLeft || nodeRight<left) return 0; //return default value
    if(left<=nodeLeft && nodeRight<=right) return Segtree[node];
    ll mid = nodeLeft + (nodeRight-nodeLeft) / 2;
    ll leftVal = query(left, right, node*2, nodeLeft, mid);
    ll rightVal = query(left, right, node*2 +1, mid+1, nodeRight);
    return merge(leftVal, rightVal);
}

ll update(ll index, ll newValue, ll node, ll nodeLeft, ll nodeRight){ //Segtree Update
    if(index<nodeLeft || nodeRight<index) return Segtree[node];
    if(nodeLeft==nodeRight) return Segtree[node]=newValue;
    ll mid = nodeLeft + (nodeRight-nodeLeft) / 2;
    ll leftVal = update(index, newValue, node*2, nodeLeft, mid);
    ll rightVal = update(index, newValue, node*2 +1, mid+1, nodeRight);
    return Segtree[node] = merge(leftVal, rightVal);
}

int main(){
    fastio;
    cin>>N>>M>>K; M+=K;
    V.resize(N+1);
    for(int i=1;i<=N;i++) cin>>V[i];
    Segtree.resize(4*(N+1));
    init(1,1,N);
    while(M--){
        ll a,b,c; cin>>a>>b>>c;
        if(a==1){ //update (b->c)
            update(b,c,1,1,N);
        }
        if(a==2){ //query (sum(b~c))
            cout<<query(b,c,1,1,N)<<'\n';
        }
    }
    return 0;
}
