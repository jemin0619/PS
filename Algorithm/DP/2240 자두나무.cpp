//https://www.acmicpc.net/problem/2240

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

//dp[i][j][k]: i초에 j번 이동했고, k에 위치할 때 먹은 자두의 개수
int dp[1003][33][3];
int T, W;
vector<int> V;

int DFS(int time, int move, int pos){
    if(time==T) return 0;

    int&ret = dp[time][move][pos];
    if(ret!=-1) return ret;

    int D1 = DFS(time+1, move, pos);
    if(V[time]==pos) D1++;

    int D2 = 0;
    if(move<W){
        D2 = DFS(time+1, move+1, 1-pos);
        if(V[time]==1-pos) D2++;
    }

    ret = max(D1, D2);
    return ret;
}

int main(){
    fastio;
    cin>>T>>W;
    V.resize(T);
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<T;i++){
        cin>>V[i]; V[i]--;
    }
    cout<<DFS(0,0,0);
    return 0;
}
