//비둘기집 원리를 알아야 함
//100개의 비둘기 집이 있을 때 비둘기 101마리가 집에 들어갔다면 한 집에는 두 비둘기가 들어가 있다는 것을 알 수 있다.
//이처럼 MBTI도 16개뿐이기에 N이 32보다 크다면 같은 MBTI 3개가 존재한다는 것을 알 수 있다.
//그렇기에 N이 32보다 작거나 같으면 브루트포스로 답을 구하고 아니면 0을 출력한다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)
#define ll long long

ll diff(string A, string B){
    ll ret = 0;
    for(int i=0;i<4;i++){
        if(A[i]!=B[i]) ret++;
    }
    return ret;
}

int main(){
    ll t; cin>>t;
    while(t--){
        ll N; cin>>N;
        vector<string> V;
        for(int i=0;i<N;i++){
            string x; cin>>x;
            V.push_back(x);
        }
        if(N>33) {cout<<"0\n"; continue;}
        
        ll mn = 0x7f7f7f7f;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                for(int k=0;k<N;k++){
                    if(i==j || j==k || k==i) continue;
                    ll val = diff(V[i],V[j]) + diff(V[j],V[k]) + diff(V[k],V[i]);
                    mn = min(val, mn);
                }
            }
        }
        cout<<mn<<'\n';
    }
    return 0;
}
