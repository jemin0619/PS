//Monotone Stack 문제입니다.
//두 원소 a,b 사이에 min(a,b)보다 큰 값이 없으면 두 원소 쌍은 답이 됩니다.
//Stack을 Monotonic하게 내림차순으로 유지시키면 O(N)에 해결할 수 있습니다.

#include <bits/stdc++.h>
using namespace std;

int N,ans;
stack<int> S;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++){
        int x; cin>>x;
        while(!S.empty() && S.top()<x){
            ans++;
            S.pop();
        }
        if(!S.empty()) ans++;
        S.push(x);
    }
    cout<<ans;
    return 0;
}
