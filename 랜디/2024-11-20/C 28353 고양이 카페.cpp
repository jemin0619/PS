//엄밀하게 증명은 못하겠는데, 그리디 + 투포인터 + 정렬로 풀린다.
//왠지 보자마자 가장 큰거랑 작은거 짝지어가며 해결하면 될 것 같았는데 된다.
//엄밀한 증명은 당장은 안떠오르는데, 느낌상 이해는 된다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int N, K; cin>>N>>K;
    vector<int> V(N);
    for(int i=0; i<N; i++) cin>>V[i];
    sort(V.begin(), V.end());
    int st=0, en=N-1;
    int ans = 0;
    while(st<en){
        //V[st] + V[en] 이 K 안넘으면 그냥 해도 됨
        while(V[st]+V[en] > K && st<en) en--;
        if(st<en){
            ans++;
            st++; en--;
        }
    }
    cout<<ans;
    return 0;
}
