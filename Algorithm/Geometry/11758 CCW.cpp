//https://www.youtube.com/watch?v=BqqjWGPXNaQ
//https://m.blog.naver.com/PostView.naver?blogId=kks227&logNo=220794097589&referrerCode=0&searchKeyword=ccw
//https://snowfleur.tistory.com/98

//개인적으로 마지막 글이 가장 인상깊다. 
//공식 유도도 마지막 글이 제일 깔끔하다고 느낀다.
//코드는 첫 번째 영상에서 나온 코드이다.

//CCW : 세 점의 위치 관계 파악
//1. CW (음수 반환)
//2. CCW (양수 반환)
//3. Collinear Points (0 반환)

//1번 점과 2번 점을 이었을 때, 3번 점이 존재하는 영역을 기준으로 방향 구별
//외적 : 두 벡터에 동시에 수직인 벡터를 찾는 연산
//두 벡터에 동시에 수직인 벡터는 2개이므로 연산 순서에 따라 방향을 결정한다.
//ex) axb = v1(위쪽),     bxa = v2(아래쪽)

#include <bits/stdc++.h>   
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

struct Point{
    ll x, y;
};

ll CCW(Point a, Point b, Point c){
    ll t1 = a.x*b.y + b.x*c.y + c.x*a.y;
    ll t2 = a.y*b.x + b.y*c.x + c.y*a.x;
    if(t1 - t2 > 0) return 1;
    else if(t1 - t2 == 0) return 0;
    else return -1;
}

int main(){
    fastio;
    Point a,b,c;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
    cout<<CCW(a,b,c);
    return 0;
}
