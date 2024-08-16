//https://www.acmicpc.net/problem/31844

#include <bits/stdc++.h>
using namespace std;

int a; //@
int b; //#
int c; //!

string str;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(int i=1;i<=10;i++){
        char x; cin>>x;
        if(x=='@') a=i;
        if(x=='#') b=i;
        if(x=='!') c=i;
        str+=x;
    }
    //-1을 출력하는 경우는 다음과 같다.
    // 로봇 상자 도착지 / 도착지 상자 로봇 순으로 배치가 되어 있지 않는 경우

    if((a<b && b<c) || (c<b && b<a)){
        cout<<abs(a-b) + abs(b-c) - 1;
    }
    else cout<<-1;
    return 0;
}
