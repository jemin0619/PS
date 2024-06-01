//처음에 생각없이 Map에서 BFS를 하려다가 시간초과를 받았습니다.
//그러다가 가짓수가 생각보다 많지 않다는 것을 깨닫고 Set으로 풀이를 작성했는데 계속 WA가 나왔습니다...
//결국 풀이를 확인하고 코드를 작성하기 시작했습니다.

//첫 번째엔 solve(1)에서 min(ans, dist)로 식을 적어 틀렸었습니다.
//두 번째엔 ans==10 에만 -1을 출력하게 하여 26%에서 틀렸었습니다.
//세 번째엔 ans가 10이 아니면 solve를 중단하도록 코딩하여 틀렸었습니다.
//마지막에 solve(1,2,3)을 전부 시도하고, ans가 K보다 크면 -1을 출력하게 하여 AC를 받았습니다.

//ans==10에만 -1을 출력하도록 하면 틀리는 이유는 
//solve(2)에서 5 또는 4를 답으로 정했을 때, 이 값이 K보다 크다면 답이 될 수 없기 때문입니다.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K; //아이템개수 초기기력
ll Ey, Ex, ans=0x7f7f7f7f7f; 
set<pair<ll,ll>> S;

void solve(int num){
    if(num==0){ //아이템 0번 사용
        ll dist = abs(Ex) + abs(Ey);
        if(dist<=K) ans = min(ans,dist);
    }

    if(num==1){ //아이템 1번 사용
        for(auto[X,Y] : S){
            ll dist = abs(Ex-X) + abs(Ey-Y);
            if(dist+2<=K) ans = min(ans, dist+2);
        }
    }

    if(num==2){ //아이템 2번 사용
        for(auto[X,Y] : S){
            if(S.find({Ex-X, Ey-Y})!=S.end()) {ans = min(ans,4LL);}
            else if(S.find({Ex-X+1,Ey-Y})!=S.end()) {ans = min(ans,5LL);}
            else if(S.find({Ex-X,Ey-Y+1})!=S.end()) {ans = min(ans,5LL);}
            else if(S.find({Ex-X-1,Ey-Y})!=S.end()) {ans = min(ans,5LL);}
            else if(S.find({Ex-X,Ey-Y-1})!=S.end()) {ans = min(ans,5LL);}
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>N>>K;
    while(N--){
        ll x,y; cin>>x>>y;
        S.insert({x,y});
    }
    cin>>Ex>>Ey;
    solve(0);
    solve(1);
    solve(2);
    if(ans>K) cout<<-1;
    else cout<<ans;
    return 0;
}
