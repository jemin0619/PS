//가위 true, 바위 false로 모델링
//양수 -> 가위 -> true
//음수 -> 바위 -> false

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N,M;
vector<int> adj[20'003];
vector<int> order(20'003, -1);
vector<int> SccNum(20'003, -1);
stack<int> stk;

int oppose(int n){
    if(n <= N) return n + N;
    else return n - N;
}

int orderCnt = 0;
int sccCnt = 0;
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
            if(x==cur) break;
        }
        sccCnt++;
    }
    return ret;
}

int main(){
    fastio;
    cin>>N>>M;
    for(int i=1; i<=N; i++){
        int x,y; cin>>x>>y;
        if(x<0) x = oppose(abs(x));
        if(y<0) y = oppose(abs(y));
        adj[oppose(x)].push_back(y);
        adj[oppose(y)].push_back(x);
    }
    for(int i=1; i<=2*N; i++){
        if(order[i]==-1) SCC(i);
    }
    for(int i=1; i<=N; i++){
        if(SccNum[i]==SccNum[i+N]){
            cout<<"OTL";
            return 0;
        }
    }
    cout<<"^_^";
    return 0;
}
