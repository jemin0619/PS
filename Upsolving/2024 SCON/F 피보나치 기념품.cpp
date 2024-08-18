#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int main(){
    fastio;
    int N; cin>>N;
    if(N==2) {cout<<"1\n1\n1\n2"; return 0;}
    vector<int> A, B;
    while(N>=3){
        A.push_back(N); N--;
        B.push_back(N); N--;
        B.push_back(N); N--;
    }
    if(N==2){
        A.push_back(1);
        B.push_back(2);
    }
    cout<<A.size()<<'\n';
    for(int val:A) cout<<val<<' ';
    cout<<'\n';
    cout<<B.size()<<'\n';
    for(int val:B) cout<<val<<' ';
    cout<<'\n';
    return 0;
}

//00:51 WA
//01:00 AC

//기념품 번호가 최대 N이라는 것을 읽지 못하고 99999부터 채워넣어서 틀렸다.
