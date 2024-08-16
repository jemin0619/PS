//이분탐색, 수학

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N;

//1 ~ mid 까지의 수 중 5와 연관된 수의 개수 카운트
ll check(ll mid){
    ll ret = 0;
    while(mid>=5){
        mid /= 5;
        ret += mid;
    }
    return ret;
}

int main(){
    cin>>N;
    ll st=4, en=1e9;
    while(st+1<en){
        ll mid = (st+en)/2;
        if(check(mid)<N) st = mid; //0의 개수가 N보다 작으면 st를 --> 로 보내서 수를 늘림
        else en = mid; //0의 개수가 N보다 크거나 같으면 en을 <-- 로 보내서 mid를 줄임
    }
    if(check(en)==N) cout<<en;
    else cout<<-1;
    return 0;
}
