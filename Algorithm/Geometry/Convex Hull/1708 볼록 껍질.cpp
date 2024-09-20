//볼록 껍질을 O(NlogN)에 구하는 알고리즘은 그라함 스캔과 모노톤 체인이 있다.
//모노톤 체인으로 풀어보았다. (정렬 구현이 쉬움)

//여러 블로그의 모노톤 체인 구현을 합쳐서 짜서, 구현이 좀 다를 수 있다.
//CCW에서 매번 -1인 경우에만 바로바로 간선을 이은 이유는 Clock Wise에만 볼록 다각형이 만들어지기 때문이다.
//위쪽 아래쪽 모두 Clock Wise에서만 볼록 껍질이 구성되게 하기 위해 CCW 함수의 인수로 주는 값들의 순서를 바꿔주었다.

//코드를 작성하면서 이게 왜 되는지 궁금했던 부분은 CCW가 0일때의 처리였다.
//그중에서도 정사각형의 경우, 한 선분에 여러 점들이 있을 때 이 코드가 왜 제대로 처리하는지 궁금했다.

//CCW가 0이 나온 경우를 생각해보자. 
//그러면 else로 들어갈 것이고, pop_back이 이루어지면서 마지막 꼭짓점이 제거된다.
//꼭짓점이 하나 남았다면 최소 두 개의 꼭짓점이 벡터에 있어야 하므로 넣어주고 i++.
//아니라면 i를 그대로 두고 넘어간다.
//다음 단계의 for문에서 검사가 이루어지고, 이때 i가 추가된다. (CCW가 0이 되지 않음)
//그렇게 한 선분에 여러 꼭짓점이 있는 경우가 제대로 처리된다.

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

int main(){
    fastio;
    int N; cin>>N;
    vector<pii> V(N);
    vector<ll> st, en;

    for(int i=0; i<N; i++) cin>>V[i].x>>V[i].y;
    sort(V.begin(), V.end());

    //위쪽 Convex Hull 구성
    st.push_back(0); st.push_back(1);
    for(int i=2; i<N;){
        if(CCW(V[st[st.size()-2]], V[st[st.size()-1]], V[i]) < 0) st.push_back(i++);
        else{
            st.pop_back();
            if(st.size()==1) st.push_back(i++);
        }
    }

    //아래쪽 Convex Hull 구성
    en.push_back(N-1); en.push_back(N-2);
    for(int i=N-3; i>=0;){
        if(CCW(V[en[en.size()-2]], V[en[en.size()-1]], V[i]) < 0) en.push_back(i--);
        else{
            en.pop_back();
            if(en.size()==1) en.push_back(i--);
        }
    }

    cout<<st.size()+en.size()-2LL;
    return 0;
}
