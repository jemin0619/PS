//그냥 백트래킹 딸깍으로 풀리는데 스도쿠 규칙에서 빼먹은게 있어서 해맸다.

#include <bits/stdc++.h>
using namespace std;

bool isused1[4][4][10]; //i,j에 위치한 3x3 격자 내부에서 k가 사용되었는가?
bool isused2[10][10]; //i번째 가로줄에 j가 사용되었는가?
bool isused3[10][10]; //i번째 세로줄에 j가 사용되었는가?
int matrix[13][13];
vector<pair<int,int>> V;

void func(int depth){
    if(depth==V.size()){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout<<matrix[i][j];
            } cout<<'\n';
        }
        exit(0);
    }
    int y = V[depth].first;
    int x = V[depth].second;
    for(int i=1; i<=9; i++){
        if(isused1[y/3][x/3][i]) continue;
        if(isused2[y][i]) continue;
        if(isused3[x][i]) continue;

        isused1[y/3][x/3][i] = true;
        isused2[y][i] = true;
        isused3[x][i] = true;
        matrix[y][x] = i;

        func(depth+1);

        isused1[y/3][x/3][i] = false;
        isused2[y][i] = false;
        isused3[x][i] = false;
        matrix[y][x] = 0;
    }
}

int main(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            scanf("%01d", &matrix[i][j]);
            if(matrix[i][j]==0) V.push_back({i,j});
            else{
                isused1[i/3][j/3][matrix[i][j]] = true;
                isused2[i][matrix[i][j]] = true;
                isused3[j][matrix[i][j]] = true;
            }
        }
    }
    func(0);
    return 0;
}
