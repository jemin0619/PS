//FFTT로 존재
//Check(x) : 블루레이의 길이가 x일때 모든 영상을 넣을 수 있는가?
//가장 작은 T (hi)를 출력

//19번째 줄 예외처리를 안하면 50%에서 WA가 뜸

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N,M; 
vector<ll> V;

bool Check(ll x){
    ll cnt = 1;
    ll sum = 0;
    
    for(ll val : V){
        if(val > x) return false;
        if(sum + val > x){
            sum = val;
            cnt++;
        }
        else sum += val;
    }
    if(cnt <= M) return true;
    else return false;
}

int main(){
    cin>>N>>M;
    ll lo=-1,hi=1;
    for(int i=0;i<N;i++){
        ll x; cin>>x;
        V.push_back(x);
        hi += x;
    }

    while(lo+1<hi){
        ll mid = (lo+hi)/2;
        if(Check(mid)) hi = mid;
        else lo = mid;
    }
    cout<<hi;
    return 0;
}
