//문제를 잘 보면 LIS라는 것을 알 수 있다.
//N이 작으므로 O(N^2) LIS로 해결했다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL) -> sync_with_stdio(false);
#define ll long long

int N,ans;
vector<int> V;
vector<int> dp;

int main(){
    fastio;
    cin>>N;
    V.resize(N);
    dp.resize(N);
    for(int i=0;i<N;i++){
        cin>>V[i]; dp[i]=1;
    }
    for(int i=1;i<N;i++){
        for(int j=0;j<i;j++){
            if(V[j]<V[i]) dp[i]=max(dp[i],dp[j]+1);
        }
    }
    cout<<*max_element(dp.begin(),dp.end());
    return 0;
}
