#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

template <typename T>
struct fenwick2D{
    int Y, X;
    vector<vector<T>> Tree;
    fenwick2D(int Y, int X): Y(Y), X(X) {Tree.resize(Y+1, vector<T>(X+1));}
    void update(int _y, int _x, T val){
        for(int y=_y; y<=Y; y+=y&-y)
            for(int x=_x; x<=X; x+=x&-x)
                Tree[y][x] += val;
    }
    T sum(int _y, int _x){
        if(_y<=0 || _x<=0) return 0;
        T ret = 0;
        for(int y=_y; y; y-=y&-y)
            for(int x=_x; x; x-=x&-x)
                ret += Tree[y][x];
        return ret;
    }
    T query(int y1, int x1, int y2, int x2){
        return sum(y2, x2) - sum(y1-1, x2) - sum(y2, x1-1) + sum(y1-1, x1-1);
    }
};

int main(){
    fastio;
    int N, M; cin>>N>>M;
    fenwick2D<ll> fw(N,N);
    vector<vector<ll>> V(N+1, vector<ll>(N+1));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>V[i][j];
            fw.update(i,j,V[i][j]);
        }
    }
    while(M--){
        int Q; cin>>Q;
        if(Q==0){
            int x,y; ll c;
            cin>>y>>x>>c;
            ll z = c - V[y][x];
            fw.update(y,x,z);
            V[y][x] = c;
        }
        else{
            int y1,x1,y2,x2;
            cin>>y1>>x1>>y2>>x2;
            cout<<fw.query(y1,x1,y2,x2)<<'\n';
        }
    }
    return 0;
}
