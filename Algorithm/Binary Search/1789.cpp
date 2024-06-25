//서로 다른 N개의 자연수의 합이 S라고 한다. S를 알 때, 자연수 N의 최댓값은 얼마일까?
//자연수를 최대로 골라야 하므로 1 ~ N까지 합이 S에 근접하게 고르면 된다.

// sum(1 ~ lo) <= S
// sum(1 ~ hi) > S

//lo를 K보다 작거나 같게 잡은 이유는 작을 경우 고른 수 중 가장 큰 수를 조절하면서 원하는 수를 맞출 수 있기 때문.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

ll S;

int main(){
    fastio;
    cin>>S;

    ll lo=0, hi=93000;
    while(lo+1<hi){
        ll mid = (lo+hi)/2;
        ll val = mid*(mid+1)/2;
        if(val<=S) lo=mid;
        else hi=mid;
    }
    cout<<lo;
    return 0;
}

/*
X(X+1)/2 = 43'0000'0000
X^2 + X = 86억
93000^2 ~= 86억
*/
