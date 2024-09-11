//C보단 괜찮았던 수학 기하 애드혹
//쉽지 않음

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int main(){
    fastio;
    ll N; cin>>N;
    if(N==1) cout<<0;
    else cout<<(N+1)/2;
    return 0;
}
