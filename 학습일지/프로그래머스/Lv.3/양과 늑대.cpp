//거의 바킹독님의 2022 KAKAO BLIND RECRUITMENT 비공식 해설집을 보고 풀었다.

//왜 비트마스킹 DFS로 해결을 해야 하는지에 대해 생각해보았다.
//가장 큰 이유는 노드마다 방문처리를 하기에 적합하지 않기 때문이다.
//이전 노드로 거슬러가서 양을 더 가져온 후 이동할 수도 있기 때문에 적합하지 않다.
//여기서 백트래킹이 떠올랐는데, 백트래킹으로 해결할 경우 포화이진트리의 경우 TLE가 나온다고 한다.

//그럼 노드들의 방문 상태를 비트마스킹을 통해 저장한다면?
//N이 17아므로 vis[1<<17]로 모든 상태를 제어할 수 있다.

//풀고 시간이 지나서 드는 생각인데, 가지치기를 훌륭하게 해낸 백트래킹 풀이인 것 같다.
//또, 전역변수를 쓰면 좋지 않을 것 같아서 사용하지 않았는데 써도 무방할 것 같다.

#include <string>
#include <vector>

using namespace std;

int Ans = 0;

void DFS(vector<int>&info, vector<vector<int>>&adj, vector<bool>&vis, int state){
    if(vis[state]) return;
    vis[state]=true;
    int Wolf=0;
    int All=0;
    for(int i=0; i<info.size(); i++){
        if(state & (1<<i)) {Wolf+=info[i]; All++;}
    }
    if(Wolf >= All - Wolf) return; //늑대가 양을 다 잡아먹은 경우엔 복구가 안됨
    Ans = max(Ans, All-Wolf);
    for(int i=0; i<info.size(); i++){
        if(!(state & (1<<i))) continue; //해당 노드를 방문한 적이 없다면 continue
        for(int nxt : adj[i]){
            DFS(info,adj,vis,state|(1<<nxt));
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    vector<vector<int>> adj(info.size());
    vector<bool> vis(1<<info.size());
    for(int i=0; i<edges.size(); i++){ //그래프 생성
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    DFS(info,adj,vis,1);
    answer = Ans;
    return answer;
}
