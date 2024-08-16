#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b){
	return b ? gcd(b, a%b) : a;
}

int main(){
    ll N; cin>>N;
    ll nume = 0; //분자
    ll deno = 1; //분모
    vector<pair<ll,ll>> V(N);
    for(int i=0;i<N;i++){
        ll x,y; cin>>x>>y;
        ll G = gcd(x,y);
        y/=G; x/=G;
        V[i] = {x,y};
        deno *= y/gcd(deno, y);
    }
    for(int i=0;i<N;i++){
        ll D = deno / V[i].second;
        nume = gcd(nume, V[i].first*D);
    }
    cout<<nume/(gcd(nume,deno))<<' '<<deno/(gcd(nume,deno));
    return 0;
}
