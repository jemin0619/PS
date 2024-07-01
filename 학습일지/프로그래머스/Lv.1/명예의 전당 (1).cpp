#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int,vector<int>,greater<int>> PQ;
    for(int i=0; i<score.size(); i++){
        PQ.push(score[i]);
        if(PQ.size()>k) PQ.pop();
        answer.push_back(PQ.top());
    }
    return answer;
}
