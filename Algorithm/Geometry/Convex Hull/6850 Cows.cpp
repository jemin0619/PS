//4%에서 WA가 났는데 앤드류 알고리즘의 구현 이슈였다.
//29%에서 WA가 났는데, 이는 자료형 변환 이슈같은데 잘은 모르겠다.

//34번의 제출 끝에 원래 짜려던 코드를 작성하고 AC를 받아낼 수 있었다...

#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define pii pair<ll,ll>
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define x first
#define y second 

int CCW(pii a, pii b, pii c){
    ll T1 = a.x*b.y + b.x*c.y + c.x*a.y;
    ll T2 = a.y*b.x + b.y*c.x + c.y*a.x;
    if(T1-T2>0) return 1;
    else if(T1-T2==0) return 0;
    else return -1;
}

int N;
vector<pii> V;

vector<int> ConvexHull(){
    vector<int> st, en;
    st.push_back(0); st.push_back(1);
    for(int i=2; i<N;){
        if(CCW(V[st[st.size()-2]], V[st[st.size()-1]], V[i]) < 0) st.push_back(i++);
        else{
            st.pop_back();
            if(st.size()==1) st.push_back(i++);
        }
    }
    en.push_back(N-1); en.push_back(N-2);
    for(int i=N-3; i>=0;){
        if(CCW(V[en[en.size()-2]], V[en[en.size()-1]], V[i]) < 0) en.push_back(i--);
        else{
            en.pop_back();
            if(en.size()==1) en.push_back(i--);
        }
    }

    vector<int> ret(st);
    for(int i=1; i<en.size()-1; i++){
        ret.push_back(en[i]);
    }
    return ret;
}

int main(){
    fastio;
    cin>>N; V.resize(N);
    for(int i=0; i<N; i++) cin>>V[i].x>>V[i].y;
    sort(V.begin(), V.end());

    vector<int> hulls = ConvexHull();

    hulls.push_back(hulls[0]);

    ld sum1=0, sum2=0;
    for(int i=0; i<hulls.size()-1; i++){
        sum1 += (V[hulls[i]].x*V[hulls[i+1]].y);
        sum2 += (V[hulls[i]].y*V[hulls[i+1]].x);
    }
    ld area = abs((sum1-sum2))/2;
    ll ans = area/50;
    cout<<ans;
    return 0;
}
