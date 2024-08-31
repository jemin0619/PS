//DP (Large) 코드를 가져왔다.
//지문을 읽으면 바로 LIS 응용이라는 것을 알 수 있다.
//처음에 쿼리 처리를 어떻게 할지 고민했는데, LIS를 양방향으로 돌리면서 i를 시작으로, 끝으로 하는 LIS를 구해놓는다.
//이후 두 값을 더한 값에서 -1을 하면 답이 된다.

//LIS를 구하는 방식에 따라 Small과 Large가 나뉘는데, O(NlogN) LIS 풀이를 가져왔다.
//음수를 사용해 i를 시작으로 하는 LIS를 구하는게 인상적이었다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int N, Q; cin>>N>>Q;
    vector<int> V(N+1);
    vector<int> dp1(N+1, 1); //i를 끝으로 하는 LIS의 길이
    vector<int> dp2(N+1, 1); //i를 시작으로 하는 LIS의 길이
    for(int i=1; i<=N; i++) cin>>V[i];

    vector<int> V1;
    V1.push_back(V[1]);
    for(int i=2; i<=N; i++){
        if(V[i]>V1.back()){
            V1.push_back(V[i]);
            dp1[i] = V1.size();
        }
        else{
            int idx = lower_bound(V1.begin(), V1.end(), V[i]) - V1.begin();
            V1[idx] = V[i];
            dp1[i] = idx+1;
        }
    }

    //음수로 처리하면 기존의 O(NlogN) LIS 알고리즘을 적용시킬 수 있다. 
    vector<int> V2;
    V2.push_back(-V[N]);
    for(int i=N-1; i>=1; i--){
        if(-V[i]>V2.back()){
            V2.push_back(-V[i]);
            dp2[i] = V2.size();
        }
        else{
            int idx = lower_bound(V2.begin(), V2.end(), -V[i]) - V2.begin();
            V2[idx] = -V[i];
            dp2[i] = idx+1;
        }
    }

    while(Q--){
        int x; cin>>x;
        cout<<dp1[x]+dp2[x]-1<<'\n';
    }
    return 0;
}
