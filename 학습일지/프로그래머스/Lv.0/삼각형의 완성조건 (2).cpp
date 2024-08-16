#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    sort(sides.begin(),sides.end());
    //가장 긴 변 x가 sides에 있는 경우
    // (sides[1] < sides[0]+x) && x<=sides[1]
    // 즉 sides[1]-sides[0] < x <= sides[1]
    // -> sides[1] - (sides[1]-sides[0])
    answer += sides[0];
    
    //가장 긴 변 x가 result에 있는 경우
    // (x < sides[0]+sides[1]) && sides[1]<x
    // sides[1] < x < sides[0]+sides[1]
    answer += sides[0]-1;
    return answer;
}
