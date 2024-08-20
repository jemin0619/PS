//구현력 이슈
//트리를 만들고, BFS, DFS 돌리기

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> adj[5003];
bool block[5003][5003];
ll D,N,U,T; 

ll pony_last = 0;

ll pony_Ans = 0;
ll twin_Ans = 0;

void twin(){ //BFS
    queue<tuple<ll,ll,ll>> Q;
    Q.push({1,0,0});
    while(!Q.empty()){
        auto[cur, cnt, time] = Q.front(); Q.pop();
        twin_Ans = max(twin_Ans, time);
        
        int x = 0;
        for(int nxt : adj[cur]){
            if(block[cur][nxt]) continue;
            x++;
        }

        int ncnt = cnt;
        if(x==2) ncnt = cnt+1;
        ll ntime = time + U + ncnt*T;

        for(int nxt : adj[cur]){
            if(block[cur][nxt]) continue;
            Q.push({nxt, ncnt, ntime});
        }
    }
}

void pony(ll cur){ //전위, 후위순회
    pony_Ans += U;
    pony_last = cur;
    for(int nxt : adj[cur]){
        if(block[cur][nxt]) continue;
        pony(nxt);
        pony_Ans += U;
    }
}

ll get_sum(ll cur){ //pony에서 마지막까지 탐색하고 올라오는 부분 삭제
    ll ret = 0;
    while(1){
        if(cur==1) break;
        ret += U;
        cur = cur/2;
    }
    ret += U;
    return ret;
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    cin>>D>>N>>U>>T;
    for(int i=0; i<N; i++){
        ll st, en; cin>>st>>en;
        block[st][en] = true;
    }

    for(int i=2; i<=(1<<D)-1; i++){
        ll u = i/2; ll v = i;
        adj[i/2].push_back(i);
    }

    twin();
    pony(1);
    pony_Ans -= get_sum(pony_last);

    if(twin_Ans > pony_Ans) cout<<":blob_twintail_sad:";
    if(twin_Ans < pony_Ans) cout<<":blob_twintail_aww:";
    if(twin_Ans == pony_Ans) cout<<":blob_twintail_thinking:";
    return 0;
}
