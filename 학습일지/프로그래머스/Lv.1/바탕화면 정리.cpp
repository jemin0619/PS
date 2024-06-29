//paper가 있는 가장 상단의 Y값, 가장 왼쪽의 X값, 가장 하단의 Y값, 가장 오른쪽의 X값을 return하면 해결할 수 있다.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer(4);
    answer[0] = answer[1] = 55;
    answer[2] = answer[3] = -1;
    for(int y=0;y<wallpaper.size();y++){ //Y축 이동
        for(int x=0;x<wallpaper[y].size();x++){ //X축 이동
            if(wallpaper[y][x]=='#'){
                answer[0] = min(answer[0],y); //가장 상단 Y값
                answer[1] = min(answer[1],x); //가장 왼쪽 X값
                answer[2] = max(answer[2],y); //가장 하단 Y값
                answer[3] = max(answer[3],x); //가장 오른쪽 X값
            }
        }
    }
    answer[2]++;
    answer[3]++;
    return answer;
}
