//https://school.programmers.co.kr/learn/courses/30/lessons/258711
//처음엔 루트노드를 찾은 후 BFS로 접근하려다가 틀었다.
//굳이 BFS를 사용하지 않아도 루트 노드를 구하면서 사용할 indegree와 outdegree를 보면 각 그래프의 개수를 구할 수 있다.
//BFS에서 이 아이디어까지 발전시키는데 20분정도 걸린 것 같다.

//마지막 TC에서 문제가 생겼었는데 노드 번호가 순서대로 지어져있지 않을 경우였다.
//Set에 노드 번호를 집어넣어서 해결했다.

#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4);
    
    set<int> nodes;
    vector<int> indegree(100'0003);
    vector<int> outdegree(100'0003);
    vector<int> adj[100'0003];
    
    for(int i=0;i<edges.size();i++){
        outdegree[edges[i][0]]++;
        indegree[edges[i][1]]++;
        adj[edges[i][0]].push_back(edges[i][1]);
        nodes.insert(edges[i][0]);
        nodes.insert(edges[i][1]);
    }
    
    for(int i : nodes){
        if(indegree[i]==0 && outdegree[i]>=2){
            if(answer[0] != 0) cout<<"루트 노드 Error\n";
            answer[0] = i;
        }
    }
    
    for(int nxt : adj[answer[0]]){
        indegree[nxt]--;
    }
    
    for(int i : nodes){
        if(outdegree[i]==0) answer[2]++; //막대그래프
        if(outdegree[i]==2 && indegree[i]==2) answer[3]++; //8자 모양 그래프
    }
    
    answer[1] = outdegree[answer[0]] - answer[2] - answer[3];
    return answer;
}
