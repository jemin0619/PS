//그리디, 우선순위 큐, 정렬

//모든 폭탄을 터뜨려야 한다.
//번호가 큰 폭탄은 번호가 작은 폭탄을 터뜨릴 수 없다.
//그러므로 번호가 작은 폭탄부터 터뜨리는게 알맞은 전략이 된다.
//PQ에 {Ai, i}로 내림차순으로 저장
//터진 폭탄은 0으로 표시

#include <bits/stdc++.h>
using namespace std;

int N, K, Ans;
vector<int> V;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> PQ;

int main(){
    cin>>N>>K;
    V.resize(N);
    for(int i=0;i<N;i++) {cin>>V[i]; PQ.push({V[i],i});}
    while(!PQ.empty()){
        auto [num, idx]=PQ.top(); PQ.pop();
        if(V[idx]==0) continue;
        V[idx] = 0; //자기 자신 터뜨림
        for(int i=idx-1;i>=0;i--){ //자신으로부터 왼쪽 확인하면서 터뜨림
            if(V[i]==0) break;

            if(V[i]>=num && V[i]<=num+K) V[i]=0;
            else break;
        } 
        for(int i=idx+1;i<N;i++){ //자신으로부터 오른쪽 확인하면서 터뜨림
            if(V[i]==0) break;

            if(V[i]>=num && V[i]<=num+K) V[i]=0;
            else break;
        }
        Ans++;
    }
    cout<<Ans;
    return 0;
}
