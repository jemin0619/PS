/*
첫째 줄만 누를지 말지를 결정한 후엔 
두번째줄부터 확인하면서 윗칸(지금이 아니면 바꿀 수 없는 칸)이 켜져 있으면 현재 칸을 눌러서 끈다.
비트마스킹으로 첫째 줄로 구할 수 있는 모든 경우의 수를 확인한다.
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL) -> sync_with_stdio(false);
#define ll long long

int ans = 0x7f7f7f7f;
string board_main[13];
string board[13];
int dy[] = {1,0,-1,0,0};
int dx[] = {0,1,0,-1,0};

void Click(int y, int x){
    for(int dir=0;dir<5;dir++){
        int ny = y+dy[dir];
        int nx = x+dx[dir];
        if(ny<0 || nx<0 || ny>=10 || nx>=10) continue;
        
        if(board[ny][nx]=='O') board[ny][nx] = '#';
        else board[ny][nx] = 'O';
    }
}

bool IsAllOff(){
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            if(board[i][j]=='O') return false;
    return true;
}

int main() {
    fastio;
    for(int i=0; i<10; i++) cin>>board_main[i];
    for(int i=0; i<(1<<10); i++){
        int temp = 0;
        for(int j=0;j<10;j++) board[j] = board_main[j];
        for(int j=0;j<10;j++){ //비트마스킹으로 생성된 순열에 따라 버튼을 누름 
            if((1<<j)&i) {Click(0,j); temp++;}
        }
        for(int ii=1;ii<10;ii++){
            for(int jj=0;jj<10;jj++){
                if(board[ii-1][jj]=='O'){
                    Click(ii,jj);
                    temp++;
                }
            }
        }
        if(IsAllOff()) ans = min(temp, ans);
    }
    if(ans == 0x7f7f7f7f) ans = -1;
    cout<<ans;
    return 0;
}
