//매 순간 가장 빠른 길을 고르는 그리디한 전략이 통한다
//문제를 읽으면서 A라는 값이 이상하게 느껴졌는데 문제를 풀고 나서 생각해보니 A는 횡단보도를 1초보다 빠른 시간으로 통과하고 다음번 횡단보도 앞까지 가는 시간이었다.

#include <bits/stdc++.h>
using namespace std;

int N,ans;
vector<tuple<int,int,int,int>> V;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++){
        int a,b,c,d; cin>>a>>b>>c>>d;
        V.push_back({a,b,c,d});
    }
    for(auto[A,B,C,D] : V){
        int cur = ans % (C+D);
        if(cur < C) ans += A; //횡단보도로 바로 이동
        else if(B > C+D-cur+A) ans += (C+D-cur+A); //기다렸다가 횡단보도로 이동
        else ans += B; //육교로 바로 이동
    }   
    cout<<ans;
    return 0;
}
