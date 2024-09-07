//BOJ 1305 광고와 같이 실패함수로 해결할 수 있다.
//반복되어야 할 부분을 구하고, 그 부분을 k번 사용해서 길이 N을 만들 수 없다면 1, 아니라면 k를 출력한다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    while(true){
        string S; cin>>S;
        if(S==".") break;
        int N = S.size();

        vector<int> Fail(N+3);
        for(int i=1, j=0; i<N; i++){
            while(j>0 && S[i]!=S[j]) j=Fail[j-1];
            if(S[i]==S[j]) j++;
            Fail[i] = j;
        }
      
        int div = N - Fail[N-1];
        if(N%div) cout<<"1\n";
        else cout<<N/div<<'\n';
    }
    return 0;
}
