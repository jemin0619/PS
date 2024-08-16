#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    while(1){
        int N; cin>>N;
        if(N==0) break;
        vector<string> V(N);
        queue<string> Qa;
        queue<string> Qb;
        vector<string> Ans;
        for(int i=0;i<N;i++) cin>>V[i];
        int A=N/2;
        if(N%2==1) {A=(N+1)/2;}
        for(int i=0;i<N;i++){
            if(i<A) Qa.push(V[i]);
            else Qb.push(V[i]);
        } 
        while(!Qa.empty() || !Qb.empty()){
            if(!Qa.empty()) {Ans.push_back(Qa.front()); Qa.pop();}
            if(!Qb.empty()) {Ans.push_back(Qb.front()); Qb.pop();}
        }
        for(string val : Ans) cout<<val<<'\n';
    }
    return 0;
}
