#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

bool OOB(int y, int x){
    if(y>=0 && y<5 && x>=0 && x<5) return false;
    else return true;
}

bool check(vector<vector<int>>&V){
    queue<pair<int,int>> Q;
    bool bingo = false;
    for(int i=0;i<5;i++){
        if(V[0][i]==0) Q.push({0,i});
        if(V[i][0]==0) Q.push({i,0});
    }
    while(!Q.empty()){
        auto&[y,x] = Q.front(); Q.pop();

        // 오른쪽으로 이동
        bingo = true;
        for(int i=1;i<=4;i++){
            int nx = x+i;
            if(OOB(y, nx)) {bingo=false; break;}
            if(V[y][nx]!=0) {bingo=false; break;}
        } if(bingo) return true;

        // 아래로 이동
        bingo = true;
        for(int i=1;i<=4;i++){
            int ny = y+i;
            if(OOB(ny, x)) {bingo=false; break;}
            if(V[ny][x]!=0) {bingo=false; break;}
        } if(bingo) return true;

        // 우측 상단
        bingo = true;
        for(int i=1;i<=4;i++){
            int nx = x+i;
            int ny = y-i;
            if(OOB(ny, nx)) {bingo=false; break;}
            if(V[ny][nx]!=0) {bingo=false; break;}
        } if(bingo) return true;
 
        // 우측 하단
        bingo = true;
        for(int i=1;i<=4;i++){
            int nx = x+i;
            int ny = y+i;
            if(OOB(ny, nx)) {bingo=false; break;}
            if(V[ny][nx]!=0) {bingo=false; break;}
        } if(bingo) return true;

        // 좌측 하단
        bingo = true;
        for(int i=1;i<=4;i++){
            int nx = x-i;
            int ny = y+i;
            if(OOB(ny, nx)) {bingo=false; break;}
            if(V[ny][nx]!=0) {bingo=false; break;}
        } if(bingo) return true;
    }
    return bingo;
}

int main(){
    fastio;
    int N; cin>>N;
    vector<string> names(N);
    vector<vector<vector<int>>> board(N, vector<vector<int>>(7, vector<int>(7)));
    for(int k=0;k<N;k++){
        cin>>names[k];
        for(int i=0;i<5;i++)
            for(int j=0;j<5;j++)
                cin>>board[k][i][j];
    }
    int M; cin>>M;
    for(int _=0;_<M;_++){
        int x; cin>>x;
        for(int k=0;k<N;k++)
            for(int i=0;i<5;i++)
                for(int j=0;j<5;j++)
                    if(board[k][i][j]==x)
                        board[k][i][j] = 0;
    }
    vector<string> Ans;
    for(int k=0;k<N;k++){
        if(check(board[k])) Ans.push_back(names[k]);
    }
    cout<<Ans.size()<<'\n';
    for(string x : Ans) cout<<x<<'\n';
    return 0;
}
