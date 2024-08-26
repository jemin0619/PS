//S5 그리디이고 아이디어가 간단합니다.
//A먼저 채우고 남은곳에 B 채우기

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int main(){
    fastio;
    string S; cin>>S;
    string ans = "";
    int len = 0;
    for(char c : S){
        if(c=='.'){
            if(len==0) {ans+='.'; continue;}
            if(len%2!=0) {cout<<-1; return 0;}
            int A = len/4;
            int B = (len%4)/2;
            for(int i=0; i<A; i++){
                ans += "AAAA";
            }
            for(int i=0; i<B; i++){
                ans += "BB";
            }
            ans += '.';
            len = 0;
        }
        else len++;
    }
    if(len%2!=0) {cout<<-1; return 0;}
    int A = len/4;
    int B = (len%4)/2;
    for(int i=0; i<A; i++){
        ans += "AAAA";
    }
    for(int i=0; i<B; i++){
        ans += "BB";
    }
    cout<<ans;
    return 0;
}
