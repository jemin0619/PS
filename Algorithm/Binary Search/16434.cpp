//Chk는 FFTT로 존재함
//Chk(0)=F (항상)
//Chk(1.23456e17+1) = T(항상)

//100만 * 100만 * 123456 = 1.23456e17
//대략 큰 값인 1e18 + 7로 잡아도 된다.

//1번 쿼리를 반복문으로 처리할 경우 시간초과가 무조건 발생하기에 수학적으로 처리해야 한다.
//몬스터의 체력을 Hm, 공격력을 Atkm, 용사의 체력을 Hh, 공격력을 Atkh로 정의한다.
//용사가 몬스터를 죽이려면 ceil(Hm/Atkh) 번 공격해야 한다. (ceil은 반올림)
//이를 풀어서 쓰면 다음과 같다. ceil(Hm/Atkh) = (Hm+Atkh-1)/Atkh
//용사가 선공이기에 몬스터는 용사보다 한 번 적게 공격한다.
//그러므로 (Hm+Atkh-1)/Atkh -1 번의 공격을 Atkm의 공격력으로 시전한다는 것이다.
//즉 ((Hm+Atkh-1)/Atkh -1)*Atkm이 용사가 받는 데미지라고 할 수 있다.

//24.10.28 지금 보니까 ceil은 걍 올림임.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

ll N, Hatk;
vector<tuple<ll,ll,ll>> V;

bool Check(ll x){ //최대체력 x로 드래곤을 쓰러뜨릴 수 있는가
    ll Health=x; ll Atk=Hatk; 
    for(auto[t,a,h] : V){
        if(t==1){ //공격력 a, 체력 h인 몬스터와 조우
            Health -= ((h+Atk-1)/Atk-1)*a;
            if(Health<=0) return false;
        }
        if(t==2){ //공격력 + a, 체력 + h
            Atk += a;
            Health = min(x,Health+h);
        }
    }
    return true;
}  

int main(){
    fastio;
    cin>>N>>Hatk;
    for(int i=0;i<N;i++){
        ll t,a,h; cin>>t>>a>>h;
        V.push_back({t,a,h});
    }
    ll lo=0, hi=1e18+7;
    while(lo+1<hi){
        ll mid = (lo+hi)/2;
        if(Check(mid)) hi = mid;
        else lo = mid;
    }
    cout<<hi;
    return 0;
}
