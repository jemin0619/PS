//https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AZIieDaq5AEDFAXd

//Tag: 수학, 애드혹

//뭔가 하고 보니까 DP처럼 생겼는데, 시간제한을 보니 DP는 아니었다.
//그냥 등차수열의 합 써서 쭉 가다가 i번째 원소까지의 합이 P가 된다면 1을 빼주면 된다.
//1을 빼는 이유는 가장 높은 층에 도달해야 하므로 가장 작은 원소인 1을 빼주는 것이다.
//그리고 1을 빼면 절대 P층에 도달할 수 없기 때문이기도 하다.

//O(N*tc)로 짜도 되긴 하는데, 이분탐색을 써서 O(tc log N)에 짜보았다.
//이분탐색에서 시작과 끝에 1의 gap을 매번 주는데, 요즘엔 다르게 해볼까 하는 생각도 든다...

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

ll getSum(ll mid){
    return (mid*(mid+1))/2;
}

int solve(){
    ll n, p; cin>>n>>p;
    //check(mid) : sum(1~mid)가 P보다 크거나 같은가?
    ll st=0, en=n+1;
    while(st+1<en){
        ll mid = (st+en)/2;
        if(getSum(mid)>=p) en = mid;
        else st = mid; 
    }
    ll ans = getSum(n);
    if(getSum(min(en, n))==p) ans-=1;
    return ans;
}

int main(){
    fastio;
    int tc; cin>>tc;
    while(tc--) cout<<solve()<<'\n';
    return 0;
}
