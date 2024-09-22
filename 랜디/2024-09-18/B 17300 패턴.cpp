//이런 많조분, 구현 문제가 너무 싫다

#include <bits/stdc++.h>
using namespace std;

string solve(vector<int> V){
    vector<bool> vis(V.size());
    vis[V[0]] = true;
    bool flag = true;

    for(int i=1; i<V.size(); i++){
        int nxt = V[i];
        int pre = V[i-1];
        pair<int,int> P = {min(pre, nxt), max(pre, nxt)};
        if(P==make_pair(1, 3)){
            if(!vis[2]) flag = false;
        }
        else if(P==make_pair(1, 7)){
            if(!vis[4]) flag = false;
        }
        else if(P==make_pair(1, 9)){
            if(!vis[5]) flag = false;
        }
        else if(P==make_pair(2, 8)){
            if(!vis[5]) flag = false;
        }
        else if(P==make_pair(3, 7)){
            if(!vis[5]) flag = false;
        }
        else if(P==make_pair(3, 9)){
            if(!vis[6]) flag = false;
        }
        else if(P==make_pair(4, 6)){
            if(!vis[5]) flag = false;
        }
        else if(P==make_pair(7, 9)){
            if(!vis[8]) flag = false;
        }
        else if(vis[nxt]) flag = false;

        vis[nxt] = true;

        if(!flag) break;
    }
    if(!flag) return "NO";
    return "YES";
}   

int main(){
    int N; cin>>N;
    vector<int> V(N);
    for(int i=0; i<N; i++) cin>>V[i];
    cout<<solve(V);
    return 0;
}
