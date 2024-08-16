#include <bits/stdc++.h>
using namespace  std;

int main(){
    string S; cin>>S;
    //S[0]이 초기 의자 상태

    char state = S[0]; int cnt=0;
    for(int i=1;i<S.size(); i++){
        //1. 떠날 때 올려야 하는 경우
        if(state != S[i]){
            cnt++;
            state = S[i];
        }
        if(S[i]!='U'){
            cnt++;
            state = 'U';
        }
    } cout<<cnt<<'\n';

    state = S[0]; cnt=0;
    for(int i=1;i<S.size(); i++){
        //2. 떠날 때 내려야 하는 경우
        if(state != S[i]){
            cnt++;
            state = S[i];
        }
        if(S[i]!='D'){
            cnt++;
            state = 'D';
        }
    } cout<<cnt<<'\n';
    
    state = S[0]; cnt=0;
    for(int i=1;i<S.size(); i++){
        //3. 떠날 때 아무거나 상관 없는 경우
        if(state != S[i]){
            cnt++;
            state = S[i];
        }
    } cout<<cnt<<'\n';
    return 0;
}
