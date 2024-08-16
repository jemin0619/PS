#include <bits/stdc++.h>
using namespace std;

int main(){
    set<string> S;
    vector<string> Job;
    vector<string> Ans;
    int N,K; 
    cin>>N;
    while(N--){
        string x; cin>>x;
        Job.push_back(x);
    }
    cin>>K;
    while(K--){
        string x; cin>>x;
        S.insert(x);
    }
    for(string val : Job){
        if(S.find(val)==S.end()){
            Ans.push_back(val);
        }
    }
    cout<<Ans.size()<<'\n';
    for(string val : Ans) cout<<val<<'\n';
    return 0;
}
