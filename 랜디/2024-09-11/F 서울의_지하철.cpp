#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int N, dest;
vector<int> V[13];
vector<int> st; //시작할 수 있는 호선의 번호
vector<bool> vis(13);
int ans = 0x7f7f7f7f;

void DFS(int cur, int time){

    //이전 결과보다 시간이 크면 멈춤
    if(time>=ans) return;

    //현재 호선에서 갈 수 있는 역들을 살핌
    for(int val1 : V[cur]){
        if(val1==dest){
            ans = min(ans, time);
            return;
        }

        //현재 호선의 역에서 환승해서 갈 수 있는 역들을 살핌
        for(int i=0; i<N; i++){
            if(i==cur) continue;
            for(int val2 : V[i]){
                if(!vis[i] && val2==val1){
                    vis[i] = true;
                    DFS(i, time+1);
                    vis[i] = false;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL)->sync_with_stdio(false);
    cin>>N;
    for(int i=0; i<N; i++){
        int k; cin>>k;
        while(k--){
            int x; cin>>x;
            V[i].push_back(x);
            if(x==0) st.push_back(i);
        }
    }
    cin>>dest;

    for(int val : st){
        vis[val] = true;
        DFS(val, 0);
        vis[val] = false;
    }

    if(ans==0x7f7f7f7f) cout<<-1;
    else cout<<ans;
    return 0;
}
