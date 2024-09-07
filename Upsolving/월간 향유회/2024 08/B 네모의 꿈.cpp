//다른 삼각형의 한 변과 길이가 같은 변이 있을 경우 무조건 네모를 만들 수 있다. (예제 참고)

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int N; cin>>N;
    vector<bool> chk(1000'003);
    while(N--){
        int a,b,c; cin>>a>>b>>c;
        if(chk[a] || chk[b] || chk[c]){
            cout<<"1"; return 0;
        }
        chk[a] = chk[b] = chk[c] = true;
    }
    cout<<"0";
    return 0;
}
