#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio cin.tie(NULL)->sync_with_stdio(false)

#pragma region CCW&Cross
struct Point{
    int x,y;
    bool operator <= (Point const & P){
        if(P.x==x) return y <= P.y;
        return x <= P.x;
    }
};

struct Line{
    Point p1, p2;
};

int CCW(Point a, Point b, Point c){
    ll T1 = a.x*b.y + b.x*c.y + c.x*a.y;
    ll T2 = a.y*b.x + b.y*c.x + c.y*a.x;
    if(T1-T2>0) return 1;
    else if(T1-T2==0) return 0;
    else return -1;
}

bool cross(Line a, Line b){
    int D1 = CCW(a.p1, a.p2, b.p1) * CCW(a.p1, a.p2, b.p2);
    int D2 = CCW(b.p1, b.p2, a.p1) * CCW(b.p1, b.p2, a.p2);
    if(D1<=0 && D2<=0){
        if(D1==0 && D2==0){
            if(a.p2 <= a.p1) swap(a.p1, a.p2);
            if(b.p2 <= b.p1) swap(b.p1, b.p2);
            return a.p1<=b.p2 && b.p1<=a.p2;
        }
        return true;
    }
    return false;
}
#pragma endregion

#pragma region Union&Find
vector<int> parent;
vector<int> sz;
int find(int u){ 
    if(u==parent[u]) return u;
    return parent[u] = find(parent[u]);
}
void merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u==v) return;
    if(u>v) swap(u,v);
    parent[v] = u;
    sz[u] += sz[v];
    sz[v] = 0;
}
#pragma endregion

int N;

int main(){
    fastio;
    cin>>N;
    vector<Line> V(N);
    parent.resize(N);
    sz.resize(N, 1);
    iota(parent.begin(), parent.end(), 0);
    for(int i=0; i<N; i++) cin>>V[i].p1.x>>V[i].p1.y>>V[i].p2.x>>V[i].p2.y;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(cross(V[i], V[j])) merge(i, j);
        }
    }

    int cnt = 0;
    int mx = -1;
    for(int i=0; i<N; i++){
        if(sz[i]==0) continue;
        cnt++;
        mx = max(mx, sz[i]);
    }   
    cout<<cnt<<'\n'<<mx;
    return 0;
}
