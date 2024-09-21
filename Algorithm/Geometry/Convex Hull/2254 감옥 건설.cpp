//아무 세 점을 잡아도 일직선이 되는 경우가 없다고 했으므로 편안하게 풀 수 있다.
//볼록껍질 내부에 점이 있는지 보려면 CCW로 볼록껍질의 모든 선분에 대해서 그 점의 외적이 한쪽에 있는지 봐주면 된다.
//점의 개수가 3개 미만인 경우를 맨 앞에서 체크해주지 않으면 메모리 초과가 나온다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define pii pair<ll, ll>
#define ll long long
#define x first 
#define y second        

int CCW(pii a, pii b, pii c){
    ll T1 = a.x*b.y + b.x*c.y + c.x*a.y;
    ll T2 = a.y*b.x + b.y*c.x + c.y*a.x;
    if(T1-T2>0) return 1;
    else if(T1-T2==0) return 0;
    else return -1;
}

int N, Px, Py;
vector<pii> V;
int ans = 0;

bool ConvexHull(vector<pii>& A){
    int n = A.size();
    if(n<3) return false; //볼록껍질 자체를 만들 수 없는 경우 (점이 2개 이하임)

    vector<bool> isused(n);
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

    vector<int> res;
    for(int i=0; i<st.size()-1; i++) {res.push_back(st[i]); isused[st[i]]=true;}
    for(int i=0; i<en.size()-1; i++) {res.push_back(en[i]); isused[en[i]]=true;}
    if(res.size()<3) return false; //볼록껍질이 구성되지 않은 경우

    //볼록껍질 내부에 점이 존재하는지 확인
    res.push_back(res[0]);
    int idx = 1;
    while(idx<res.size() && CCW(A[res[idx-1]], A[res[idx]], {Px, Py})<0) idx++;
    if(idx==res.size()) ans++;
    else return false; //존재하지 않으면 중지

    //존재한다면 볼록껍질에 포함되는 점들을 제거함
    vector<pii> ret;
    for(int i=0; i<n; i++){
        if(isused[i]) continue;
        ret.push_back(A[i]);
    }
    A = ret; //점들 집합 갱신
    return true;
}

int main(){
    fastio;
    cin>>N>>Px>>Py;
    V.resize(N);
    for(int i=0; i<N; i++) cin>>V[i].x>>V[i].y;

    while(ConvexHull(V));

    cout<<ans;
    return 0;
}
