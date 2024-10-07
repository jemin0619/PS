/*
스택에 입력받은 문자열을 넣어놓고 시작하는 방식으로 짜보자.
ABABABB 같은 연쇄적인 원소 변경이 일어나는 경우만 처리해주면 무난하게 AC를 받을 수 있을 것 같다.

원본 문자열이 들어가있는 스택을 S라고 하자.
ABB가 입력되었을 때 S의 top에는 A가 존재한다.

답이 저장될 벡터를 V라고 하자.
V의 원소가 2개 미만이면 S의 top을 넣어준다.
원소가 2개 이상인데 뒤쪽 원소가 AB를 이루고, 현재 S의 top이 B이면 두 번 pop 후 S에 AB를 순서대로 넣어준다.

이런 식으로 추가할 원소를 스택에 넣어서 관리하면 간단하게 풀 수 있을 것 같다.
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

void solve(){
    int n; cin>>n;
    string tmp; cin>>tmp;
    stack<char> S;
    vector<char> ans;
    for(int i=tmp.size()-1; i>=0; i--) S.push(tmp[i]);
    while(!S.empty()){
        char c = S.top(); S.pop();
        if(ans.size()>=2 && ans[ans.size()-2]=='A' && ans[ans.size()-1]=='B' && c=='B'){
            ans.pop_back();
            ans.pop_back();
            S.push('A');
            S.push('B');
        }
        else ans.push_back(c);
    }
    for(char c : ans) cout<<c;
    cout<<'\n';
}

int main(){
    fastio;
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}
