//튜플로 처리해야하는게 귀찮았다.
//Cows와 크게 다를게 없었다.
//선분 내부에 있는 점도 쓰인 것으로 취급하는 문제는 왜 없는지 모르겠다.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define tiii tuple<ll,ll,ll>
#define x first 
#define y second
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int CCW(tiii a, tiii b, tiii c){
    auto[ax,ay,aw] = a;
    auto[bx,by,bw] = b;
    auto[cx,cy,cw] = c;
    ll T = ax*by + bx*cy + cx*ay - ay*bx - by*cx - cy*ax;
    if(T>0) return 1;
    else if(T==0) return 0;
    else return -1;
}

vector<int> ans;

bool ConvexHull(vector<tiii>&A, int cnt){
    int n = A.size();
    if(n<3) return false;
    sort(A.begin(), A.end());
    vector<int> st, en;
    st.push_back(0); st.push_back(1);
    for(int i=2; i<n;){
        if(CCW(A[st[st.size()-2]], A[st[st.size()-1]], A[i])<0) st.push_back(i++);
        else{
            st.pop_back();
            if(st.size()==1) st.push_back(i++);
        }
    }
    en.push_back(n-1); en.push_back(n-2);
    for(int i=n-3; i>=0;){
        if(CCW(A[en[en.size()-2]], A[en[en.size()-1]], A[i])<0) en.push_back(i--);
        else{
            en.pop_back();
            if(en.size()==1) en.push_back(i--);
        }
    }
    vector<int> res;
    for(int i=0; i<st.size()-1; i++) res.push_back(st[i]);
    for(int i=0; i<en.size()-1; i++) res.push_back(en[i]);
    if(res.size()<3) return false;

    for(int val : res){
        auto[x,y,w] = A[val];
        ans[w] = cnt;
        //cout<<w<<' ';
    }//cout<<'\n';

    vector<tiii> temp;
    for(auto[x,y,w] : A){
        if(ans[w]==0) temp.push_back({x,y,w});
    }
    A = temp;

    return true;
}

int main(){
    fastio;
    int N; cin>>N;
    vector<tiii> V(N);
    ans.resize(N, 0);
    for(int i=0; i<N; i++){
        int x,y; cin>>x>>y;
        V[i] = {x,y,i};
    }
    int cnt = 1;
    while(ConvexHull(V, cnt++));
    for(int val : ans) cout<<val<<' ';
    return 0;
}
