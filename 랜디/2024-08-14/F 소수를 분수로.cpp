//1.1같이 무한소수가 아닌 소수가 들어왔을 경우 b가 0이 되므로 Division by zero 에러가 뜰 수 있다.
//이 점만 고려해서 풀어주면 된다.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    string S; cin>>S;
    string tmp = "";
    string N="", M="", K=""; //정수부, 소수부(순환 제외), 순환소수부
    int step = 0;
    for(char c : S){
        if(c=='.') {step=1; continue;}
        if(c=='(') {step=2; continue;}
        if(c==')') continue;
        if(step==0) N+=c;
        if(step==1) M+=c;
        if(step==2) K+=c;
    }
    if(M.empty() && K.empty()) {cout<<N<<"/1"; return 0;}

    string A = ""; //분모
    for(int i=0; i<K.size(); i++) A+='9';

    if(A.empty()) A = "1";
    for(int i=0; i<M.size(); i++) A+='0';

    string B1 = N+M+K;
    string B2 = N+M;
    
    ll a = stoll(A);
    ll b = stoll(B1) - stoll(B2);
    if(b==0){
        b = stoll(B1);
    }
    
    ll g = gcd(a,b);
    a /= g;
    b /= g;
    cout<<b<<'/'<<a;

    return 0;
}
