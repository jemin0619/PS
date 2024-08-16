//펜윅 트리로 Lazy Propagation 없이 구간 업데이트, 점 쿼리를 할 수 있다.
//구간 업데이트, 구간 쿼리를 하려면 펜윅트리 두 개를 사용해야 한다.
//코드에서 주의할 점은 점 쿼리만을 위해 짜진 코드이므로 단일 업데이트에도 다음 인덱스에 -값 처리를 해줘야 한다.
//imos법이 정말 많이 쓰이는 것 같다.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio cin.tie(NULL)->sync_with_stdio(false)

template <typename T>
struct fenwick{
    int n;
    vector<T> Tree;
    fenwick(int n):n(n){Tree.resize(n+1);}
    void update(int i, T val){
        for(;i<=n;i+=i&-i) Tree[i] += val;
    }
    T sum(int i){
        T ret = 0;
        for(;i;i-=i&-i) ret += Tree[i];
        return ret;
    }
};

int main(){
    fastio;
    int N; cin>>N;
    vector<ll> V(N+1);
    fenwick<ll> fw(N);
    for(int i=1;i<=N;i++){
        cin>>V[i];
        fw.update(i, V[i]);
        fw.update(i+1, -V[i]);
    }
    int M; cin>>M;
    while(M--){
        int Q; cin>>Q;
        if(Q==1){
            int i,j; ll k;
            cin>>i>>j>>k;
            fw.update(i, k);
            fw.update(j+1,-k);
        }
        else{
            int i; cin>>i;
            cout<<fw.sum(i)<<'\n';
        }
    }
    return 0;
}
