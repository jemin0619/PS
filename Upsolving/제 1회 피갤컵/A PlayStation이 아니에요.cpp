//파이썬은 stack에서도 문자열 슬라이싱이 가능해 풀이가 간단하다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int N; cin>>N;
    string S = "";
    while(N--){
        char x; cin>>x;
        if(S.size()<2) S+=x;
        else{
            if(x=='4' && S[S.size()-1]=='S' && S[S.size()-2]=='P') continue;
            if(x=='5' && S[S.size()-1]=='S' && S[S.size()-2]=='P') continue;
            S+=x;
        } 
    }
    cout<<S;
    return 0;
}
