#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    arr.push_back(0x7f7f7f7f);
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]!=arr[i+1]) answer.push_back(arr[i]);
    }

    return answer;
}
