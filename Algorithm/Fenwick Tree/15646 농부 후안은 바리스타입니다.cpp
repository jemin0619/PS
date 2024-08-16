//imos법 + 2D 펜윅
//(y2+1, x2+1)에 -d를 넣어서 틀렸었는데, 생각해보니 -d가 두 번 적용되는 구간이므로 +d를 해서 한 번만 적용되게 해주는게 맞았다.
//펜윅 구현이 틀린건지, N,M 크기를 반대로 한건지, imos법을 잘못 적용한건지 뭐가 문제인건지 햇갈려서 디버깅이 힘들었다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

template <typename T>
struct fenwick2D{
    int N,M;
    vector<vector<T>> Tree;
    fenwick2D(int N, int M):N(N),M(M){Tree.resize(N+1, vector<T>(M+1));}
    void update(int _y, int _x, T val){
        for(int y=_y; y<=N; y+=y&-y)
            for(int x=_x; x<=M; x+=x&-x)
                Tree[y][x] += val;
    }
    T sum(int _y, int _x){
        T ret = 0;
        for(int y=_y; y; y-=y&-y)
            for(int x=_x; x; x-=x&-x)
                ret += Tree[y][x];
        return ret;
    }
};

int main(){
    fastio;
    int N, M, K; cin>>N>>M>>K;
    fenwick2D<ll> fw(N, M);
    while(K--){
        int Q; cin>>Q;
        if(Q==1){
            int x1, x2, y1, y2; ll d;
            cin>>y1>>x1>>y2>>x2>>d;
            fw.update(y1, x1, d);
            fw.update(y1, x2+1, -d);
            fw.update(y2+1, x1, -d);
            fw.update(y2+1, x2+1, d);
        }else{
            int x, y;
            cin>>y>>x;
            cout<<fw.sum(y, x)<<'\n';
        }
    }
    return 0;
}
