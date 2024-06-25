/*
현우는 용돈을 효율적으로 활용하고 돈을 펑펑 쓰지 않기 위해서 앞으로 N일 동안 자신이 매일 사용할 금액을 계산하고, 
정확히 통장에서 M번, K원 씩 출금해서 사용하기로 결정했습니다. 현재 수중에 있는 금액으로 하루를 보낼 수 있다면 그대로 소비합니다. 
부족하다면, 수중에 있는 금액은 통장에 넣은 뒤 K원을 인출해서 하루를 생활합니다. 이때, 현우가 매번 출금할 금액 K원의 최솟값을 구하는 프로그램을 작성해주세요.

FFTT로 존재함?
T(hi) 출력

지문이 상당히 어색함
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL) -> sync_with_stdio(false);
#define ll long long

ll N,M;
vector<ll> V;

bool solve(ll mid){
    ll cnt = 0;
    ll price = mid;
    for(ll val : V){
        if(val > mid) return false; //1회 인출량이 val보다 작으면 실패
        if(val > price){ //현재 가진 돈이 부족하면
            cnt++; //사용횟수 증가
            if(cnt>=M) return false; //사용횟수가 M을 넘기면 실패
            price = mid; //현재 가진 돈 보충
        }
        price -= val; //돈 사용 (매번 시행됨)
    }
    return true;
}

int main() {
    fastio;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        ll x; cin>>x;
        V.push_back(x);
    }
    ll lo=0, hi=1e18;
    while(lo+1<hi){
        ll mid = (lo+hi)/2;
        if(solve(mid)) hi=mid;
        else lo = mid;
    }
    cout<<hi;
    return 0;
}
