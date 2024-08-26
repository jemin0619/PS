//N이 커서 DP로 접근하긴 힘들어보인다.
//무게에 따라 사탕을 분리해서 저장하고, 내림차순으로 정렬한다.
//그 후 각 배열에 누적합을 시켜준다.
//이후 무게가 3인 사탕부터 개수를 늘려가며 담아보며 답을 구한다.
//무게가 5인 사탕에 대해서도 답을 구한다.
//모든 경우에서 당도롤 가장 많이 가져갈 때의 답을 출력한다.

//OutOfBound 고치느라 고생했다...

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int main(){
    fastio;
    ll N, W; cin>>N>>W;
    vector<ll> A, B;
    for(int i=0; i<N; i++){
        int t,s; cin>>t>>s;
        if(t==3) A.push_back(s);
        else B.push_back(s);
    }
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    partial_sum(A.begin(), A.end(), A.begin());
    partial_sum(B.begin(), B.end(), B.begin());

    ll mx = 0;
    for(int i=0; i<A.size(); i++){
        ll ans = A[i];
        ll nw = W - (i+1)*3;
        if(nw<0) break;
        ll idx = nw/5 - 1;
        if(!B.empty() && idx>=0) ans += B[min(idx, (ll)B.size()-1)];
        mx = max(ans, mx);
    }

    for(int i=0; i<B.size(); i++){
        ll ans = B[i];
        ll nw = W - (i+1)*5;
        if(nw<0) break;
        ll idx = nw/3 - 1;
        if(!A.empty() && idx>=0) ans += A[min(idx, (ll)A.size()-1)];
        mx = max(ans, mx);
    }

    cout<<mx;
    return 0;
}
