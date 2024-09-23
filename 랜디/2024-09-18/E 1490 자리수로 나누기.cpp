//사실 이게 왜 돌아가는지는 잘 모르겠다.
//앞 숫자는 입력받은 수로 고정시키고, 그 뒤에 0~9, 00~99, 000~999, 00000~99999 다 넣어보면서 되는지 판단한다.
//LCM을 사용해 판별을 간단하게 하였다.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}

int main(){
    string S; cin>>S;
    ll L = 1;
    for(char c : S){
        if(c=='0') continue;
        L = lcm(L, c-'0');
    }
    if(stoll(S)%L==0) {cout<<S; return 0;}
    ll digit = 1;
    while(true){
        string str = S;
        ll mx = pow(10, digit);
        for(int i=0; i<mx; i++){
            string tmp = to_string(i);
            while(tmp.size()<digit) tmp = "0" + tmp;
            ll tmp2 = stoll(S+tmp);
            if(tmp2%L==0) {cout<<tmp2; return 0;}
        }
        digit++;
    }
    return 0;
}
