//3이 안된다고 생각했는데 3이 가능했음...
//나머지는 4 2 3 1에다가 붙여나가는 식으로 해결

#include <iostream>
using namespace std;

int main(){
    int N; cin>>N;
    if(N==1) {cout<<"YES\n1"; return 0;}
    if(N==2) {cout<<"NO"; return 0;}
    if(N==3) {cout<<"YES\n1 3 2"; return 0;}
    if(N>=4) cout<<"YES\n4 2 3 1 ";
    for(int i=5;i<=N;i++){
        cout<<i<<' ';
    }
    return 0;
}
