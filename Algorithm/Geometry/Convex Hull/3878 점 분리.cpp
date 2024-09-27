//점이 3개가 넘으면 볼록껍질을 구성해본다는 아이디어만 있으면 풀 수 있다.
//혹시나 틀린다면 구현 이슈이다...

//1 1 : 항상 가능
//2 1 : 선분 내에 점이 속하면 불가능
//1 2 : 선분 내에 점이 속하면 불가능
//2 2 : 두 선분이 교차하면 불가능

//3 1 : 볼록껍질 내에 점이 있으면 불가능
//3 2 : 마찬가지
//1 3 : 마찬가지
//2 3 : 마찬가지

//3+ 3+ : 
//어떤 볼록껍질 A의 한 꼭짓점 a가 어떤 볼록껍질 B의 내부(선분 포함)에 존재하거나,
//어떤 볼록껍질 B의 한 꼭짓점 b가 어떤 볼록껍질 A의 내부(선분 포함)에 존재하는 경우 불가능

//10%에 WA가 난다면 볼록껍질의 선분 속에 점이 존재하는 경우를 빼먹은 것이다... 
//볼록껍질을 시계 방향으로 뽑아낸 경우 CCW<=0 으로 해줘야됨

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define pii pair<ll,ll>
#define x first 
#define y second

int CCW(pii A, pii B, pii C){
    ll T1 = A.x*B.y + B.x*C.y + C.x*A.y;
    ll T2 = A.y*B.x + B.y*C.x + C.y*A.x;
    if(T1-T2>0) return 1;
    else if(T1-T2==0) return 0;
    else return -1;
}

bool Intersect(pii a, pii b, pii c, pii d){
    int D1 = CCW(a, b, c) * CCW(a, b, d);
    int D2 = CCW(c, d, a) * CCW(c, d, b);
    if(D1<=0 && D2<=0){
        if(D1==0 && D2==0){
            if(a>=b) swap(a, b);
            if(c>=d) swap(c, d);
            return a<=d && c<=b;
        }
        return true;
    }
    return false;
}

vector<pii> ConvexHull(vector<pii> V){
    int N = V.size();
    if(N<=2) return V;
    vector<pii> st, en;
    sort(V.begin(), V.end());
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

void solve(){
    int N, M; cin>>N>>M;
    if(N==0 && M==0) exit(0);
    vector<pii> A(N), B(M);
    for(int i=0; i<N; i++) cin>>A[i].x>>A[i].y;
    for(int i=0; i<M; i++) cin>>B[i].x>>B[i].y;
    A = ConvexHull(A);
    B = ConvexHull(B);
    N = A.size();
    M = B.size();

    if(N==1 && M==1) {cout<<"YES\n"; return;} //항상 가능
    
    //선분 교차 
    if(N==2 && M==2){
        if(Intersect(A[0], A[1], B[0], B[1])) {cout<<"NO\n"; return;}
        else {cout<<"YES\n"; return;}
    }

    //선분 하나, 점 하나
    if(N==1 && M==2){ //한 점이 선분에 포함된다면 NO
        if(CCW(B[0], B[1], A[0])==0){
            sort(B.begin(), B.end());
            if(B[0].x<=A[0].x && A[0].x<=B[1].x){cout<<"NO\n"; return;}
            else {cout<<"YES\n"; return;}
        }
        else {cout<<"YES\n"; return;}
    }
    if(N==2 && M==1){ //한 점이 선분에 포함된다면 NO
        if(CCW(A[0], A[1], B[0])==0){
            sort(A.begin(), A.end());
            if(A[0].x<=B[0].x && B[0].x<=A[1].x){cout<<"NO\n"; return;}
            else {cout<<"YES\n"; return;}
        }
        else {cout<<"YES\n"; return;}
    }

    //볼록껍질 하나, 점or선분 하나
    if(N>=3 && M<=2){ //볼록다각형 A 내부에 B[0]~B[M-1]이 포함된다면 NO
        A.push_back(A[0]);
        for(auto&P : B){
            int idx = 1;
            while(idx<A.size() && CCW(A[idx-1], A[idx], P)<=0) idx++;
            if(idx==A.size()) {cout<<"NO\n"; return;}
        }
        cout<<"YES\n"; return;
    }
    if(N<=2 && M>=3){ //볼록다각형 B 내부에 A[0]~A[N-1]이 포함된다면 NO
        B.push_back(B[0]);
        for(auto&P : A){
            int idx = 1;
            while(idx<B.size() && CCW(B[idx-1], B[idx], P)<=0) idx++;
            if(idx==B.size()) {cout<<"NO\n"; return;}
        }
        cout<<"YES\n"; return;
    }

    //볼록다각형 두 개가 구성되는 경우
    A.push_back(A[0]); B.push_back(B[0]);
    for(auto&P : A){ //A의 한 꼭짓점 P가 볼록다각형 B에 있으면 바로 NO
        int idx = 1;
        while(idx<B.size() && CCW(B[idx-1], B[idx], P)<=0) idx++;
        if(idx==B.size()) {cout<<"NO\n"; return;}
    }
    for(auto&P : B){ //B의 한 꼭짓점 P가 볼록다각형 A에 있으면 바로 NO
        int idx = 1;
        while(idx<A.size() && CCW(A[idx-1], A[idx], P)<=0) idx++;
        if(idx==A.size()) {cout<<"NO\n"; return;}
    }

    //나머지 경우는 OK
    cout<<"YES\n"; return;
}

int main(){
    fastio;
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}
