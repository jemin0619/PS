#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int main(){
    fastio;
    ll N; cin>>N;
    ll mx = 2;
    while(mx<N) mx*=2;
    cout<<mx<<' ';
    if(mx==N){
        cout<<0; 
        return 0;
    }
    ll cnt = 0;
    while(N){
        mx/=2;
        if(mx<=N) N-=mx;
        cnt++;
    }
    cout<<cnt;
    return 0;
}

/*
2 4 8 16

15의 경우엔?
16을 구매해서 8, 8로 나눈다. 
8 하나는 바로 사용한다. (남은 개수: 7)
나머지 8을 4, 4로 만든다. 
4 하나는 바로 사용한다. (남은 개수: 3)
나머지 4를 2,2로 만든다. 
2 하나는 바로 사용한다. (남은 개수: 1)
1, 1로 만들고 바로 사용
*/
