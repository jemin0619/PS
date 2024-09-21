//기하는 사소한 오차로 WA가 나기 때문에 주의해야 한다.
//이것 때문에 머리아프고 힘들다...
//2%에서 WA가 발생했다면 반올림 이슈이다. 
//printf로 출력하던가, 이 코드처럼 floor(ans+0.5)로 반올림 처리를 해줄 수 있다.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define x first 
#define y second

int CCW(pii a, pii b, pii c){
    ll T = a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
    if(T>0) return 1;
    else if(T==0) return 0;
    else return -1;
}

vector<pii> ConvexHull(vector<pii> A){
    ll n = A.size();
    sort(A.begin(), A.end());

    vector<int> st, en;
    st.push_back(0); st.push_back(1);
    for(int i=2; i<n;){
        if(CCW(A[st[st.size()-2]], A[st[st.size()-1]], A[i]) < 0) st.push_back(i++);
        else{
            st.pop_back();
            if(st.size()==1) st.push_back(i++);
        }
    }

    en.push_back(n-1); en.push_back(n-2);
    for(int i=n-3; i>=0;){
        if(CCW(A[en[en.size()-2]], A[en[en.size()-1]], A[i]) < 0) en.push_back(i--);
        else{
            en.pop_back();
            if(en.size()==1) en.push_back(i--);
        }
    }

    vector<pii> ret;
    for(int i=0; i<st.size()-1; i++) ret.push_back(A[st[i]]);
    for(int i=0; i<en.size()-1; i++) ret.push_back(A[en[i]]);
    return ret;
}

double dist(pii a, pii b){
    double dx = (a.x-b.x) * (a.x-b.x);
    double dy = (a.y-b.y) * (a.y-b.y);
    double ret = sqrt(dx + dy);
    return ret;
}

int main(){
    ll N,L; cin>>N>>L;
    vector<pii> V(N);
    for(int i=0; i<N; i++) cin>>V[i].x>>V[i].y;

    vector<pii> hull = ConvexHull(V);
    hull.push_back(hull[0]);

    double ans = 0;
    for(int i=1; i<hull.size(); i++){
        ans += dist(hull[i-1], hull[i]);
    }
    ans += 2*3.1415926535*L;
    ans = floor(ans+0.5);
    cout<<(ll)ans;
    return 0;
}
