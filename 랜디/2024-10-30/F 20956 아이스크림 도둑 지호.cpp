/*
value 기준으로 정렬한다.
이후 deque에 정렬한 배열에서 가장 큰 값과 같은 값을 갖는 원소들을 모두 삽입한다.
기본적으론 앞에서부터 원소들을 제거해나간다. (같은 값이면 왼쪽부터라고 문제에 제시됨)
그러다가 7의 배수인 원소를 제거하게 되면, 뒤에서부터 원소를 제거해나가면 된다. (뒤집어졌기 때문)
구현은 간단하다.
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
using ll = long long;
using pii = pair<ll,ll>;

int main(){
    fastio;
    int N, M; cin>>N>>M;
    vector<pii> V(N);
    for(int i=0; i<N; i++){
        ll val; cin>>val;
        V[i] = {val, -(i+1)};
    }
    sort(V.begin(), V.end());
    deque<pii> deq;
    bool flag = false;
    while(M--){
        if(deq.empty()){
            int val = V.back().first;
            while(!V.empty() && V.back().first==val){
                deq.push_back(V.back());
                V.pop_back();
            }
        }
        if(!flag){
            auto[val, idx] = deq.front();
            cout<<-idx<<'\n';
            if(val%7==0) flag=!flag;
            deq.pop_front();
        }
        else{
            auto[val, idx] = deq.back();
            cout<<-idx<<'\n';
            if(val%7==0) flag=!flag;
            deq.pop_back();
        }
    }
    return 0;
}
