//구현

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M; cin>>N>>M;
    vector<int> V(N+1, -1);
    while(M--){
        int t,i,s; cin>>t>>i>>s;
        if(s==0){ //레이스 시작 신호
            if(V[i]!=-1) {cout<<"NO"; return 0;} //레이스 시작하고 종료되기 전 새로운 레이스를 시작한 경우
            V[i] = t;
        }
        if(s==1){ //레이스 종료 신호
            if(V[i]==-1) {cout<<"NO"; return 0;} //레이스를 시작하기 전 종료한 경우
            if(t - V[i] < 60) {cout<<"NO"; return 0;} //레이스를 59초 이내에 종료한 경우
            V[i] = -1; //해당 유저 레이스 종료 처리
        }
    }
    for(int val : V){
        if(val != -1) {cout<<"NO"; return 0;}
    }
    cout<<"YES";
    return 0;
}
