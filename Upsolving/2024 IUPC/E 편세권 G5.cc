//수많은 실패 끝에 성공했다.
//알고리즘은 일단 집 -> 편의점으로 BFS를 실행할 시 BFS를 R번 하게 되므로 시간초과가 발생함이 분명하다.
//그러므로 편의점 -> 집으로 Multi-Source BFS를 실행하면 시간복잡도를 줄이며 제한시간 내에 동작하는 코드를 작성할 수 있다.

//이때 주의할 점은 Multi-Source BFS로 집 -> 편의점까지의 최단거리를 구할 것이므로 중간에 집에 도달하더라도 탐색을 멈춰선 안된다.
//이 점을 잊어서 여러 번 틀렸었다...

//편의점을 벽이라고 생각해서 넘기려고 했는데 굳이 그럴 필요가 없었다.
//고려하지 않아도 AC를 받을 수 있다.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,ll> Pii;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

ll N,M,R,C; //R 방의수 C 편의점수
ll board[1003][1003]; //1~R은 방, R+1은 편의점
ll dist[1003][1003];
ll cost[100'0003]; //cost[1~R] 월세

ll ans = 0x7f7f7f7f;
queue<Pii> Q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(dist,-1,sizeof(dist));
    cin>>N>>M>>R>>C;
    for(int i=1;i<=R;i++){
        ll a,b,w; cin>>a>>b>>w;
        board[a][b]=i;
        cost[i]=w;
    }
    for(int i=1;i<=C;i++){
        ll a,b; cin>>a>>b;
        board[a][b]=R+1;
        Q.push({a,b});
        dist[a][b]=0;
    }
    while(!Q.empty()){
        auto[curY,curX]=Q.front(); Q.pop();
        for(int dir=0;dir<4;dir++){
            int ny = curY+dy[dir];
            int nx = curX+dx[dir];
            if(ny<1 || nx<1 || ny>N || nx>M) continue; //OOB
            if(dist[ny][nx]!=-1) continue; //방문했던곳
            dist[ny][nx]=dist[curY][curX]+1;
            if(board[ny][nx]>=1 && board[ny][nx]<=R){
                ll val = dist[ny][nx] * cost[board[ny][nx]];
                ans = min(ans,val);
            }
            Q.push({ny,nx});
        }
    }
    cout<<ans;
    return 0;
}
