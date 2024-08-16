//Ans를 int로 해서 한 번 WA

#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    int N; cin>>N;
    vector<int> V(N);
    long long Ans = 0;
    stack<int> stk;
    for(int i=0; i<N; i++){
        cin>>V[i];
        if(stk.empty()) {Ans++; stk.push(V[i]);}
        else if(stk.top()<V[i]){ //비어있지 않고 오름차순을 유지한다면
            Ans += stk.size()+1;
            stk.push(V[i]);
        }
        else{ //오름차순 유지가 안된다면
            while(!stk.empty()) stk.pop();
            stk.push(V[i]);
            Ans++;
        }
    }
    cout<<Ans;
    return 0;
}
