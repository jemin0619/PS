#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define ff first
#define ss second
#define pii pair<ll,ll>
#define tiii tuple<ll,ll,ll>
#define pb push_back

int main(){
    fastio;
    int t; cin>>t;
    while(t--){
        int N,S,E; cin>>N>>S>>E;
        if((S==1 && E==N)||(S==N && E==1)) {cout<<"0\n"; continue;}
        if(abs(S-E)==1) {cout<<"1\n"; continue;} //둘이 붙어있는 경우
        if(S==1 || S==N) {cout<<"1\n"; continue;} //시작점이 끄트머리인 경우
        else {cout<<"2\n"; continue;}
    }
    return 0;
}

//00:18 WA
//00:21 WA
//00:24 WA
//00:30 AC

//3차 시도에서 st와 en의 gap이 1인 경우를 고려했지만 똑같이 WA였다.
//문제를 다시 읽자, 순간이동은 1 또는 N으로만 가능하다는 것을 보았고, 식을 수정했다.
//총 10개의 경우의 수가 존재했다.
