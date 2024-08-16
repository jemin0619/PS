#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);

int N, Ans;
vector<int> parent;
vector<pair<int,int>> V;

void init(){
    parent.resize(1003);
    for(int i=1;i<=1001;i++){
        parent[i]=i;
    }
}

int find(int u){
    if(parent[u]==u) return u;
    return parent[u] = find(parent[u]);
}

bool compV(pair<int,int>&A, pair<int,int>&B){
    if(A.second==B.second) return A.first<B.first;
    return A.second>B.second;
}

int main(){
    fastio;
    cin>>N;
    init();
    for(int i=1;i<=N;i++){
        int a,b; cin>>a>>b;
        V.push_back({a,b});
    } sort(V.begin(),V.end(),compV);
    for(auto val : V){
        if(find(val.first)>=1){ //공간이 남아있다면
            int u = find(val.first);
            parent[u] = u-1;
            Ans += val.second; 
        }
    }
    cout<<Ans;
    return 0;
}
