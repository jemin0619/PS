//https://www.acmicpc.net/problem/31845

#include <bits/stdc++.h>
using namespace std;

int N,M; //카드 수 / 턴 수
int score=0;
deque<int> deq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>N>>M;
    while(N--){
        int x; cin>>x;
        deq.push_back(x);
    }
    sort(deq.begin(),deq.end(),greater<>());
    while(M--){
        if(deq.front()<0) break;
        score+=deq.front(); deq.pop_front();
        if(deq.empty()) break;
        deq.pop_back();
        if(deq.empty()) break;
    }
    cout<<score;
    return 0;
}
