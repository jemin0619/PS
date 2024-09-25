//적당히 구현해준다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    string S; cin>>S;
    stack<char> stk;
    for(char c : S){
        if(!stk.empty() && c==')' && stk.top()=='(') stk.pop();
        else stk.push(c);
    }
    cout<<stk.size();
    return 0;
}
