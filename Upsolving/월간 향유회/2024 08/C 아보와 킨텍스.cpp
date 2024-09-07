//처음에 25*N + 26으로 식을 짜고 반례가 의심되어 set을 사용한 완탐 코드를 짰다.
//TC를 다양하게 넣었는데 모두 같게 나와서 제출하고 AC를 받았다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    long long N; string S;
    cin>>N>>S;
    cout<<(long long)(25LL*(N+1LL))+1LL;
  
    /* //Brutefore
    set<string> s;
    for(int i=0; i<=N; i++){
        for(int ch=0; ch<26; ch++){
            char c = 'a'+ch;
            string str = "";
            for(int j=0; j<i; j++) str+=S[j];
            str+=c;
            for(int j=i; j<N; j++) str+=S[j];
            s.insert(str);
        }
    }
    cout<<'\n'<<s.size();*/
  
    return 0;
}
