//18회 시도만에 성공했다 ㅋㅋㅋㅋ...
//TC가 빡빡하게 짜진건지 초기 구간을 애매하게 설정해주면 WA가 났던 것 같다.

//토카가 집까지 가는데 필요한 최소 이동횟수 X를 구한다.
//0~T번 이동할 때 돌돌이가 토카를 잡는 경우가 있는지 체크한다.
//두 개 모두 이분탐색으로 처리가 가능하다.

//나는 토카의 시작 위치를 0으로 생각해 코드를 작성했다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

ll A,B,C,D,K;

//mid번 이동했을 때, 돌돌이가 토카를 잡는가?
bool check(ll mid){
    if(mid==0) return false;
    ll ret1 = mid*(2*B + (mid-1)*-K); //등차수열의 합
    ll ret2 = -C + D*mid;
    if(ret1<=ret2*2) return true; //돌돌이와 토카의 위치가 같거나 돌돌이가 토카를 앞지름
    if(ret1>=A*2 && ret2>=A) return true; //동시에 집에 도착함
    return false;
}

int main(){
    fastio;
    cin>>A>>B>>C>>D>>K;

    if(K==0){ //속도 감소가 없으면 이분탐색 필요없음
        ll ret = (A-1)/B + 1;
        if(ret*D >= A+C) cout<<-1;
        else cout<<ret;
        return 0;
    }

    ll X = B/K + (B%K!=0); //토카의 이동거리가 0이 되기까지의 이동횟수
    ll st=-1, en=X+1;

    while(st+1<en){
        ll mid = (st+en)/2;
        ll dist = mid*(2*B + (mid-1)*-K);
        if(dist>=2*A) en = mid;
        else st = mid;
    }

    ll ans = en;

    if(en*(2*B+(en-1)*-K)>=2*A){
        st = -1, en = en+1;
        while(st+1<en){
            ll mid = (st+en)/2;
            if(check(mid)){
                cout<<-1;
                return 0;
            }
            else st = mid;
        }
        cout<<ans;
    }
    else cout<<-1;
    return 0;
}
