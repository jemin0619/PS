#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

map<string, int> Mp1;
map<int, string> Mp2;

vector<int> adj1[100'003]; //정방향
vector<int> adj2[100'003]; //역방향

int main(){
    fastio;
    int N; cin>>N; 
    int idx = 1;
    for(int i=1; i<N; i++){
        string A, B; cin>>A>>B;
        if(Mp1[A]==0) {Mp1[A]=idx; Mp2[idx]=A; idx++;}
        if(Mp1[B]==0) {Mp1[B]=idx; Mp2[idx]=B; idx++;}
        adj1[Mp1[A]].push_back(Mp1[B]);
        adj2[Mp1[B]].push_back(Mp1[A]);
    }
    queue<int> Q1, Q2;
    string A, B; cin>>A>>B;
    int Anum = Mp1[A];
    int Bnum = Mp1[B];

    Q1.push(Anum);
    Q2.push(Anum);
    
    while(!Q1.empty()){
        int cur = Q1.front(); Q1.pop();
        if(Mp2[cur]==B) {cout<<1; return 0;}
        for(int nxt : adj1[cur]){
            Q1.push(nxt);
        }
    }

    while(!Q2.empty()){
        int cur = Q2.front(); Q2.pop();
        if(Mp2[cur]==B) {cout<<1; return 0;}
        for(int nxt : adj2[cur]){
            Q2.push(nxt);
        }
    }
    cout<<0;
    return 0;
}
