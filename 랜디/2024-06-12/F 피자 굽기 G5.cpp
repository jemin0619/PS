//Monotonic Stack
//구멍 A 이후의 구멍들에 실질적으로 넣을 수 있는 크기는 A보다 작거나 같을 수밖에 없다.
//그렇게 Monotonic하게 요소들을 관리해면 O(N)에 해결이 가능하다.

//Monotonic하게 vector에 저장 후 Binary Search 풀이도 가능하다.
//그것보단 Stack이 깔끔한 듯 하다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);

int D,N;
stack<int> St;

int main(){
    fastio;
    cin>>D>>N;
    for(int i=0;i<D;i++){
        int x; cin>>x;
        if(!St.empty() && St.top()<x) x=St.top();
        St.push(x);
    }
    for(int i=0;i<N;i++){
        int x; cin>>x;
        while(!St.empty() && St.top()<x) St.pop();
        if(St.empty()) {cout<<0; return 0;}
        if(!St.empty() && St.top()>=x) St.pop();
    }
    cout<<St.size()+1;
    return 0;
}
