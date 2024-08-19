#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int get(int num){
    if(num==0 || num==2 || num==5) return num;
    else return 1;
}

int main(){
    fastio;
    int N, M; cin>>N>>M;
    N = get(N);
    M = get(M);
    if(N==M) cout<<"=";
    else{
        if((N==0 && M==5) || (N==5 && M==2) || (N==2 && M==0) || N==1) cout<<"<";
        else cout<<">";
    }
    return 0;
}

//00:02 WA
//00:06 AC

//지문을 잘못 읽어서 무효에 대한 처리를 잘못했다.
//함수로 무효 표식을 1로 통일시켜서 해결했다.
