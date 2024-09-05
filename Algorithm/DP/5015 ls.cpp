//종만북 공부 중 와일드카드 문제를 풀다가 BOJ에 비슷한 문제가 있어서 풀게 되었다.
//완전탐색으로 겹치는 문자를 모두 확인하는데, 이 방법만으로는 시간초과가 발생하므로
//메모이제이션 DP로 기억하면서 풀어나가면 시간초과를 막을 수 있다.

//와일드카드 문자를 만나면 대입시키는 경우와 대입시키지 않는 경우로 분기가 나뉜다.
//분기가 계속해서 나뉘면서 문자 하나를 대입시키고, 두 개를 대입시키고 ... 모든 경우를 확인한다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N;
string P, W;
int dp[103][103];

bool solve(int p, int w){
    int &ret = dp[p][w];
    if(ret != -1) return ret;

    if(p<P.size() && w<W.size() && P[p]==W[w]) return ret = solve(p+1, w+1);

    if(p==P.size()) return ret = (w==W.size());

    if(P[p]=='*'){
        //*에 아무것도 대입하지 않는 경우 or *에 문자 하나를 대입시키는 경우
        if((p<P.size() && solve(p+1, w) )|| (w<W.size() && solve(p, w+1))){
            return ret = 1;
        }
    }

    return ret = 0;
}

int main(){
    fastio;
    cin>>P>>N;
    for(int i=0; i<N; i++){
        cin>>W;
        memset(dp, -1, sizeof(dp));
        if(solve(0, 0)) cout<<W<<'\n';
    }
    return 0;
}
