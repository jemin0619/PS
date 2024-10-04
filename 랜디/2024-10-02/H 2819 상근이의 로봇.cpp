//매번 거리 업데이트를 O(N)보다 빠르게 해야 TLE를 피할 수 있다.
//이분 탐색으로 O(logN)에 업데이트를 처리할 수 있다.

//upper_bound : 찾고자 하는 값보다 큰 값이 나타나는 최초의 idx 반환
//lower_bound : 찾고자 하는 값 이상의 값이 나타나는 최초의 idx 반환

//식이 어색할 수 있는데, 뺄 값들 sub, 더할 값을 add라고 정의한다.
//X는 이분탐색으로 구한 idx이다.
//sub : N - X
//add : N - sub = N - (N-X) = X
//val = add - sub = X - (N-X) = 2X - N

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int main(){
    fastio;
    ll N, M; cin>>N>>M;
    vector<ll> X(N), Y(N);
    ll ans = 0;
    for(int i=0; i<N; i++){
        cin>>X[i]>>Y[i];
        ans += (abs(X[i]) + abs(Y[i]));
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    string S; cin>>S;
    ll Cx=0, Cy=0;
    for(char c : S){
        if(c=='S'){ //x,y+1
            //Cy보다 y값이 작거나 같은 조사점들과의 거리는 1씩 증가한다.
            //Cy보다 y값이 큰 조사점들과의 거리는 1씩 감소한다. (초과 -> upper_bound)
            ll val = 2*(upper_bound(Y.begin(), Y.end(), Cy) - Y.begin()) - N;
            ans += val;
            Cy++;
        }
        if(c=='J'){ //x,y-1
            //Cy보다 y값이 작은 조사점들과의 거리는 1씩 감소한다
            //Cy보다 y값이 크거나 같은 조사점들과의 거리는 1씩 증가한다 (이상 -> lower_bound)
            ll val = 2*(Y.end() - lower_bound(Y.begin(), Y.end(), Cy)) - N;
            ans += val;
            Cy--;
        }
        if(c=='I'){ //x+1,y
            ll val = 2*(upper_bound(X.begin(), X.end(), Cx) - X.begin()) - N;
            ans += val;
            Cx++;
        }
        if(c=='Z'){ //x-1,y
            ll val = 2*(X.end() - lower_bound(X.begin(), X.end(), Cx)) - N;
            ans += val;
            Cx--;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
