//빠르게 증명하지 못하겠어서 O(N!) 시뮬레이션 돌리고 규칙성 찾음

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

void solve(){
    int N; cin>>N;
    if(N==1) {cout<<"1"; return;}
    vector<int> ans(N);
    int a=1, b=N;
    bool flag = false;
    if(N%2==0) flag = true;
    for(int i=N-1; i>=0; i--){
        if(flag) ans[i] = a++;
        else ans[i] = b--;
        flag = !flag;
    }
    for(int i=0; i<N; i++) cout<<ans[i]<<' ';
}

void debug(){ //규칙 찾기
    int N; cin>>N;
    vector<ll> V;
    for(int i=1; i<=N; i++) V.push_back(i);
    vector<pair<ll, vector<ll>>> answer;
    do{
        ll ans = 1;
        bool flag = false;
        for(int i=0; i<N; i++){
            if(!flag) ans*=V[i];
            else ans+=V[i];
            flag = !flag;
        }
        answer.push_back({ans, V});
    }while(next_permutation(V.begin(), V.end()));
    sort(answer.rbegin(), answer.rend());
    for(int i=0; i<2; i++){
        for(ll val : answer[i].second) cout<<val<<' ';
        cout<<"ans = "<<answer[i].first<<'\n';
    }
}

int main(){
    fastio;
    solve();
    return 0;
}
