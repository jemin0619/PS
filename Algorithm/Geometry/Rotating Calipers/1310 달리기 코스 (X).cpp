//BOJ 2049 가장 먼 두 점 코드로 풀린다.
//다른 점은 이번엔 한 좌표엔 한 점만 있다는 것이다.

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

ll getDist(pii a, pii b){
    ll T1 = a.x-b.x;
    ll T2 = a.y-b.y;
    T1 *= T1; T2 *= T2;
    return T1 + T2;
}

vector<pii> ConvexHull(vector<pii> V){
    int N = V.size();
    if(N<3) return V;
    sort(V.begin(), V.end());
    vector<pii> st, en;
    for(auto&P : V){
        while(st.size()>=2 && CCW(st[st.size()-2], st[st.size()-1], P)>=0) st.pop_back();
        st.push_back(P);
        while(en.size()>=2 && CCW(en[en.size()-2], en[en.size()-1], P)<=0) en.pop_back();
        en.push_back(P);
    }
    vector<pii> ret;
    for(int i=0; i<st.size()-1; i++) ret.push_back(st[i]);
    for(int i=en.size()-1; i>0; i--) ret.push_back(en[i]);
    return ret;
}

ll Rotating_Calipers(vector<pii> V){
    int N = V.size();
    if(N<3) return -1;
    ll ret = 0;
    int idx = 1;
    for(int i=0; i<N; i++){
        while(true){
            int nidx = (idx+1)%N;
            ll D1 = getDist(V[i], V[idx]);
            ll D2 = getDist(V[i], V[nidx]);
            if(D2>D1) idx = nidx;
            else break;
        }
        ret = max(ret, getDist(V[i], V[idx]));
    }
    return ret;
}

int main(){
    fastio;
    int N; cin>>N;
    vector<pii> V(N);
    for(int i=0; i<N; i++) cin>>V[i].x>>V[i].y;
    V = ConvexHull(V);
    if(V.size()<3){
        cout<<getDist(V[0], V[1]);
        return 0;
    }
    cout<<Rotating_Calipers(V);
    return 0;
}
