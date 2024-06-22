//벌집 모양에서 BFS로 Flood Fill

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

ll K,N,M;
char board[1003][1003];
bool vis[1003][1003];
vector<ll> V;
ll dy[6] = {0,1,1,0,-1,-1};
ll dx[2][6] = {{-1,-1,0,1,0,-1},{-1,0,1,1,1,0}};

int main(){
    fastio;
    cin>>K>>N>>M;
    if(K==0) {cout<<0; return 0;}
  
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>board[i][j];
  
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(vis[i][j]) continue;
            if(board[i][j]=='#') continue;
            
            ll sz=1;
            queue<pair<ll,ll>> Q;
            Q.push({i,j}); vis[i][j]=true;

            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int dir=0;dir<6;dir++){
                    ll ny = cur.first + dy[dir];
                    ll nx = cur.second + dx[cur.first%2][dir];
                    if(ny<0 || nx<0 || ny>=N || nx>=M) continue; //OOB
                    if(vis[ny][nx]) continue;
                    if(board[ny][nx]=='#') continue;
                    Q.push({ny,nx}); vis[ny][nx]=true;
                    sz++;
                }
            }
            V.push_back(sz);
        }
    }
  
    sort(V.begin(),V.end(),greater<>());
    partial_sum(V.begin(),V.end(),V.begin());

    //K보다 작은가
    //TTFF -> F 출력
    ll lo=-1, hi=V.size(); //K==0인 경우를 이미 처리해서 lo 바꿔도 AC 받을 수 있을 듯
    while(lo+1<hi){
        ll mid = (lo+hi)/2;
        if(V[mid]<K) lo=mid;
        else hi=mid;
    }
    if(hi>=V.size()) cout<<V.size();
    else cout<<hi+1;

    return 0;
}
