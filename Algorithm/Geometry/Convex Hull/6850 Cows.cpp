//4%에서 WA가 났는데 앤드류 알고리즘의 구현 이슈였다.
//29%에서 WA가 났는데, 이는 자료형 변환 이슈같은데 잘은 모르겠다.

//34번의 제출 끝에 원래 짜려던 코드를 작성하고 AC를 받아낼 수 있었다...

#include <bits/stdc++.h>
#define fastio cin.tie(NULL)->sync_with_stdio(false)
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define x first
#define y second

int CCW(pii a, pii b, pii c){
    ll T1 = a.x*b.y + b.x*c.y + c.x*a.y;
    ll T2 = a.y*b.x + b.y*c.x + c.y*a.x;
    if(T1-T2 > 0) return 1;
    else if(T1-T2 == 0) return 0;
    else return -1;
}

vector<pii> ConvexHull(vector<pii> A){
    int n = A.size(), k=0;
    if(n<=2) return A;
    vector<pii> ret(2*n);
    sort(A.begin(), A.end());
    for(int i=0; i<n; i++){
        while(k>=2 && CCW(ret[k-2], ret[k-1], A[i])<=0) k--;
        ret[k++] = A[i];
    }
    for(int i=n-2, t=k+1; i>=0; i--){
        while(k>=t && CCW(ret[k-2], ret[k-1], A[i])<=0) k--;
        ret[k++] = A[i];
    }
    ret.resize(k-1);
    return ret;
}

int main(){
    fastio;
    int N; cin>>N; 
    vector<pii> V(N);
    for(int i=0; i<N; i++) cin>>V[i].x>>V[i].y;
    sort(V.begin(), V.end());

    vector<pii> hulls = ConvexHull(V);

    hulls.push_back(hulls[0]);

    long long total = 0;
    for(int i=0; i<hulls.size()-1; i++){
        total += (hulls[i].x*hulls[i+1].y - hulls[i].y*hulls[i+1].x);
    }
    cout<<total/100;
    return 0;
}
