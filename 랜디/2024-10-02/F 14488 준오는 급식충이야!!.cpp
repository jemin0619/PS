//순서대로 쭉 확인하면서 겹치는 부분을 구해주면 된다.
//삼분탐색 풀이도 존재하는 것 같다.
//서로 만날 수 있는 가장 빠른 시간을 구해서 그 값이 T보다 작거나 같은지 확인하는 방식이다.
//이런 발상을 할 수 있다는 것이 대단하다..

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ld long double

bool cross(ld a, ld b, ld c, ld d){
    return a<=d && c<=b;
}

int main(){
    fastio;
    int N; ld T; cin>>N>>T;
    vector<ld> X(N), V(N);
    for(int i=0; i<N; i++) cin>>X[i];
    for(int i=0; i<N; i++) cin>>V[i];

    if(N==1) {cout<<1; return 0;}

    ld st = X[0] - T*V[0];
    ld en = X[0] + T*V[0];
    for(int i=1; i<N; i++){
        ld Nst = X[i] - T*V[i];
        ld Nen = X[i] + T*V[i];
        if(cross(st, en, Nst, Nen)){
            st = max(st, Nst);
            en = min(en, Nen);
        }
        else{
            cout<<0;
            return 0;
        }
    }
    cout<<1;
    return 0;
}
