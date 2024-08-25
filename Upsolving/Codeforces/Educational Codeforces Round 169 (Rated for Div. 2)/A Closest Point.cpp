//점을 추가해서 그 점이 모든 점에 대해 가장 가까운 점이 되도록 할 수 있냐를 묻는다.
//코포가 간만이라 이런 애드훅이 A에 나온다고 생각하지 못했다.
//모든 점에 대해 가까워야하므로 N이 2보다 큰 경우는 불가능하다.
//추가로 정수만 삽입할 수 있으므로 두 수간 차가 1인 경우도 불가능하다. (+수가 오름차순으로 들어옴)

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int t; cin>>t;
    while(t--){
        int N; cin>>N;
        vector<int> V(N);
        for(int i=0; i<N; i++) cin>>V[i];
        if(N>2 || (N==2 && V[0]+1==V[1])) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;   
}
