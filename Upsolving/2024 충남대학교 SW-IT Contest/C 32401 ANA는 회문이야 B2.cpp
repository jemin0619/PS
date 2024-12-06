#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int N; string S; cin>>N>>S;
    S = " " + S;
    vector<int> P1(N+1);
    vector<int> P2(N+1);
    for(int i=1; i<=N; i++){
        if(S[i]=='A') P1[i] += 1;
        if(S[i]=='N') P2[i] += 1;
        P1[i] += P1[i-1];
        P2[i] += P2[i-1];
    }
    int ans = 0;
    for(int st=1; st<=N-2; st++){
        for(int en=st+2; en<=N; en++){
            if(S[st]=='A' && S[en]=='A' && P1[en]-P1[st-1]==2 && P2[en]-P2[st-1]==1) ans++;
        }
    }
    cout<<ans;
    return 0;
}
