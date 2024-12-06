//일단 맞게만 짜봤는데, 중복되는 부분이 많아서 코드 길이를 상당히 짧게 할 수도 있다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define pii pair<int,int>
#define xx first
#define yy second

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

int main(){
    fastio;
    int N; cin>>N;
    pii Player = {0,0}, Camera = {0, -1};
    int dir = 0;
    while(N--){
        string S; cin>>S;
        if(S=="W"){
            int ndir = dir;
            Player.xx += dx[ndir];
            Player.yy += dy[ndir];
            Camera.xx += dx[ndir];
            Camera.yy += dy[ndir];
        }
        if(S=="A"){
            int ndir = (dir+3)%4;
            Player.xx += dx[ndir];
            Player.yy += dy[ndir];
            Camera.xx += dx[ndir];
            Camera.yy += dy[ndir];
        }
        if(S=="S"){
            int ndir = (dir+2)%4;
            Player.xx += dx[ndir];
            Player.yy += dy[ndir];
            Camera.xx += dx[ndir];
            Camera.yy += dy[ndir];
        }
        if(S=="D"){
            int ndir = (dir+1)%4;
            Player.xx += dx[ndir];
            Player.yy += dy[ndir];
            Camera.xx += dx[ndir];
            Camera.yy += dy[ndir];
        }
        if(S=="MR"){
            dir = (dir+1)%4;
            int ndir = (dir+2)%4;
            Camera.xx = Player.xx + dx[ndir];
            Camera.yy = Player.yy + dy[ndir];
        }
        if(S=="ML"){
            dir = (dir+3)%4;
            int ndir = (dir+2)%4;
            Camera.xx = Player.xx + dx[ndir];
            Camera.yy = Player.yy + dy[ndir];
        }
        cout<<Player.xx<<' '<<Player.yy<<' '<<Camera.xx<<' '<<Camera.yy<<'\n';
    }
    return 0;
}
