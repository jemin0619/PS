//그냥 피보나치 써서 파이스트*100/(파이스프+토마토스프) 이런 식으로 하면 안됨.
//매번 토마토, 혹은 파이스프를 추가하는게 아니라 둘이 섞여서 만들어진 스프를 넣는 것이기에 매번 /2를 해줘서 스프 비율을 맞춰줘야 한다.

#include <bits/stdc++.h>
using namespace std;
#define ld long double

int main(){
    int N; cin>>N;
    N = min(100, N);
    vector<ld> DP(103);
    DP[1] = 1; DP[2] = 0;
    for(int i=3; i<=N; i++){
        DP[i] = (DP[i-1] + DP[i-2])/2;
    }
    cout<<fixed;
    cout.precision(10);
    cout<<DP[N]*100<<' '<<100-(DP[N]*100);
    return 0;
}
