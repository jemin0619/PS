//모든 게임에서 승리함.
//x를 게임횟수라고 가정한다.
//f(x)에 따라 x가 증가할수록 파라미터가 FFTT로 존재하는 결정문제로 볼 수 있다.

//(long long)(nX/nY * 100)이 (long long)(X/Y * 100)과 다르면 T
//가장 빠른 T(hi)를 출력한다.

//다음 식은 항상 성립한다.
// f(0) = F
// f(???) = T 구하기 귀찮아서 대충 큰 수를 넣었다.

//처음에 hi를 1e18로 해서 오버플로우때문에 틀렸었는데 주의해야겠다.

#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define fastio cin.tie(NULL)->sync_with_stdio(false);

ll X,Y; //게임 횟수, 이긴 게임

bool Check(ll mid){
    ll pre = (Y*100)/X;
    ll nxt = ((Y+mid)*100)/(X+mid);
    return nxt > pre;
}

int main(){
    fastio;
    cin>>X>>Y;
    ll lo=0, hi=1e12;
    while(lo+1 < hi){
        ll mid = (lo+hi)/2;
        if(Check(mid)) hi = mid;
        else lo = mid;
    }
    if(Check(hi)) cout<<hi;
    else cout<<-1;
    return 0;
}
