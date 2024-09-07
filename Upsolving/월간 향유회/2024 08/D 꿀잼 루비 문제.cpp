//모든 경우를 완탐하면 TLE를 받는다.
//내림차순 정렬 후 적당한 개수의 보석만 고려해주어야 한다.
//적당한 개수는 대충 50개 정도로 잡아도 된다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N, M, K;
vector<tuple<int,int,int>> V;
bool vis[1003][1003];
int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};

int Ans = 0;

int DFS(int depth, int sel){
    //depth==21로 주어도 통과한다
    if(depth==N*M || sel==0 || depth==50) return 0; 

    int D1 = DFS(depth+1, sel);

    auto&[val,y,x]=V[depth];
    for(int dir=0; dir<4; dir++){
        int ny=y+dy[dir];
        int nx=x+dx[dir];
        if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
        if(vis[ny][nx]) return D1;
    }

    vis[y][x] = true;
    int D2 = DFS(depth+1, sel-1) + val;
    vis[y][x] = false;

    int ret = max(D1, D2);
    return ret;
}

int main(){
    fastio;
    cin>>N>>M>>K;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int val; cin>>val;
            V.push_back({val, i, j});
        }
    }
    sort(V.rbegin(), V.rend());

    cout<<DFS(0, K);
    return 0;
}
