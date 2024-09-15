//순열 사이클 분할 풀이가 시간복잡도 차원에서 훨씬 낫지만 Sparse Table로도 충분히 돌아간다.
//2.5초라 시간제한이 빡빡했으면 TLE를 받았을 것이다.
//Sparse Table을 H[N][bit]로 채우면 캐시 적중률에서 손해가 생겨 TLE가 난다고 한다.
//순싸분 풀이가 더 쉬웠을 것 같긴 하다. (풀면서 굳이 K번 이동할 필요가 없다는 생각을 하긴 함) 

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

ll N, K;
ll H[50][1000'003];
vector<ll> S; //k번 섞은 후 카드 배열
vector<ll> D; //i -> D[i]로 간선 생성
vector<ll> ans;

int main(){
    fastio;
    cin>>N>>K;
    S.resize(N+1);
    D.resize(N+1);
    ans.resize(N+1);
    for(int i=1; i<=N; i++) cin>>S[i];
    for(int i=1; i<=N; i++){
        cin>>D[i];
        H[0][i] = D[i];
    }
    for(int i=1; i<50; i++)
        for(int j=1; j<=N; j++)
            H[i][j] = H[i-1][H[i-1][j]];

    for(int i=1; i<=N; i++){
        ll idx = i;
        for(int bit=0; bit<50; bit++){
            if(K&(1LL<<bit)){
                idx = H[bit][idx];
            }
        }
        ans[idx] = S[i];
    }
    for(int i=1; i<=N; i++) cout<<ans[i]<<' ';
    return 0;
}
