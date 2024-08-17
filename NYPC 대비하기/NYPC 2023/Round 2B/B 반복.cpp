//00:30 B WA
//00:33 B AC

//문제 원인은 시작부터 변경이 안되는 경우의 조건을 V[N-1]==N 으로 잡았었기 때문이다.
//좌표압축을 해도 최대값이 N이 아닐 수도 있다는 것을 잊었었다.

//문제에서 규칙을 찾아보면 가장 큰 수가 오른쪽에 오면 더 이상 문자열이 바뀌지 않는다.
//그렇기에 -1을 출력해야 할 상황은 존재하지 않는다.

//매번 배열을 새로고침하면 시간초과가 나기에 그리디하게 접근해야 한다.
//가장 오른쪽에 있는 수를 기준으로 그 수보다 작거나 같은 수들은 왼쪽, 큰 수들은 오른쪽으로 위치를 바꾼다.
//이 말은 가장 오른쪽에 올 수는 변경 전 배열을 기준으로 가장 오른쪽 값부터 왼쪽으로 이동할 때 그 값보다 큰 최초의 값이라는 의미이다.
//이것은 가장 오른쪽의 값의 갱신된 후에도 동일하기에, 배열을 바꿀 필요 없이 그냥 N-1 ~ 0으로 스위핑하면서 풀면 된다.
//시간복잡도는 O(N)

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
#define ff first
#define ss second
#define pii pair<ll,ll>
#define tiii tuple<ll,ll,ll>

int main(){
    fastio;
    int N; cin>>N;
    vector<int> V(N);
    for(int i=0; i<N; i++) cin>>V[i];

    vector<int> tmp(V);
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for(int&val : V) val = lower_bound(tmp.begin(), tmp.end(), val) - tmp.begin() + 1;

    int MX = *max_element(V.begin(), V.end());
    
    //시작부터 변경이 안되는 경우
    if(V[N-1]==MX) {cout<<0; return 0;}

    int cnt = 0;
    int val = V[N-1];
    for(int i=N-2; i>=0; i--){
        if(V[i]>val){
            cnt++;
            val = V[i];
            if(val==MX) {cout<<cnt; return 0;}
        }
    }
    //cout<<-1;
    return 0;
}
