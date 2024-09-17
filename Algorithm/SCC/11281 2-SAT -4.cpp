//해를 구하는 아이디어는 다음의 개념에서 비롯된다.
// A -> B
// A가 T/F 일때 B는 T이다.
// A가 false여도 B는 true일 수 있으므로, 왠만해서 false로 두는 것이 좋다.
//그러므로 SCC를 위상정렬한 순서로 방문할 때, 아직 x와 ~x가 정해지지 않았다면, 현재 방문한 정점을 false로 둔다.

//추가적으로 부정 노드를 나는 not i를 i+N으로 잡았는데, 짝수 홀수를 구분해 X/2를 하면 i가 나오도록 하는게 대세인 것 같다.
//예를 들어 [3]이 있으면, 6은 [3]이고, 7은 [not 3]이다. 6과 7 모두 /2를 하면 원래 수가 나온다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N, M;
vector<int> adj[20'003];
vector<int> order(20'003, -1);
vector<int> SccNum(20'003, -1);
stack<int> stk;

int Oppose(int num){
    if(num>N) return num-N; //num>N 이면 num은 not인 노드임
    else return num+N; //num<=N 이면 num은 not이 아닌 노드임
}

int sccCnt = 0;
int orderCnt = 0;
int SCC(int cur){
    stk.push(cur);
    int ret = order[cur] = orderCnt++;
    for(int nxt : adj[cur]){
        if(order[nxt]==-1) ret = min(ret, SCC(nxt));
        else if(SccNum[nxt]==-1) ret = min(ret, order[nxt]);
    }
    if(ret == order[cur]){
        while(true){
            int x = stk.top(); stk.pop();
            SccNum[x] = sccCnt;
            if(x == cur) break; 
        }
        sccCnt++;
    }
    return ret;
}

vector<int> _2SAT(){
    for(int i=1; i<=2*N; i++){
        if(order[i]==-1) SCC(i);
    }

    for(int i=1; i<=N; i++)
        if(SccNum[i] == SccNum[i+N]) return vector<int>();

    vector<pair<int,int>> Order_2SAT;
    for(int i=1; i<=N*2; i++){
        Order_2SAT.push_back({-SccNum[i], i});
    }
    sort(Order_2SAT.begin(), Order_2SAT.end());

    vector<int> answer(N+3, -1);
    for(auto&[x, node] : Order_2SAT){
        int original = node;
        if(original>N) original = original - N;
        if(answer[original]!=-1) continue; //이미 값이 정해진 경우
        if(node <= N) answer[original] = 0;
        else if(node > N) answer[original] = 1;
    }
    return answer;
}

int main(){
    fastio;
    cin>>N>>M;
    while(M--){
        int u,v; cin>>u>>v;
        if(u<0) u = Oppose(abs(u));
        if(v<0) v = Oppose(abs(v));
        adj[Oppose(u)].push_back(v);
        adj[Oppose(v)].push_back(u);
    }
    
    vector<int> ans = _2SAT();
    if(ans.empty()) cout<<"0";
    else{
        cout<<1<<'\n';
        for(int i=1; i<=N; i++){
            cout<<ans[i]<<' ';
        }
    }
    return 0;
}
