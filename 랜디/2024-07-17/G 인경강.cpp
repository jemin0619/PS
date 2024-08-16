#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ff first
#define ss second

int main(){
    fastio;
    int N, M; cin>>N>>M;
    vector<int> V(M);
    for(int i=0;i<M;i++) cin>>V[i];
    vector<pair<int,int>> pre;
    for(int i=0;i<M;i++){
        V[i]/=2;
        vector<pair<int,int>> cur;
        vector<pair<int,int>> live; //살아있는(이동가능한) 부분들
        while(V[i]--){
            int st, en; cin>>st>>en;
            cur.push_back({st,en});
        }
        if(pre.empty()) pre=cur;
        else{
            for(auto c : cur){
                for(auto p : pre){
                    if((p.ff<=c.ff && c.ff<=p.ss) || (p.ff<=c.ss && c.ss<=p.ss) || (c.ff<=p.ff && p.ff<=c.ss) || (c.ff<=p.ss && p.ss<=c.ss)) {
                        live.push_back(c);
                        break;
                    }
                }
            }
            if(live.empty()) {cout<<"NO"; return 0;}
            pre.clear();
            for(auto val : live){
                pre.push_back(val);
            }
        }
    }
    cout<<"YES";
    return 0;
}
