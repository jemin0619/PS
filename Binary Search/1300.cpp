//2차원 배열을 만들고 정렬하는 풀이는 시간복잡도, 메모리 제한상 불가능하다.
//다음과 같은 관찰을 통해 시간복잡도를 획기적으로 줄일 수 있다.

// 1 2 3
// 2 4 6
// 3 6 9

//다음의 N=3, N*N 배열에서 6보다 작거나 같은 수를 구하려면 어떻게 해야 할까?
//각 행의 첫 번째 항을 a라고 정의한다.
//이때 첫 번째 행에서 6보다 작거나 같은 수의 개수는 min(6/a,N)이고, 모든 행을 살핀 값을 더하면 다음과 같다.
//min(6/1, N) + min(6/2, N) + min(6/3, N)

//각 행마다 a ~ a*N 의 수만 존재하기에 어떤 수 X보다 작거나 같은 수의 개수를 구하러면 min(X/a, N)을 때리면 된다.

//파라미터가 FFTT로 존재하도록 Check(0)=F, Check(10^9)=T 로 잡았다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

ll N,K;

bool Check(ll x){  //A[i][j] <= X를 만족하는 A[i][j]의 개수가 K보다 크거나 같은가?
    ll cnt = 0;
    for(int i=1;i<=N;i++){
        cnt += min<ll>(x/i, N);
    }
    return cnt >= K;
}

int main(){
    fastio;
    cin>>N>>K;
    ll lo=0, hi=1e9;
    while(lo+1<hi){
        ll mid = (lo+hi)/2;
        if(Check(mid)) hi = mid;
        else lo = mid;
    }
    cout<<hi;
    return 0;
}
