//로테이팅 캘리퍼스 연습 문제이다.
//모노톤 체인 + 로테이팅 캘리퍼스 글들을 많이 읽었지만 구현이 다 달라서 GPT한테 물어보았고, 가장 나은 로테이팅 캘리퍼스 구현체를 사용했다.

//컨벡스 헐을 구성한 이후에 꼭짓점 개수를 판단해야 한다.
//구성 이후 꼭짓점이 3개 미만일 수 있기 때문이다. (세 점이 일직선에 있는 경우)

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define ld long double
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

vector<pii> ConvexHull(vector<pii> V){
    int N = V.size();
    if(N<3) return V;
    sort(V.begin(), V.end());
    vector<pii> U, D;
    for(auto&P : V){
        while(U.size()>=2 && CCW(U[U.size()-2], U[U.size()-1], P)>=0) U.pop_back();
        U.push_back(P);
        while(D.size()>=2 && CCW(D[D.size()-2], D[D.size()-1], P)<=0) D.pop_back();
        D.push_back(P);
    }
    vector<pii> ret;
    for(int i=0; i<U.size()-1; i++) ret.push_back(U[i]);
    for(int i=D.size()-1; i>0; i--) ret.push_back(D[i]);
    return ret;
}

ld getDist(pii a, pii b){
    ld T1 = a.x-b.x;
    ld T2 = a.y-b.y;
    T1 *= T1; T2 *= T2;
    return (ld)sqrt(T1+T2);
}

//모든 i에 대해, V[i]와 V[idx]가 가장 멀어지는 지점까지 idx 이동
//O(N^2)로 보일 수 있으나, 투 포인터 기법으로 O(N)에 동작한다
ld Rotating_Calipers(vector<pii> V){
    int N = V.size();
    if(N < 3) return -1;
    ld ret = 0;
    int idx = 1;
    for(int i=0; i<N; i++){
        while(true){
            int nidx = (idx+1)%N;
            ld D1 = getDist(V[i], V[idx]);
            ld D2 = getDist(V[i], V[nidx]);
            if(D2 > D1) idx = nidx;
            else break;
        }
        ret = max(ret, getDist(V[i], V[idx]));
    }
    return ret;
}

void solve(){
    int N; cin>>N;
    vector<pii> V(N);
    for(int i=0; i<N; i++) cin>>V[i].x>>V[i].y;
    V = ConvexHull(V);
    if(V.size()<3) {cout<<getDist(V[0], V[1])<<'\n'; return;}
    cout<<Rotating_Calipers(V)<<'\n';
    return;
}

int main(){
    fastio;
    cout<<fixed; 
    cout.precision(20);
    int tc =1;
    while(tc--){
        solve();
    }
    return 0;
}
