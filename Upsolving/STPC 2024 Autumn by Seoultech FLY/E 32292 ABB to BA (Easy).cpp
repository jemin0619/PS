//제한이 작아서 브루트포스로 풀린다.
//하지만 Hard도 풀기 위해 stack으로 풀었다.
//풀이에 관련된 주석은 Hard 코드에 남겨두었다.

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
