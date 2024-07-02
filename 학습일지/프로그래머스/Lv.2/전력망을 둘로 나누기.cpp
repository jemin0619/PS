//유니온파인드 + 스투라로 해결
//DFS 한 번으로도 해결하던데 오버킬인듯...

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void init(int n, vector<int>&parent, vector<int>&sz){
    for(int i=1;i<=n;i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int u, vector<int>&parent){
    if(u==parent[u]) return u;
    return parent[u] = find(parent[u], parent);
}

void merge(int u, int v, vector<int>&parent, vector<int>&sz){
    u = find(u,parent); v = find(v,parent);
    if(u==v) return;
    if(sz[v]>sz[u]) swap(u,v);
    sz[u] += sz[v];
    sz[v] = 0;
    parent[v] = u;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 0x7f7f7f7f;
    vector<int> sz(n+1);
    vector<int> parent(n+1);
    for(int i=0;i<wires.size();i++){
        init(n,parent,sz);
        for(int j=0;j<wires.size();j++){
            if(i==j) continue;
            merge(wires[j][0],wires[j][1],parent,sz);
        }
        vector<int> V;
        for(int j=1;j<=n;j++){
            if(sz[j]==0) continue;
            V.push_back(sz[j]);
        }
        answer = min(answer, abs(V[0]-V[1]));
    }
    return answer;
}
