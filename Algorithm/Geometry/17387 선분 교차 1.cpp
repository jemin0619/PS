//세 점이 일직선 위에 있는 경우가 없다고 했으므로 CCW가 0이 되는 경우는 고려하지 않아도 된다.
//코드는 선분 교차 2까지 풀 수 있게 작성했다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

struct Point{
    ll x,y;
    bool operator <= (Point const &P) {
        if(x == P.x) return y <= P.y;
        return x <= P.x;
    }
};

struct Line{
    Point P1, P2;
};

int CCW(Point a, Point b, Point c){
    ll T1 = a.x*b.y + b.x*c.y + c.x*a.y;
    ll T2 = a.y*b.x + b.y*c.x + c.y*a.x;
    if(T1-T2>0) return 1;
    else if(T1-T2==0) return 0;
    else return -1;
}

bool cross(Line L1, Line L2){
    int D1 = CCW(L1.P1, L1.P2, L2.P1) * CCW(L1.P1, L1.P2, L2.P2);
    int D2 = CCW(L2.P1, L2.P2, L1.P1) * CCW(L2.P1, L2.P2, L1.P2);
    if(D1<=0 && D2<=0){
        if(D1==0 && D2==0){
            if(L1.P2 <= L1.P1) swap(L1.P1, L1.P2);
            if(L2.P2 <= L2.P1) swap(L2.P1, L2.P2);
            return L1.P1<=L2.P2 && L2.P1<=L1.P2;
        }
        return true;
    }
    return false;
}

int main(){
    fastio;
    Line A, B;
    cin>>A.P1.x>>A.P1.y>>A.P2.x>>A.P2.y;
    cin>>B.P1.x>>B.P1.y>>B.P2.x>>B.P2.y;
    cout<<cross(A, B);
    return 0;
}
