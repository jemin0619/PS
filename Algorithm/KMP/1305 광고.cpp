//실패함수 응용 문제
//Fail[N-1]은 전체 문자열에서 접두사와 접미사가 일치하는 최대 길이이다.
//일치하지 않는 나머지 부분이 반복되어야 광고가 완성된다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int N; string S;
    cin>>N>>S;

    vector<int> Fail(N+3);
    for(int i=1, j=0; i<N; i++){
        while(j>0 && S[i]!=S[j]) j=Fail[j-1];
        if(S[i]==S[j]) j++;
        Fail[i] = j;
    }

    cout<<N-Fail[N-1];
    return 0;
}
