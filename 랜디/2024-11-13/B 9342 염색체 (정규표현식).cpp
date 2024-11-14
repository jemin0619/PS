//깡 구현을 시도했으나 구현이 살짝 까다로웠다.

#include <bits/stdc++.h>
#include <regex>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    regex r("[A,B,C,D,E,F]?A+F+C+[A,B,C,D,E,F]?");
    int tc; cin>>tc;
    while(tc--){
        string N; cin>>N;
        if(regex_match(N, r)) cout<<"Infected!\n";
        else cout<<"Good\n";
    }
    return 0;
}
