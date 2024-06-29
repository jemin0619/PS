//그래프에서의 BFS로 해결 가능
//맥주를 마시면서 걸으면 최대 1000의 거리까지 이동이 가능하므로 현재 위치부터 다음 곳까지의 거리가 1000보다 작거나 같으면 이동할 수 있다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define pii pair<int,int>
#define X first
#define Y second

int main(){
    fastio;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        pii home, des;
        vector<pii> store;
        vector<bool> vis(n);
        cin>>home.X>>home.Y;
        for(int i=0;i<n;i++){
            int sx, sy; cin>>sx>>sy;
            store.push_back({sx,sy});
        }
        cin>>des.X>>des.Y;

        bool flag = false;
        queue<pii> Q;
        Q.push({home.X,home.Y});
        while(!Q.empty()){
            auto cur = Q.front();
            Q.pop();
            if(abs(cur.X-des.X)+abs(cur.Y-des.Y)<=1000) {flag=true; break;}
            for(int i=0;i<n;i++){
                if(vis[i]) continue;
                if(abs(cur.X-store[i].X)+abs(cur.Y-store[i].Y)<=1000){
                    vis[i] = true;
                    Q.push({store[i].X,store[i].Y});
                }
            }
        }
        if(flag) cout<<"happy\n";
        else cout<<"sad\n";
    }
    return 0;
}
