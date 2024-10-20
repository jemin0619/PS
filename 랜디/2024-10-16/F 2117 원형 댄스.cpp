#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll N){
    if(N==1 || N==2) return 0;
    if(N==3) return 1;
    ll A = N/2;
    ll B = N - A;
    A--; B--;
    ll ret = A*A + A + B*B + B;
    return ret/2;
}

int main(){
    ll N; cin>>N;
    cout<<solve(N);
    return 0;
}