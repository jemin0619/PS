//https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV4suNtaXFEDFAUf

//Tag: Bruteforce
//N과 M 제한을 보면 아슬아슬하게 브루트포스로 돌 것 같단 직감이 들었다. (다른 방법은 안떠오름)
//BOJ에 '감시' 라는 문제와 비슷하다.
//제한이 빡빡해서 조금이라도 커팅을 해줘야 한다.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int dy[4] = {1,0,-1,0};
const int dx[4] = {0,1,0,-1};

int mxConn, mnLine;
int ans, n;
int board[103][103];
vector<pair<int,int>> v;

void f(int depth, int conn, int line){
    if(depth==v.size()){
        if(conn>mxConn) mxConn=conn, mnLine=line;
        else if(conn==mxConn) mnLine = min(mnLine, line);
        return;
    }
    for(int dir=0; dir<4; dir++){
        int count = 0;
        int curY = v[depth].first;
        int curX = v[depth].second;

        while(true){
            curY += dy[dir];
            curX += dx[dir];
            if(curY<0 || curX<0 || curY>=n || curX>=n) break;
            if(board[curY][curX]==1) {count=0; break;}
            count++;
        }

        int Ypos = v[depth].first;
        int Xpos = v[depth].second;
        for(int i=0; i<count; i++){
            Ypos += dy[dir];
            Xpos += dx[dir];
            board[Ypos][Xpos] = 1;
        }

        f(depth+1, conn+((count==0)?0:1), line+count);

        Ypos = v[depth].first;
        Xpos = v[depth].second;
        for(int i=0; i<count; i++){
            Ypos += dy[dir];
            Xpos += dx[dir];
            board[Ypos][Xpos] = 0;
        }
    }
}

void solve(int tc){
    v.clear();
    mxConn = INT_MIN;
    mnLine = INT_MAX;

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
            if(board[i][j]==0) continue;
            if(i==0 || j==0 || i==n-1 || j==n-1) continue;
            v.push_back({i,j});
        }
    }

    f(0, 0, 0);
    cout<<"#"<<tc<<' '<<mnLine<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin>>tc;
    for(int i=1; i<=tc; i++) solve(i);
    return 0;
}
