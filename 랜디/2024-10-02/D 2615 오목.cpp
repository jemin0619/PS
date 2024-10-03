//구현이 생각보다 까다롭다.
//다양한 방법으로 오목 확인 알고리즘을 구현할 수 있을 것 같다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<vector<int>> V(19, vector<int>(19));
int ansY, ansX;

bool check(int y, int x){
    for(int dir=0; dir<8; dir++){
        int cnt = 1;
        ansY = y;
        ansX = x;
        for(int k=1; k<=20; k++){
            int ny = y+dy[dir]*k;
            int nx = x+dx[dir]*k;
            if(ny<0 || nx<0 || ny>=19 || nx>=19) break;
            if(V[ny][nx]!=V[y][x]) break;
            cnt++;
            if(nx<ansX) {ansY=ny; ansX=nx;}
        }
        if(cnt==5){
            //반대편에 돌이 하나 놓여있으면 false  
            int ndir = (dir+4)%8;
            int ny = y+dy[ndir];
            int nx = x+dx[ndir];
            if(ny<0 || nx<0 || ny>=19 || nx>=19) return true;
            if(V[ny][nx]!=V[y][x]) return true;
            return false;
        }
    }
    return false;
}

int main(){
    fastio;
    for(int i=0; i<19; i++)
        for(int j=0; j<19; j++)
            cin>>V[i][j];

    for(int i=0; i<19; i++){
        for(int j=0; j<19; j++){
            if(V[i][j]==0) continue;
            if(check(i, j)){
                cout<<V[i][j]<<'\n';
                cout<<ansY+1<<' '<<ansX+1;
                return 0;
            }
        }
    }
    cout<<0;
    return 0;
}
