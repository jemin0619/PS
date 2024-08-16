#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int N,a,b; cin>>N>>a>>b;
    vector<int> A(N), B(N);
    vector<pair<int,int>> V;
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<N;i++) cin>>B[i];
    for(int i=0;i<N;i++) V.push_back({A[i]-B[i], i});
    sort(V.begin(), V.end());
    //앞에서부터 b명은 B 그룹, 나머지는 A 그룹에 넣을 수 있다.
    //V에서 앞에 있을수록 B 과목을 상대적으로 잘 본 사람이라는 것이고, 뒤에 있을수록 A 과목을 상대적으로 잘 본 사람이라는 의미.
    int ans = 0;
    for(int i=0;i<N;i++){
        if(i<b) ans += B[V[i].second];
        else ans += A[V[i].second];
    }
    cout<<ans;
    return 0;
}
