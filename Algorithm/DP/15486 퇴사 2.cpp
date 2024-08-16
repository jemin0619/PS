//5달 전에 바텀업으로 풀었던 문제인데 탑다운으로 해결해봤습니다.
//탑다운 코드가 직관적이라 더 쉬운 듯 합니다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define pii pair<int,int>
#define ff first
#define ss second 

int N; 
vector<pii> V;
vector<int> dp;

int solve(int day){
    if(day>=N) return 0;

    int&ret = dp[day];
    if(ret != -1) return ret;
    ret = 0;

    //그냥 다음 날로 넘어가기
    int D1 =  solve(day+1);

    //상담 하기 (상담 끝나는 날이 N일을 넘기면 상담 못함)
    int D2 = 0;
    if(day+V[day].ff<=N) D2 = solve(day + V[day].ff) + V[day].ss;

    ret = max(D1, D2);

    return ret;
}

int main(){
    fastio;
    cin>>N;
    V.resize(N);
    dp.resize(N, -1);

    for(int i=0;i<N;i++){
        cin>>V[i].ff>>V[i].ss;
    }

    cout<<solve(0);
    return 0;
}
