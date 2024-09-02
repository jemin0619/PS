//역대급 애드 훅
//https://risk-boy.github.io/boj/31876/
//두 점수의 길이가 같고, 앞자리가 0이 아니라는 것을 이용한다.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int solve(int u, int v, string A, string B){
    int sz = A.size();

    if(u==v){
        if(A==B) return 2;
        if(A<B) return 1;
        else return 0;
    }

    if(sz>=22){ //이 경우부턴 u, v에 따라 대소관계 비교가능
        if(u>v) return 0;
        if(u<v) return 1;
        //rasauq는 u==v에서 이미 처리됨
    }

    ll sc_a=0, sc_b=0;
    ll mul_a=1, mul_b=1;
    for(int i=sz-1; i>=0; i--){
        sc_a += (mul_a * (ll)(A[i]-'0'));
        sc_b += (mul_b * (ll)(B[i]-'0'));
        mul_a *= u;
        mul_b *= v;
    }
    if(sc_a>sc_b) return 0;
    else if(sc_a<sc_b) return 1;
    else return 2;
}

int main(){
    fastio;
    ll u, v; string A,B; cin>>u>>v>>A>>B;
    
    int flag = solve(u,v,A,B);
    if(flag==0) cout<<"ras";
    if(flag==1) cout<<"auq";
    if(flag==2) cout<<"rasauq";
	return 0;
}
