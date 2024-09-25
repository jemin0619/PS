//https://m.blog.naver.com/pasdfq/221458566958
//짧은 버전으로 다시 짜보았다.

//pii를 ll ll로 해주지 않으면 WA
//이유는 CCW에서 T1, T2 계산 중 int 범위를 넘길 수 있기 때문

//CCW가 0인 경우도 pop시키기에 한 선분에 여러 꼭짓점이 들어가지 않는다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define pii pair<ll,ll>
#define x first 
#define y second

int CCW(pii a, pii b, pii c){
    ll T1 = a.x*b.y + b.x*c.y + c.x*a.y;
    ll T2 = a.y*b.x + b.y*c.x + c.y*a.x;
    if(T1-T2>0) return 1;
    else if(T1-T2==0) return 0;
    else return -1;
}

ll ConvexHull(vector<pii>V){
    int N = V.size();
    if(N<=2) return -1;

    ll ret = 0;
    sort(V.begin(), V.end());
    vector<pii> U, D;
    for(auto&P : V){
        while(U.size()>=2 && CCW(U[U.size()-2], U[U.size()-1], P)>=0) U.pop_back();
        U.push_back(P);
        while(D.size()>=2 && CCW(D[D.size()-2], D[D.size()-1], P)<=0) D.pop_back();
        D.push_back(P);
    }
    ret = U.size()+D.size()-2;
    return ret;
}

int main(){
    fastio;
    int N; cin>>N;
    vector<pii> V(N);
    for(int i=0; i<N; i++) cin>>V[i].x>>V[i].y;
    cout<<ConvexHull(V);
    return 0;
}
