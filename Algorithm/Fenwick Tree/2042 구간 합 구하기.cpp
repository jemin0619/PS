#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio cin.tie(NULL)->sync_with_stdio(false)

template <typename T>
struct fenwick{
    int N;
    vector<T> Tree;
    fenwick(int N):N(N){Tree.resize(N+1);}
    void update(int i, T x){
        for(;i<N;i+=i&-i) Tree[i] += x;
    }
    T sum(int i){
        T ret = 0;
        for(;i;i-=i&-i) ret += Tree[i];
        return ret;
    }
};

int main(){
    fastio;
    int N, M, K; cin>>N>>M>>K;
    M += K;
    vector<ll> V(N+1);
    fenwick<ll> fw(N+1);
    for(int i=1;i<=N;i++){
        cin>>V[i];
        fw.update(i, V[i]);
    }
    while(M--){
        //b값이 ll이 아니면 2%에서 WA를 받는다.
        ll q,a,b; cin>>q>>a>>b;
        if(q==1){
            ll z = b - V[a];
            fw.update(a, z);
            V[a] = b;
        }
        if(q==2){
            cout<<fw.sum(b)-fw.sum(a-1)<<'\n';
        }
    }
    return 0;
}
