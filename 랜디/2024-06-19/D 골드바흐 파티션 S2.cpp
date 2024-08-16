#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL) -> sync_with_stdio(false);

vector<bool> isPrime(1000'010,true);
vector<int> Primes;

void seive(){
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i*i<=1000'003;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=1000'003;j+=i) isPrime[j]=false;
        }
    }

    for(int i=2;i<=1000'003;i++){
        if(isPrime[i]) Primes.push_back(i);
    }
}

int main(){
    fastio;
    seive();
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int ans = 0;
        for(int val : Primes){
            if(val>n) break;
            if(val*2==n) continue;
            if(isPrime[n-val]) ans++; //쌍이 지어지는 경우만 체크
        }
        ans/=2; //겹치는 쌍들을 없앰
        if(isPrime[n/2]) ans++;
        cout<<ans<<'\n';
    }
    return 0;
}
