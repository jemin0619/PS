//모든 보석을 나눠줘야 하고, 한 사람은 같은 색의 보석만 가져갈 수 있음
//Check(Mid) : 한 사람이 가져갈 수 있는 최대 보석 개수(질투심)를 Mid개로 정할 수 있는가?
//FT로 존재하므로 hi를 출력한다. (질투심 제한을 늘릴수록 모든 보석을 사람들에게 나눠줄 수 있음 (못받는사람도 존재) , M<=N)

//lo와 hi를 잡는 기준은 어떤 상황에서도 Check(mid)가 False와 True로 구성되게 하는 것이다.
//lo를 1로 반례는 다음과 같다.

//3 3
//1 1 1
//ans : 1

//이 경우 lo가 1이면 2가 나오게 된다. 
//Check(1)이 True이기 때문인데, 이렇게 되면 TT...가 되므로 안된다.
//그러므로 항상 범위를 잡을 때 FT라면 Check(lo)=F Check(hi)=T로, TF라면 반대로 잡아야 한다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

ll N,M; //사람수 보석수
vector<ll> V;

bool Check(ll x){ 
    ll num = 0; //나누어진 보석 묶음의 개수
    for(ll val : V){
        num += (val/x + (val%x!=0));
    }
    //보석 묶음의 개수가 사람들 수보다 작거나 같으면 모든 보석을 나눠줄 수 있다.
    return num<=N;
}

int main(){
    fastio;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        ll x; cin>>x;
        V.push_back(x);
    }
    
    ll lo=0, hi=1e9;
    while(lo+1<hi){
        ll mid = (lo+hi)/2;
        if(Check(mid)) hi=mid;
        else lo=mid;
    }
    cout<<hi;
    return 0;
}
