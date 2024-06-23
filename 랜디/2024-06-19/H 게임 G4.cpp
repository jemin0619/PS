//전형적인 DFS

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

ll L, R, ans;
map<string,bool> vis;
map<string,int> dp;

string f(string str){
    ll mul=1, sum=0;
    for(char c : str){
        mul *= (c-'0');
        sum += (c-'0');
    }
    string ret = to_string(sum)+to_string(mul);
    return ret;
}

int DFS(string str){
    if(vis[str]) return dp[str];
    vis[str]=true;
    string ret = f(str);
    if(stoll(ret)>100000) return dp[str] = -1;
    if(ret==str) return dp[str] = 1;
    return dp[str] = DFS(ret);
}

int main(){
    fastio;
    cin>>L>>R;
    for(int i=L;i<=R;i++){
        ans += DFS(to_string(i));
    }
    cout<<ans;
    return 0;
}
