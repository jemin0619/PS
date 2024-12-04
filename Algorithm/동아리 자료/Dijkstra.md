# Dijkstra
### - 다익스트라
[문제집 링크](https://www.acmicpc.net/group/workbook/view/20184/75143)

풀이마다 최단거리를 저장하는 배열 이름을 dp로 지었는데, 다익스트라는 dp보단 greedy라고 볼 수 있어서 조금 불편할 수도 있을 것 같습니다...

***

[1916 최소비용 구하기 G5](https://www.acmicpc.net/problem/1916)

가장 기본적인 다익스트라 문제입니다.
```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define pii pair<ll,ll>

int main(){
    fastio;
    int N,M; cin>>N>>M;
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    vector<vector<pii>> adj(N+1);
    vector<ll> dp(N+1, LLONG_MAX);
    while(M--){
        ll u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
    }
    int st, en; cin>>st>>en;
    dp[st] = 0;
    PQ.push({dp[st], st});
    while(!PQ.empty()){
        auto[curW, curN] = PQ.top(); PQ.pop();
        if(dp[curN] != curW) continue;
        for(auto[nxtN, nxtW] : adj[curN]){
            if(dp[nxtN] <= dp[curN]+nxtW) continue;
            dp[nxtN] = dp[curN]+nxtW;
            PQ.push({dp[nxtN], nxtN});
        }
    }
    cout<<dp[en];
    return 0;
}
```

***

[1753 최단경로 G4](https://www.acmicpc.net/problem/1753)

우선순위 큐에 시작점만 넣고, dp 배열을 채워가면 됩니다.
***

[1504 특정한 최단 경로 G4](https://www.acmicpc.net/problem/1504)

중간에 거쳐야 하는 두 지점을 A, B로, 시작과 끝을 st, en이라 할 때, 최단경로는 다음과 같습니다. 

min(st - A - B - en, st - B - A - en)
***

[1261 알고스팟 G4](https://www.acmicpc.net/problem/1261) 

상하좌우로 이동하면서 1인 공간은 가중치가 1이고, 0이면 가중치를 0으로 쳐서 다익스트라를 돌려주면 됩니다.

가중치가 0과 1인 것을 이용한 0-1 BFS 풀이도 가능합니다.
***

[11779 최소비용 구하기 2](https://www.acmicpc.net/problem/11779) 

경로 역추적을 해야 합니다. pre 배열을 만들면 간단하게 해결 가능합니다.
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> Pii;
#define X first //가중치
#define Y second //노드 번호

const int INF = 1e9 + 10;
int N,M; //정점수 간선수
int d[1003]; //최단거리 배열
int pre[1003]; //경로복원 배열
vector<Pii> adj[1003]; //그래프
priority_queue<Pii,vector<Pii>,greater<Pii>> PQ;
int st, en;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N>>M;
    fill(d,d+N+1,INF);
    while(M--){
        int u, v, w; cin>>u>>v>>w;
        adj[u].push_back({w,v});
    }
    cin>>st>>en;
    d[st]=0; PQ.push({d[st],st});
    while(!PQ.empty()){
        auto[cur_Weight, cur_Node]=PQ.top(); PQ.pop();
        if(cur_Weight != d[cur_Node]) continue; //st에서 길이가 정해진 가중치와 다른 경우 넘어감
        for(auto[nxt_Weight, nxt_Node] : adj[cur_Node]){
            if(d[nxt_Node]<=d[cur_Node]+nxt_Weight) continue;
            d[nxt_Node]=d[cur_Node]+nxt_Weight;
            PQ.push({d[nxt_Node],nxt_Node});
            pre[nxt_Node] = cur_Node;
        }
    }
    cout<<d[en]<<'\n';

    //경로 역추적 (en에서부터 시작)
    vector<int> path;
    int cur = en;
    while(st!=cur){
        path.push_back(cur);
        cur = pre[cur];
    } path.push_back(st);
    reverse(path.begin(),path.end());
    cout<<path.size()<<'\n';
    for(int x : path) cout<<x<<' ';
    return 0;
}
```
***

[1238 파티 G3](https://www.acmicpc.net/problem/1238)

단방향 도로이기에, 모든 정점 i에 대해 다익스트라를 돌리면서 (i - X - i)의 최단거리를 구해주면 됩니다.

[i에서 X로 가는 최단거리 + X에서 i로 가는 최단거리]를 해야 하기에 다익스트라를 두 번 돌려야 합니다.
***

[31230 모비스터디 G3](https://www.acmicpc.net/problem/31230)

최단경로 역추적...도 가능하겠지만 굉장히 복잡해보인다.
```cpp
//A -> i -> B 의 최단경로가 A -> B의 최단경로와 같다면 i는 최단경로에 속하는 것이라 판단할 수 있다.
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define pii pair<ll,ll>

void Dijkstra(vector<ll>&dp, vector<vector<pii>>&adj, int st){
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    dp[st] = 0;
    PQ.push({dp[st], st});
    while(!PQ.empty()){
        auto[curW, curN] = PQ.top(); PQ.pop();
        if(dp[curN]!=curW) continue;
        for(auto[nxtN, nxtW] : adj[curN]){
            if(dp[nxtN]<=dp[curN]+nxtW) continue;
            dp[nxtN] = dp[curN] + nxtW;
            PQ.push({dp[nxtN], nxtN});
        }
    }
}

int main(){
    fastio;
    int N,M,A,B; cin>>N>>M>>A>>B;
    vector<ll> dpA(N+1, LLONG_MAX);
    vector<ll> dpB(N+1, LLONG_MAX);
    vector<vector<pii>> adj(N+1);
    while(M--){
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    Dijkstra(dpA, adj, A);
    Dijkstra(dpB, adj, B);
    vector<int> ans;
    for(int i=1; i<=N; i++){
        if(dpA[i]+dpB[i]==dpA[B]){
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<'\n';
    for(int val : ans) cout<<val<<' ';
    return 0;
}
```
***

[23030 후다다닥을 이겨 츄르를 받자! G3](https://www.acmicpc.net/problem/23030)

N, M이 작아서 별다른 테크닉 없이 쿼리마다 다익스트라를 돌려주면 된다.
```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define tiii tuple<ll,ll,ll>

int N, M, K;
vector<vector<vector<tiii>>> adj; //adj[i][j] : i번 노선의 j번 역에서 갈 수 있는 공간 [가중치, 노선, 역]

int Dijkstra(ll T, int u1, int u2, int v1, int v2){
    priority_queue<tiii, vector<tiii>, greater<tiii>> PQ;
    vector<vector<ll>> dp(11, vector<ll>(51, 0x7f7f7f7f));
    dp[u1][u2] = 0;
    PQ.push({dp[u1][u2], u1, u2});
    while(!PQ.empty()){
        auto[curW, curR, curS] = PQ.top(); PQ.pop();
        if(dp[curR][curS]!=curW) continue;
        for(auto[nxtW, nxtR, nxtS] : adj[curR][curS]){
            if(nxtW==1) nxtW = T;
            else nxtW = 1;
            if(dp[nxtR][nxtS]<=dp[curR][curS]+nxtW) continue;
            dp[nxtR][nxtS] = dp[curR][curS] + nxtW;
            PQ.push({dp[nxtR][nxtS], nxtR, nxtS});
        }
    }
    return dp[v1][v2];
}

int main(){
    fastio;
    cin>>N;
    adj.resize(N+1);
    for(int i=1; i<=N; i++){
        ll sz; cin>>sz;
        adj[i].resize(sz+1);
        for(int j=1; j<=sz-1; j++){
            adj[i][j].push_back({0, i, j+1});
            adj[i][j+1].push_back({0, i, j});
        }
    }
    cin>>M;
    for(int i=1; i<=M; i++){
        ll p1,p2,q1,q2; cin>>p1>>p2>>q1>>q2;
        adj[p1][p2].push_back({1, q1, q2});
        adj[q1][q2].push_back({1, p1, p2});
    }
    cin>>K;
    while(K--){
        ll T, u1, u2, v1, v2; cin>>T>>u1>>u2>>v1>>v2;
        cout<<Dijkstra(T, u1, u2, v1, v2)<<'\n';
    }
    return 0;
}
```
***

[20183 골목 대장 호석 - 효율성 2 G2](https://www.acmicpc.net/problem/20183)

굉장히 재밌는 문제입니다. C원으로 목적지까지 도달하려고 하는데, 이때 한 골목에서 내는 최대 요금을 최소화해야 합니다.

가장 직관적인 풀이로는 매개변수 탐색이 있습니다. 최대 요금에 대해 매개변수 탐색을 돌려서 다익스트라에서 해당 값보다 가중치가 큰 간선을 무시하게 구현하면 무난하게 해결이 가능합니다. 

다익스트라 한 번으로도 가능하다고 하지만 굳이 싶습니다...
***

[17835 면접보는 승범이네 G2](https://www.acmicpc.net/problem/17835)

약간의 머리를 써야 합니다.

Multi - Source BFS처럼 우선순위 큐에 면접장 후보를 모두 넣어준 뒤, 다익스트라를 돌립니다.

이후 가장 먼 곳을 골라서 출력하면 됩니다.
***

[22255 호석사우루스 G2](https://www.acmicpc.net/problem/22255)

BFS에 약하시면 조금 어려울 수 있습니다.

최단거리 배열을 3차원으로 만들어 어느 시점에 접근했는지까지 저장해줘야 합니다.

주기가 3이므로 0, 1, 2까지의 정보만 담으면 되므로 큰 메모리를 요구하지 않습니다.
```cpp
//그냥 일반적인 BFS 문제에서 최단거리를 구하기 위해 다익스트라를 적용시킨 모습이다.
//각 칸에 대해서 좌표 이외에도 어느 시점에 도달했는지까지 정보를 추가해서 처리해야 한다.
//횡단보도를 푼 상태여서 접근이 쉬웠다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

const int dy[4] = {0,1,0,-1};
const int dx[4] = {1,0,-1,0};

int N, M, stY, stX, enY, enX;
vector<vector<int>> board;
vector<vector<vector<int>>> dp;

int main(){
    fastio;
    cin>>N>>M>>stY>>stX>>enY>>enX;
    stY--; stX--; enY--; enX--;
    board.resize(N, vector<int>(M));
    dp.resize(N, vector<vector<int>>(M, vector<int>(3, 0x7f7f7f7f)));
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin>>board[i][j];
    priority_queue<tuple<int,int,int,int>, vector<tuple<int,int,int,int>>, greater<tuple<int,int,int,int>>> PQ;
    dp[stY][stX][1] = 0;
    PQ.push({dp[stY][stX][1], stY, stX, 1});
    while(!PQ.empty()){
        auto[curW, curY, curX, curT] = PQ.top(); PQ.pop();
        //cout<<curW<<' '<<curY<<' '<<curX<<' '<<curT<<'\n';
        if(dp[curY][curX][curT] != curW) continue;
        for(int dir=0; dir<4; dir++){
            if(curT==1 && dir%2==0) continue;
            if(curT==2 && dir%2==1) continue;
            int ny = curY + dy[dir];
            int nx = curX + dx[dir];
            int nT = (curT+1)%3;
            if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
            if(board[ny][nx]==-1) continue;
            if(dp[ny][nx][nT]<=curW+board[ny][nx]) continue;
            dp[ny][nx][nT] = curW + board[ny][nx];
            PQ.push({dp[ny][nx][nT], ny, nx, nT});
        }
    }
    int mnVal = 0x7f7f7f7f;
    for(int i=0; i<3; i++) mnVal = min(mnVal, dp[enY][enX][i]);
    if(mnVal == 0x7f7f7f7f) cout<<-1;
    else cout<<mnVal;
    return 0;   
}
```
***

[32294 수열과 개구리 G2](https://www.acmicpc.net/problem/32294)

1 ~ N 외에 "벗어낫다" 라고 정의할 수 있는 공간을 0, N+1로 놓습니다.

이후 0, N+1에서 각각 다익스트라를 진행하고, 둘 중 더 빠른 값을 선택하면 됩니다.
***

[24042 횡단보도 G1](https://www.acmicpc.net/problem/24042)

과거에 모듈러 연산을 사용한 깔끔한 풀이를 보고 '어렵다'는 생각을 하고 넘겼는데, 지금 풀어보니 되게 재밌는 문제였습니다.

'주기'라는 개념이 들어가 있어 복잡하게 느껴질 수 있지만, 현재 주기에 건널 수 있는지, 다음 번 주기가 되어야 건널 수 있는지를 구분해서 가중치를 잘 구해준다면 쉽게 해결 가능합니다.
```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define pii pair<ll,ll>
#define ll long long

int N, M;
vector<vector<pii>> adj;

ll Dijkstra(int st, int en){
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    vector<ll> dp(N+1, LLONG_MAX);
    dp[st] = 0;
    PQ.push({dp[st], st});
    while(!PQ.empty()){
        auto[curW, curN] = PQ.top(); PQ.pop();
        if(dp[curN] != curW) continue;
        for(auto[nxtW, nxtN] : adj[curN]){
            ll x = curW % M, nw;
            if(nxtW >= x) nw = nxtW - x; //이번 주기에 넘어갈 수 있다면
            else nw = M + nxtW - x; //다음 주기에서야 넘어갈 수 있다면
            nw += 1; //지나는데 1분 소요됨
            if(dp[nxtN] <= dp[curN] + nw) continue;
            dp[nxtN] = dp[curN] + nw;
            PQ.push({dp[nxtN], nxtN});
        }
    }
    return dp[en];
}

int main(){
    fastio;
    cin>>N>>M;
    adj.resize(N+1);
    for(int i=0; i<M; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back({i, v});
        adj[v].push_back({i, u});
    }
    cout<<Dijkstra(1, N);
    return 0;
}
```
***

[1162 도로포장 P5](https://www.acmicpc.net/problem/1162)

24.11.29 기준 P5인데, 그 정도는 아닌 것 같습니다. G2~G1 사이 정도?

최단 거리 배열을 [노드][남은 포장 횟수] 로 놓은 뒤, 답을 찾아주면 쉽게 AC를 받을 수 있습니다.
```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define pii pair<ll,ll>
#define tiii tuple<ll,ll,ll>

int main(){
    fastio;
    int N, M, K; cin>>N>>M>>K;
    vector<vector<pii>> adj(N+1);
    while(M--){
        ll u,v,w; cin>>u>>v>>w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    priority_queue<tiii, vector<tiii>, greater<tiii>> PQ;
    vector<vector<ll>> dp(N+1, vector<ll>(K+1, LLONG_MAX));
    dp[1][K] = 0;
    PQ.push({dp[1][K], 1, K});
    while(!PQ.empty()){
        auto[curW, curN, curK] = PQ.top(); PQ.pop();
        if(dp[curN][curK]!=curW) continue;
        for(auto[nxtW, nxtN] : adj[curN]){
            if(curK>0 && dp[nxtN][curK-1] > curW){
                dp[nxtN][curK-1] = curW;
                PQ.push({dp[nxtN][curK-1], nxtN, curK-1});
            }
            if(dp[nxtN][curK] > curW+nxtW){
                dp[nxtN][curK] = curW + nxtW;
                PQ.push({dp[nxtN][curK], nxtN, curK});
            }
        }
    }
    
    //dp[N][0]이 항상 답인 것은 아니다.
    ll mnVal = LLONG_MAX;
    for(int i=0; i<=K; i++) mnVal = min(mnVal, dp[N][i]);
    cout<<mnVal;
    return 0;
}
```
***

[13308 주유소 P5](https://www.acmicpc.net/problem/13308)

다익스트라도 BFS처럼 특정 노드에 최초로 도달한 시점의 거리가 최단거리입니다.

dp[노드][가는 길에서 가장 싼 기름값] 으로 놓으면 풀 수 있습니다.
```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define pii pair<ll,ll>
#define tiii tuple<ll,ll,ll>

ll N, M;
vector<ll> oil;
vector<vector<pii>> adj;
vector<vector<ll>> dp;
priority_queue<tiii, vector<tiii>, greater<tiii>> PQ;

int main(){
    fastio;
    cin>>N>>M;
    oil.resize(N+1);
    adj.resize(N+1);
    ll mxOil = -1;
    for(int i=1; i<=N; i++){
        cin>>oil[i];
        mxOil = max(mxOil, oil[i]);
    }
    while(M--){
        ll u,v,w; cin>>u>>v>>w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    dp.resize(N+1, vector<ll>(mxOil+1, LLONG_MAX));
    dp[1][oil[1]] = 0;
    PQ.push({dp[1][oil[1]], 1, oil[1]});

    while(!PQ.empty()){
        auto[curW, curN, curOil] = PQ.top(); PQ.pop();
        if(curN==N){ //다익스트라도 BFS 마냥 노드에 처음 도달할 때가 가장 빠른 도달 시점이기 때문에 이래도 됨
            cout<<curW;
            return 0;
        }
        if(dp[curN][curOil]!=curW) continue;
        for(auto[nxtW, nxtN] : adj[curN]){
            ll x = curOil * nxtW; //당장 다음까지 이동하는데 필요한 최소 비용
            ll nxtOil = min(curOil, oil[nxtN]);
            if(dp[nxtN][nxtOil]<=curW+x) continue;
            dp[nxtN][nxtOil] = curW+x;
            PQ.push({dp[nxtN][nxtOil], nxtN, nxtOil});
        }
    }
    return 0;
}
```
***

[5719 거의 최단 경로 P5](https://www.acmicpc.net/problem/5719)

[31230 모비스터디 G3](https://www.acmicpc.net/problem/31230)에서는 특정 노드가 최단거리에 속하는지 판별했다면, 이 문제에서는 특정 간선이 최단거리에 속하는지 판별해줘야 합니다. 이것이 귀찮다면 단순 구현으로 처리해야 하는데, 간선을 지우는 과정이 굉장히 지루하고 복잡하기에 이 풀이가 정해에 가깝다고 생각합니다. 

시작점과 끝점에서 각각 다익스트라를 돌리고 그 결과를 dp1, dp2에 저장했을 때 각 간선의 정보를 [nxtN, nxtW]로 놓으면, dp1[curN] + nxtW + dp2[nxtN] == dp1[en]이면 해당 간선은 최단거리에 속한 것으로 판단할 수 있습니다.
```cpp
//31230 모비스터디 G3에 쓰인 '특정 노드가 최단거리에 속하는지를 검출할 때 사용한 테크닉'을 간선에 적용시킨다.

//dp1: S를 시작점으로 돌린 다익스트라 결과 배열
//dp2: D를 시작점으로 돌린 다익스트라 결과 배열
//dp1[cur] + curW + dp2[nxt] == dp1[D](=dp2[S]) 가 true면 그 간선은 최단거리에 쓰인 간선이기에 사용 불가능.

//dp3: S를 시작점으로 돌린 다익스트라 결과 배열. (단, 최단거리에 사용된 간선을 제외한 상태로 돌림)

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define pii pair<int,int>

void Dijkstra(vector<vector<pii>>&adj, vector<int>&dp, int st){
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    dp[st] = 0;
    PQ.push({dp[st], st});
    while(!PQ.empty()){
        auto[curW, curN] = PQ.top(); PQ.pop();
        if(dp[curN]!=curW) continue;
        for(auto[nxtW, nxtN] : adj[curN]){
            if(dp[nxtN]<=dp[curN]+nxtW) continue;
            dp[nxtN] = dp[curN] + nxtW;
            PQ.push({dp[nxtN], nxtN});
        }   
    }
}

bool solve(){
    int N, M; cin>>N>>M;
    if(N==0 && M==0) return false;
    int S,D; cin>>S>>D;
    vector<vector<pii>> adj(N+1), rev(N+1);
    vector<int> dp1(N+1, 0x7f7f7f7f), dp2(N+1, 0x7f7f7f7f), dp3(N+1, 0x7f7f7f7f);
    while(M--){
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({w, v});
        rev[v].push_back({w, u});
    }
    Dijkstra(adj, dp1, S);
    Dijkstra(rev, dp2, D);
    
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    dp3[S] = 0;
    PQ.push({dp3[S], S});
    while(!PQ.empty()){
        auto[curW, curN] = PQ.top(); PQ.pop();
        if(dp3[curN]!=curW) continue;
        for(auto[nxtW, nxtN] : adj[curN]){
            if(dp1[curN] + nxtW + dp2[nxtN] == dp1[D]) continue; //현재 간선이 최단거리에 속한 경우
            if(dp3[nxtN]<=dp3[curN]+nxtW) continue;
            dp3[nxtN] = dp3[curN] + nxtW;
            PQ.push({dp3[nxtN], nxtN});
        }   
    }
    if(dp3[D]==0x7f7f7f7f) cout<<-1<<'\n';
    else cout<<dp3[D]<<'\n';
    return true;
}

int main(){
    fastio;
    while(solve());
    return 0;
}
```
***

[1854 K번째 최단경로 찾기 P4](https://www.acmicpc.net/problem/1854)

다익스트라 알고리즘에 대한 높은 이해도가 요구됩니다.

노드에 K번째 도달했을 때의 값이 K번째 최단경로의 길이가 됩니다.

이를 위해 우선순위 큐를 노드마다 만들어, K번째 최단경로를 저장해줍니다.
```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define pii pair<int,int>

int N,M,K;
vector<vector<pii>> adj;
vector<priority_queue<int>> kth_PQ;

void Dijkstra(){
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    kth_PQ[1].push(0);
    PQ.push({0, 1});
    while(!PQ.empty()){
        auto[curW, curN] = PQ.top(); PQ.pop();
        for(auto[nxtW, nxtN] : adj[curN]){
            //아직 K회보다 적게 방문했으면 무조건 추가해줘야됨
            if(kth_PQ[nxtN].size() < K){
                kth_PQ[nxtN].push(curW + nxtW);
                PQ.push({curW+nxtW, nxtN});
            }

            //K회 방문한 상태면 K번째 값을 최대한 작은 값으로 갱신해줌
            else if(kth_PQ[nxtN].top() > curW+nxtW){
                kth_PQ[nxtN].pop();
                kth_PQ[nxtN].push({curW+nxtW});
                PQ.push({curW+nxtW, nxtN});
            }
        }
    }
}

int main(){
    fastio;
    cin>>N>>M>>K;
    adj.resize(N+1);
    kth_PQ.resize(N+1);
    while(M--){
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({w, v});
    }
    
    Dijkstra();

    for(int i=1; i<=N; i++){
        if(kth_PQ[i].size() < K) cout<<-1<<'\n';
        else cout<<kth_PQ[i].top()<<'\n';
    }
    return 0;
}
```
***

[9376 탈옥 P4](https://www.acmicpc.net/problem/9376)

다익스트라를 3번 돌립니다.

외부에서 한 번, $ 각각 한 번.

이후 각각의 dist 배열을 모두 합치고, #인 부분은 -2를 해줍니다.

격자에서 가장 작은 값이 답이 됩니다.

***

[13907 세금 P4](https://www.acmicpc.net/problem/13907)

dp[i][j] : i번째 노드까지 j개의 간선을 써서 도달하는 최소 비용

N이 1000으로 작아서, K개의 쿼리를 처리할 때, O(NK)로 처리해줄 수 있습니다.

또, 커팅으로 실행시간을 크게 단축할 수 있었습니다...!
```cpp
//커팅 X -> 1000ms
//커팅 O -> 20ms ~ 16ms
//왜 이렇게 오래 걸리는지 한참동안 찾았습니다...

//visited 배열을 통해 해당 노드까지 도달하는데 필요한 가장 작은 간선 수를 저장합니다. (정정: 가장 작으면서 비용도 가장 적은 간선 수.)
//이후 노드에 방문했을 때, visited 값이 현재 노드에 오는데 사용한 간선 수보다 적다면 커팅해줍니다.
//간선 수가 최소 간선 수보다 많으면 무조건 비효율적이기 때문입니다... (세금이 minus가 아니기 때문)

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define pii pair<int,int>
#define tiii tuple<int,int,int>

int N,M,K;
int st, en;
vector<vector<pii>> adj;
vector<vector<int>> dp; //dp[i][j] : i번 노드에 j개의 간선을 거쳐 도달한 최소 비용
vector<int> P, visited;

int main(){
    fastio;
    cin>>N>>M>>K>>st>>en;
    adj.resize(N+1);
    P.resize(K+1, 0);
    visited.resize(N+1, 0x7f7f7f7f);
    dp.resize(N+1, vector<int>(N+1, 0x7f7f7f7f));
    while(M--){
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    for(int i=1; i<=K; i++) cin>>P[i];

    priority_queue<tiii, vector<tiii>, greater<tiii>> PQ;
    dp[st][0] = 0;
    PQ.push({dp[st][0], st, 0});
    while(!PQ.empty()){
        auto[curW, curN, curE] = PQ.top(); PQ.pop();
        if(dp[curN][curE]!=curW) continue;
        if(curE==N) continue;
        if(visited[curN] >= 0x7f7f7f7f) visited[curN] = curE;
        for(auto[nxtW, nxtN] : adj[curN]){
            if(visited[nxtN] <= curE+1) continue; //이 부분에서 커팅을 해줘야 20ms에 풀린다.
            if(dp[nxtN][curE+1]<=curW+nxtW) continue;
            dp[nxtN][curE+1] = curW + nxtW;
            PQ.push({dp[nxtN][curE+1], nxtN, curE+1});
        }
    }

    for(auto val : P){
        int ans = 0x7f7f7f7f;
        for(int i=0; i<=visited[en]; i++){
            if(dp[en][i]==0x7f7f7f7f) continue;
            dp[en][i] += val*i;
            ans = min(ans, dp[en][i]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
```

***

[22870 산책 (large) P4](https://www.acmicpc.net/problem/22870)

통곡의 벽입니다... 

S -> E 돌리고, 경로 역추적하면서 사용한 정점 지우고, 그 상태로 E -> S 돌려서 두 최단경로 더해서 출력하면 될 것 같지만, '오름차순' 때문에 AC를 받기가 쉽지 않습니다.

다음의 TC를 통해 코드가 제대로 '오름차순' 의 경로를 골랐는지 확인할 수 있습니다.

```
6 15
1 2 1
1 3 2
1 4 3
1 5 4
1 6 6
2 3 1
2 4 2
2 5 3
2 6 4
3 4 1
3 5 2
3 6 3
4 5 1
4 6 2
5 6 1
1 6

1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 최단경로 -> 1
```

S -> E에서만 오름차순 조건을 고려해주면 E -> S에선 굳이 할 필요가 없습니다.

E -> S에선 최단경로만 얻으면 되기 때문입니다.

오름차순 조건을 고려해서 사용한 정점들을 제거해주기 위해 BFS를 돌려주면서 역추적 배열을 채운 뒤, 역추적을 통해 사용한 정점들을 찾고 삭제합니다.

맞는 것 같은데 끝까지 안풀려서 너무 힘든 문제였습니다...

```cpp
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define pii pair<ll,ll>

vector<vector<pii>> adj;
vector<ll> dp1, dp2;
set<int> vis;

void Dijkstra(vector<ll>&dp, int st, int en, set<int> S){
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    dp[st] = 0;
    PQ.push({dp[st], st});
    while(!PQ.empty()){
        auto[curW, curN] = PQ.top(); PQ.pop();
        if(dp[curN]<curW) continue;
        for(auto[nxtW, nxtN] : adj[curN]){
            if(S.find(nxtN)!=S.end()) continue; //사용한 적 있는 노드면
            if(dp[nxtN]<=curW+nxtW) continue;
            dp[nxtN] = curW + nxtW;
            PQ.push({dp[nxtN], nxtN});
        }
    }
}

void trace(int N, int st, int en){
    queue<int> Q;
    vector<int> nxt(N+1, 0x7f7f7f7f);
    Q.push(en);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(auto[preW, preN] : adj[cur]){
            if(dp1[cur]==dp1[preN]+preW && nxt[preN]>cur){
                nxt[preN] = cur;
                Q.push(preN);
            }
        }
    }

    int node = st;
    while(node != en){
        node = nxt[node];
        vis.insert(node);
    }
}

int main(){
    fastio;
    int N, M; cin>>N>>M;
    adj.resize(N+1);
    dp1.resize(N+1, LLONG_MAX);
    dp2.resize(N+1, LLONG_MAX);
    while(M--){
        ll u,v,w; cin>>u>>v>>w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    int S, E; cin>>S>>E;

    Dijkstra(dp1, S, E, {});
    
    trace(N, S, E);

    Dijkstra(dp2, E, S, vis);

    cout<<dp1[E] + dp2[S];
    return 0;
}
```

***

[28354 링크 컷 토마토 P4](https://www.acmicpc.net/problem/28354)

간선의 추가/삭제와 시간 순 처리를 잘 해줘야 하는 문제입니다.

간선 처리는 간선 저장시에 간선이 존재하는 구간을 같이 저장해줘서 처리 가능하고, 시간 순으로 처리하는 것은 우선순위 큐를 써주면 됩니다.

그렇기에 다익스트라로 해결할 수 있습니다.
```cpp
//시간 순으로 처리만 잘 해준다면 BFS로도 처리할 수 있다.
//매 삽입마다 시간 순 정렬이 유지되는 우선순위 큐로 다익스트라를 돌린다면, 더욱 깔끔해진다.

//간선이 추가되고, 사라지는 것의 처리는 간선을 저장할 때, 존재하는 구간을 같이 저장함으로써 처리 가능하다.
//코드에서는 {st, en, Node} 식으로 저장해주었다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define pii pair<ll,ll>
#define tiii tuple<ll,ll,ll>

int N,M,K,Q;
map<pii, int> Mp;
vector<vector<tiii>> adj;
vector<ll> dp; 
priority_queue<pii, vector<pii>, greater<pii>> PQ;

int main(){
    fastio;
    cin>>N>>M>>K>>Q;
    adj.resize(N+1);
    dp.resize(N+1, LLONG_MAX);
    while(M--){
        int u,v; cin>>u>>v;
        Mp[{u,v}] = 0;
    }
    while(K--){
        ll x; cin>>x;
        dp[x] = 0;
        PQ.push({dp[x], x});
    }
    while(Q--){
        ll t,u,v; cin>>t>>u>>v;
        auto it = Mp.find({u,v});
        if(it!=Mp.end()){ 
            //t,u,v 쌍이 모두 다르게 들어온다고 하므로, u,v 쌍은 겹칠 수 있다.
            //그러므로 Mp[{u,v}]를 push 해줘야 올바르게 동작한다. (안하면 7% WA)
            adj[u].push_back({Mp[{u,v}], t-1, v});
            adj[v].push_back({Mp[{u,v}], t-1, u});
            Mp.erase(it);
        }
        else Mp[{u,v}] = t;
    }
    for(auto[key, st] : Mp){
        auto[u,v] = key;
        adj[u].push_back({st, LLONG_MAX, v});
        adj[v].push_back({st, LLONG_MAX, u});
    }
    while(!PQ.empty()){
        auto[curW, curN] = PQ.top(); PQ.pop();
        if(dp[curN]!=curW) continue;
        for(auto[st, en, nxtN] : adj[curN]){
            if(curW > en) continue; //나중에 연결되지 않으면, 건너뛰어야됨
            if(dp[nxtN]<=max(st, curW)+1) continue;
            dp[nxtN] = max(st, curW) + 1;
            PQ.push({dp[nxtN], nxtN}); 
        }
    }
    for(int i=1; i<=N; i++) cout<<((dp[i]==LLONG_MAX)?-1:dp[i])<<' ';
    return 0;
}
```
***

[1848 동굴 탐험 D5](https://www.acmicpc.net/problem/1848)

***

[18193 비행기 타고 가요 D3](https://www.acmicpc.net/problem/18193)

***
