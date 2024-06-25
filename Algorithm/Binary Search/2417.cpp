//https://www.acmicpc.net/problem/2417
//FT로 존재하기에 T(hi)를 출력해야 한다.
//hi는 N의 최대값이 2^63-1이기에 2^31-1로 잡아서 제곱했을 때 N의 최대값에 근접하게 잡는다.
//N이 0일 경우 예외처리를 잊어선 안된다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll unsigned long long

ll N;

int main(){
    fastio;
    cin>>N;

    if(N==0) {cout<<0; return 0;}

    ll lo=0, hi=(1ULL<<32)-1;
    while(lo+1<hi){
        ll mid = (lo+hi)/2;
        if(mid*mid<N) lo = mid;
        else hi = mid;
    }

    cout<<hi;
    return 0;
}
