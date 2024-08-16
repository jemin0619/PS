#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

/*
처음에 그래프로 접근한다는 발상조차 하지 못했는데, Hint를 보고서 깨달았다.
정점이 N개인 완전 그래프를 생성하고 그래프에서 DFS를 돌기만 하면 해결된다.

완전 그래프를 생성하지 않고도 for문으로 순회할 수 있다. (어차피 한 정점은 모든 정점으로 향할 수 있으므로)
*/

int N;
vector<int> adj[503];
bool vis[503][503];

void DFS(int cur, int pre){
    vis[pre][cur] = vis[cur][pre] = true;
    cout<<"a"<<cur<<' ';
    for(int nxt : adj[cur]){
        if(vis[cur][nxt] || vis[nxt][cur]) continue;
        DFS(nxt,cur); break;
    }
}

int main(){
    fastio;
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i==j) continue;
            adj[i].push_back(j);
        }
    }

    //이렇게 하지 않으면 TC2에서 문제가 생긴다.
    //사전순으로 가장 빠른 답을 출력해야 하므로 마지막 두개는 an a1일 것이다.
    //미리 방문처리를 해줘서 마지막에 방문하도록 해야 한다.
    //이 부분을 도저히 모르겠어서 답을 확인했다.
    vis[1][N] = vis[N][1] = true;

    DFS(1,0);
    cout<<"a1";
    return 0;
}
