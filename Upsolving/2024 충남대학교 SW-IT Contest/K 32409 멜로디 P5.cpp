//한 가지 전략으로 모든 케이스에 맞는 답을 만들어낼 수 있다.
//1 ~ N-1까지의 음을 바로바로 처리하면서 가는 것이다.
//다음 음과 번갈아가며 이동하면서 현재 음을 모두 다 쓰는 것이 최적이다.
//현재 음을 x번 써야 한다고 할 때, 소모해야 하는 다음 음은 x-1개이다. 
//(x=3) x, x+1, x, x+1, x ...
//이렇게 이동하다가 마지막 음이 하나 남거나 없다면 해당 멜로디를 만들 수 있다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

string solve(){
    int N; cin>>N;
    vector<int> a(N);
    for(int i=0; i<N; i++) cin>>a[i];
    for(int i=0; i<N-1; i++){
        if(a[i]<=0) return "NO";
        a[i+1] -= a[i]-1;
        a[i] = 0;
    }
    if(a[N-1]==0 || a[N-1]==1) return "YES";
    return "NO";
}

int main(){
    fastio;
    int tc; cin>>tc;
    while(tc--){
        cout<<solve()<<'\n';
    }
    return 0;
}
