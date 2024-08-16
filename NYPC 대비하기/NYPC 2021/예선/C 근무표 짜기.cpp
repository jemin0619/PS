//그리디, 정렬, 우선순위 큐 
//20번, 27번 라인이 있어야 AC를 받을 수 있다.

//PQ 만들고 {남은 근무일수, 개발자번호}로 저장
//오름차순 정렬시켜놓기
//날짜를 돌면서 PQ.top을 빼면서 Ans를 채움
//다음 날로 넘어갈땐 PQ에서 뺐던 원소를 갱신 후 다시 담아줘야함

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int N,K; cin>>N>>K;
    priority_queue<pair<int,int>> PQ; //{남은 근무일수, 개발자번호}
    vector<vector<int>> Ans(K+1);
    for(int i=1;i<=N;i++){
        int x; cin>>x;
        if(x==0) continue; //근무하는 사람만 PQ에 삽입
        PQ.push({x,i});
    }
    for(int i=1;i<=K;i++){
        int x; cin>>x;
        vector<pair<int,int>> tmp;
        while(x--){
            if(PQ.empty()) continue; //예외처리
            Ans[i].push_back(PQ.top().second);
            tmp.push_back({PQ.top().first-1,PQ.top().second});
            PQ.pop();
        }
        for(auto val : tmp){
            if(val.first==0) continue;
            PQ.push(val);
        }
    }
    for(int i=1;i<=K;i++){
        cout<<Ans[i].size()<<' ';
        for(int val : Ans[i]) cout<<val<<' ';
        cout<<'\n';
    }
    return 0;
}

//Ans에 안담고 tmp로 답을 출력해도 된다.
