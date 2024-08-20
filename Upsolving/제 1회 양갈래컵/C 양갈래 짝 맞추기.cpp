//참고 https://jaemin8852.tistory.com/299
//조합론이 너무 싫어요

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    ll N; cin>>N;
    ll Ans = 1;
    for(ll i=N; i>0; i-=2){
        Ans *= (i*(i-1))/2;
        Ans /= (i/2); //쌍들을 뽑을때 생긴 순서 삭제
    }
    cout<<Ans;
    return 0;
}
