//어떤 노드의 차수가 1이라는 것은 모든 노드를 1:1 매칭시킬때, 그 노드는 유일한 한 쌍을 이룬다는 것이다.
//그러므로 쌍을 이루는 노드들부터 묶어주고, 차수를 갱신하면서 차수가 1인 노드들을 계속 큐에 넣으면서 관리한다.

#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin>>N>>M;

    vector<vector<int>> adj(2 * N + 1);
    vector<int> indegree(2 * N + 1, 0);
    vector<int> matched(2 * N + 1, 0);
    queue<int> Q;

    while(M--){
        int a, b; cin>>a>>b;
        adj[a].push_back(N + b);
        adj[N + b].push_back(a);
        indegree[a]++;
        indegree[N + b]++;
    }

    for (int i=1; i<=2*N; i++){
        if(indegree[i]==1) Q.push(i);
    }

    int cnt = 0;
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        
        //간선들을 제거하는 것은 무거운 연산이므로 사용하지 않는다.
        //그렇기에 차수가 1이라도 여러 간선들이 있을 수 있다.
        //매번 !matched[nxt]를 써줘서 막아줄 수 있다.

        for(int nxt1 : adj[cur]){
            if (!matched[nxt1]){
                matched[cur] = nxt1;
                matched[nxt1] = cur;

                //양방향 그래프이기에 들어오는 간선이 하나라는 말은 나가는 간선도 하나라는 말이다.
                //그렇기에 cur은 차수가 1인 간선이므로 나가는 간선도 nxt1 하나이다.
                //그러니 adj[cur]에 대해 loop를 돌 필요는 없다. (이미 돌았기에 queue에 들어온 것이기 때문)

                //adj[nxt1]에 대해서 loop를 돌며 차수를 업데이트하고 queue에 넣어준다.
                for(int nxt2 : adj[nxt1]){
                    if(matched[nxt2]) continue; 
                    indegree[nxt2]--;
                    if(indegree[nxt2]==1) Q.push(nxt2);
                }
                cnt++;
                break;
            }
        }
    }

    if(cnt != N){
        cout << "NO";
        return 0;
    }

    cout<<"YES\n";
    for(int i=1; i<=N; i++){
        cout<<matched[i] - N<<'\n';
    }

    return 0;
}
