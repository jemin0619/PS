//새가 실제로 이동할 수 있는 구멍의 크기는 줄어드는 것이 명확하므로 이를 활용해 이분탐색 혹은 모노톤 큐 느낌의 풀이를 짤 수 있다.
//이분탐색이 더 직관적이지만 {오프라인 쿼리, 정렬} 쪽 풀이를 선택했다.
//정렬은 새의 크기가 큰 순으로 정렬했다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define x first
#define y second

int main(){
    fastio;
    int N; cin>>N;
    vector<int> U(N), D(N), gap(N+1);
    for(int i=0; i<N; i++) cin>>U[i];
    for(int i=0; i<N; i++) cin>>D[i];
    for(int i=0; i<N; i++){
        if(i>0) gap[i] = min(gap[i-1], U[i]-D[i]);
        else gap[i] = U[i]-D[i];
    } gap[N] = -1;
    int M; cin>>M;
    deque<pair<int,int>> deq(M);
    vector<int> ans(M);
    for(int i=0; i<M; i++){
        int x; cin>>x;
        deq[i] = {x, i};
    }
    sort(deq.begin(), deq.end(), greater<pair<int,int>>());
    for(int i=0; i<=N; i++){
        while(!deq.empty() && deq.front().x>gap[i]){
            ans[deq.front().y] = i;
            deq.pop_front();
        }
    }
    for(int i=0; i<M; i++) cout<<ans[i]<<'\n';
    return 0; 
}
