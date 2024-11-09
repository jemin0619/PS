//대충 풀었는데 시간 내에 돌아간다.
//각 TC당 10^9로 돌아가니 괜찮긴 할텐데, 이 풀이보다는 모든 회문을 만들고 그것들 중 적은 수를 더해서 만들 수 있는 수를 고르는게 나아보인다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

string gene(int len, int num){
    string n = to_string(num);
    while(n.size()<len){
        n = "0" + n;
    }
    return n;
}

void solve(string N){
    int num = stoi(N);
    for(int i=num; i<=999999999; i++){
        string x = gene(N.size(), i);
        
        int idx = 0;
        while(idx<x.size()/2 && x[idx]==x[x.size()-1-idx]) idx++;
        if(idx==x.size()/2){
            cout<<i-num<<'\n';
            return;
        }

    }
}   

int main(){
    fastio;
    while(true){
        string N; cin>>N;
        if(N=="0") break;
        solve(N);
    }
    return 0;
}
