//처음에 문제 이해를 제대로 못했는데 문제에서 말하는 ans는 풀고 닫는 것을 하나로 친다.

//체인들을 배열에 저장하고 배열을 오름차순으로 정렬한다.
//정렬 후 앞의 체인을 하나씩 풀고 뒤에서부터 두 개의 체인끼리 묶는다면 고리를 최소한으로 사용해 문제를 해결할 수 있다.

//vector로 풀려 했지만 deque로 앞과 뒤의 원소를 pop시키는게 더 편하기에 deque를 사용했다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL) -> sync_with_stdio(false);
#define ll long long

ll N,ans;
deque<ll> V;

int main(){
    fastio;
    cin>>N;
    while(N--){
        ll x; cin>>x;
        V.push_back(x);
    }
    sort(V.begin(),V.end());
    while(V.size()>1){
        V.front()--; //앞의 고리를 하나 품
        ll tmp = V.back(); V.pop_back(); //푼 고리로 뒤쪽의 두 고리를 묶음
        V.back() += tmp;
        ans++;
        if(V.front()==0) V.pop_front();
    }
    cout<<ans;
    return 0;
}
