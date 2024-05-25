//https://www.acmicpc.net/problem/11003
//https://stonejjun.tistory.com/126

//모노톤 큐는 deque로 구현된다.
//일종의 테크닉으로 모노톤 큐를 통한 최적화가 가능하다.
//해당 코드대로 알고리즘을 짜면 덱에 원소들이 단조증가(?)하게 저장된다.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> Pll;
#define val first
#define idx second

ll N,M;
deque<Pll> deq; //val idx

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        Pll X; cin>>X.val;
        X.idx = i;
        while(!deq.empty() && deq.back().val>=X.val) deq.pop_back();
        deq.push_back(X);
        while(deq.front().idx <= i-M) deq.pop_front();
        cout<<deq.front().val<<' ';
    }
    return 0;
}
