//누적합
//좌표압축 안해도 돌아갈것 같은데 안전하게 하는게 좋음

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int N; cin>>N;
    vector<int> X(N), Y(N);
    for(int i=0; i<N; i++) cin>>X[i]>>Y[i];
    
    //좌표압축
    vector<int> cmpX(X), cmpY(Y);
    sort(cmpX.begin(), cmpX.end());
    sort(cmpY.begin(), cmpY.end());
    cmpX.erase(unique(cmpX.begin(), cmpX.end()), cmpX.end());
    cmpY.erase(unique(cmpY.begin(), cmpY.end()), cmpY.end());
    for(int&val : X) val = lower_bound(cmpX.begin(), cmpX.end(), val) - cmpX.begin();
    for(int&val : Y) val = lower_bound(cmpY.begin(), cmpY.end(), val) - cmpY.begin();
    
    //카운트
    vector<int> Ysum(N+3, 0), Xsum(N+3, 0);
    for(int i=0; i<N; i++){
        Xsum[X[i]]++;
        Ysum[Y[i]]++;
    }
    
    int ans = 0;
    for(int val : Ysum){
        if(val>=2) ans++;
    }
    
    for(int val: Xsum){
        if(val>=2) ans++;
    }
    cout<<ans;
    return 0;
}
