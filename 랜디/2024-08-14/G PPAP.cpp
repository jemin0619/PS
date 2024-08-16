//개인적으로 cpp로 문자열 처리를 할 때 덱을 많이 써서 접근이 쉬웠다.
//처음엔 KMP를 배우진 않았지만 그런 느낌이 났는데 간단한 문제였다.
//스택 풀이가 정해인 것 같은데 그냥 덱으로 PPAP가 맞춰졌는지 확인하면서 가도 풀린다.
//정해는 A가 들어왔을 때... 이런 식으로 푸는 것 같다.

#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    string S; cin>>S;
    deque<char> deq;
    
    for(char c : S){
        deq.push_back(c);
        while(deq.size()>=4){
            int en = deq.size()-1;
            if(deq[en]=='P' && deq[en-1]=='A' && deq[en-2]=='P' && deq[en-3]=='P'){
                deq.pop_back(); deq.pop_back(); deq.pop_back();
            }
            else break;
        }
    }
    if(deq.size()==1 && deq.front()=='P') cout<<"PPAP";
    else cout<<"NP";
    return 0;
}
