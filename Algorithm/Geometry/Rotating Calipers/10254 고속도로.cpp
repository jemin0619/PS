//이전까지 사용했던 로테이팅 캘리퍼스 구현체가 잘못되었었다.
//기준점에서 다른 두 점간 거리를 비교해서 이동하다가 거리가 줄면 멈추는 식이었는데, 이런 구현에 반례가 있었다.
//삼분탐색에서의 반례 https://blog.naver.com/rdd573/221652112578
//다른 문제들의 TC가 너무 약했던 것 같다. (좌표 제한이 작았음)

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

ll getDist2(pii a, pii b){
    ll T1 = a.x-b.x;
    ll T2 = a.y-b.y;
    return T1*T1 + T2*T2;
}

vector<pii> ConvexHull(vector<pii> V){
    int N = V.size();
    sort(V.begin(), V.end());
    vector<pii> up, down;
    for(auto&P : V){
        while(up.size()>=2 && CCW(up[up.size()-2], up[up.size()-1], P)>=0) up.pop_back();
        up.push_back(P);
        while(down.size()>=2 && CCW(down[down.size()-2], down[down.size()-1], P)<=0) down.pop_back();
        down.push_back(P);
    }

    vector<pii> ret;
    for(int i=0; i<up.size()-1; i++) ret.push_back(up[i]);
    for(int i=down.size()-1; i>0; i--) ret.push_back(down[i]);

    pii A, B;
    ll maxDist = -0;
	for(int i=0, j=(int)down.size()-1; i+1<up.size() || j>0;){
        ll ND = getDist2(up[i], down[j]);
        if(maxDist<ND){
            maxDist = ND;
            A = up[i];
            B = down[j];
        }

		ll upX = up[i+1].x - up[i].x;
		ll upY = up[i+1].y - up[i].y;
		ll downX = down[j].x - down[j-1].x;
		ll downY = down[j].y - down[j-1].y;

		if(i+1 == up.size()) --j;
		else if(j == 0) ++i;
		else if(upY * downX > downY * upX) ++i;
		else --j;
	}
    
    if(ret.size()>=3) cout<<A.x<<' '<<A.y<<' '<<B.x<<' '<<B.y<<'\n';

    return ret;
}



void solve(){
    int N; cin>>N;
    vector<pii> V(N);
    for(int i=0; i<N; i++) cin>>V[i].x>>V[i].y;
    V = ConvexHull(V);
    if(V.size()<3) cout<<V[0].x<<' '<<V[0].y<<' '<<V[1].x<<' '<<V[1].y<<'\n';
}

int main(){
    fastio;
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}
