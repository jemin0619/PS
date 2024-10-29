//Ceil(A/B) = (A+B-1)/B
//Atk를 고정시키면 이기는데 필요한 최소 Hp를 다음의 식으로 구할 수 있다.
//Ceil(Enemy.Hp/Player.atk)*Enemy.atk + 1
//적을 죽일 만큼 때릴 수 있어야 이기기 때문이다.

//O(N^2)로 Player.atk를 결정하고, 이후 투 포인터로 나머지 카드들로 최소 Hp 이상을 만족시키는 경우의 수를 모두 구한다.
//총 시간복잡도는 O(N^3)이 된다.
//N이 500이라 0.2초에 돈다.

//간만에 자력솔이라 좋았다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int main(){
    fastio;
    ll N, Eatk, Eh; cin>>N>>Eatk>>Eh;
    vector<ll> V(N);
    for(int i=0; i<N; i++) cin>>V[i];
    ll ans = 0;

    //st~en까지를 공격력으로 묶음
    for(int st=0; st<N; st++){
        ll Patk = 0;
        for(int en=st; en<N; en++){
            Patk += V[en];
            ll mnPh = ((Eh+Patk-1)/Patk) * Eatk + 1; //승리에 필요한 플레이어의 최소 체력
            
            vector<ll> arr;
            for(int i=0; i<N; i++){
                if(st<=i && i<=en) continue;
                arr.push_back(V[i]);
            } int M = arr.size();

            //투 포인터로 가능한 모든 경우의 수 카운트
            //합이 mnPh에 도달하면 그 뒤엔 굳이 포인터를 이동시키지 않고 간단한 식으로 구한다.
            ll Ph = 0; ll hi=0;
            for(int lo=0; lo<M; lo++){
                while(hi<M && Ph<mnPh){
                    Ph += arr[hi];
                    hi++;
                }
                if(Ph>=mnPh) ans += (M-hi+1);
                Ph -= arr[lo];
            }
        }
    }

    if(ans==0) cout<<"IMPOSSIBLE";
    else cout<<ans;
    return 0;
}
