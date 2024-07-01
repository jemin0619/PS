#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string tmp = "";
    for(int i=1;i<food.size();i++){
        if(food[i]%2) food[i]--;
    }
    
    for(int i=1;i<food.size();i++){
        for(int j=0;j<food[i]/2;j++){
            answer += to_string(i);
        }
    }

    for(int i=answer.size()-1;i>=0;i--) tmp += answer[i];
    answer = answer + "0" + tmp;
    return answer;
}
