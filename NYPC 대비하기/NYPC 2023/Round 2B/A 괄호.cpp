//그리디하게 접근
//인접한 괄호 쌍을 모두 없애면 )))((( 이런 모양이 남는다.
//하나씩 뒤집고 없애고 하면 남은 문자열의 길이만큼의 비용이 소모된다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define ff first
#define ss second
#define pii pair<ll,ll>
#define tiii tuple<ll,ll,ll>

int main(){
    fastio;
    int N; string S;
    cin>>N>>S;
    stack<char> st;
    int Ans = 0;
    for(char c : S){
        if(st.empty()) st.push(c);
        else if(st.top()=='(' && c==')') {st.pop(); Ans++;}
        else st.push(c);
    }
    Ans += st.size();
    cout<<Ans;
    return 0;
}
