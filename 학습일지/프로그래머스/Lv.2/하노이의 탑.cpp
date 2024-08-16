//1. 마지막 원판을 제외한 원판들을 그대로 두 번째 막대로 옮긴다.
//2. 맨 밑 원판을 마지막 막대로 옮긴다.
//3. 두 번째 막대의 원판들을 그대로 마지막 막대로 옮긴다.

//재귀함수의 매개변수로 6-st-en이 의미하는 값은 st, en을 제외한 막대의 번호이다.
//각 막대의 번호를 더하면 6이므로 이 식이 성립한다.

//또, 가운데 막대에 꽂힌 원판들을 마지막 막대로 이동하는 것은 가운데 막대와 첫 번째 막대의 위치를 바꿔서 생각해보면 첫 번째 상황과 똑같다고 볼 수 있다.
//자기 힘으로 떠올리기엔 Lv.3은 될 것 같은데 너무 웰노운이라 Lv.2로 책정된 느낌이다...

#include <string>
#include <vector>

using namespace std;

void func(vector<vector<int>>&V, int n, int st, int en){
    if(n==1){
        V.push_back({st,en});
        return;
    }
    func(V,n-1,st,6-st-en);
    V.push_back({st,en});
    func(V,n-1,6-st-en,en);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    func(answer,n,1,3);
    return answer;
}
