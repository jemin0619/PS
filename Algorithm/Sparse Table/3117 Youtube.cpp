//합성함수와 쿼리와 거의 같은 문제이다.
//M--로 한 칸 적게 이동해야 제대로 이동할 수 있다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

//M이 이동거리라고 볼 수 있다
//2^30 >= 10억

ll H[33][100003];

int main(){
    fastio;
    ll N, K, M; cin>>N>>K>>M; //학생 수, 동영상 수, 남은 수업
    M--;

    vector<ll> Query(N);
    for(int i=0; i<N; i++) cin>>Query[i];

    for(int i=1; i<=K; i++) cin>>H[0][i];

    for(int i=1; i<30; i++)
        for(int j=1; j<=K; j++)
            H[i][j] = H[i-1][H[i-1][j]];
    
    for(int i=0; i<N; i++){
        ll X = Query[i];
        for(int i=0; i<30; i++){
            if(M&(1<<i)){
                X = H[i][X];
            }
        }
        cout<<X<<' ';
    }
    return 0;
}
