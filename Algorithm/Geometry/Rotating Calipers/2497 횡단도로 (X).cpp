//예제와 답이 달라서 혹시 했는데, 스페셜 져지라 상관없었다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define pii pair<ll,ll>
#define ld long double
#define x first 
#define y second

pii A, B;

ld getDist(pii a, pii b){
    ld T1 = a.x-b.x;
    ld T2 = a.y-b.y;
    T1 *= T1; T2 *= T2;
    return (ld)sqrt(T1+T2);
}

ld Rotating_Calipers(vector<pii> V){
    int N = V.size();
    if(N<3) return -1;
    ld ret = -1;
    int idx = 1;
    for(int i=0; i<N; i++){
        while(true){
            int nidx = (idx+1)%N;
            ld D1 = getDist(V[i], V[idx]);
            ld D2 = getDist(V[i], V[nidx]);
            if(D2>D1) idx = nidx;
            else break;
        }
        if(ret < getDist(V[i], V[idx])){
            ret = getDist(V[i], V[idx]);
            A = V[i];
            B = V[idx];
        }
    }
    return ret;
}

int main(){
    fastio;
    int N; cin>>N;
    vector<pii> V(N);
    for(int i=0; i<N; i++) cin>>V[i].x>>V[i].y;
    Rotating_Calipers(V);
    cout<<A.x<<' '<<A.y<<' '<<B.x<<' '<<B.y;
    return 0;
}
