//풀이: 삼분탐색
//함수가 볼록함수이기에 삼분탐색으로 풀이가 가능하다.
//삼분탐색은 처음 써보는데 재밌는 테크닉인 것 같다.

//참고 https://ws-pace.tistory.com/214
//참고 https://blog.naver.com/kks227/221432986308
//참고 https://witch.work/posts/binary-search-next-step

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int N;
vector<ll> Y(30'0003);
vector<ll> D(30'0003);

//가운데 높이를 mid로 했을 때 변경에 걸리는 횟수
ll func(ll mid){
    ll ret = 0;
    ret += abs(mid - Y[N/2]) + abs(mid - D[N/2]); //가운데 높이를 mid로 설정
    
    ll lmid = mid+1;
    for(int i=N/2-1; i>=0; i--){
        ret += abs(lmid - Y[i]) + abs(lmid - D[i]);
        lmid++;
    }

    ll rmid = mid+1;
    for(int i=N/2+1; i<N; i++){
        ret += abs(rmid - Y[i]) + abs(rmid - D[i]);
        rmid++;
    }

    return ret;
}

int main(){
    fastio;
    cin>>N;
    for(int i=0; i<N; i++) cin>>Y[i];
    for(int i=0; i<N; i++) cin>>D[i];

    ll MX = max(*max_element(Y.begin(), Y.end()), *max_element(D.begin(), D.end()));

    //0 ~ MX 사이에 답이 있다.
    //MX보다 작은 범위 내에 답이 있지만 편의상 MX를 en으로 잡아도 된다.
    ll st = -1, en = MX;
    while(st+2<en){
        ll p = (st*2+en)/3;
        ll q = (st+en*2)/3;
        if(func(p) <= func(q)) en=q;
        else st=p;
    }
    ll ans = func(max(st,0LL));
    for(int i=max(st,0LL); i<=max(en,0LL); i++){
        ans = min(ans, func(i));
    }
    cout<<ans;
    return 0;
}
