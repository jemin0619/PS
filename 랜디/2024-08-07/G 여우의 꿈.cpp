//2023년도 서울대 문제인데 어려웠다.
//하노이의 탑도 5개월 전에 처음 볼 땐 엄청 어려웠는데, 이제는 이해가 잘 된다.
//큰 수 연산이 필요할 땐 항상 POW2같이 전처리를 해서 쓰는게 좋다.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio cin.tie(NULL)->sync_with_stdio(false)

const ll MOD = 1e9 + 7;

vector<int> V; //아름다운 배열
vector<ll> POW2;
ll Ans = 0;

//하노이 탑 문제에서 N개의 원판을 옮기는데 드는 최소 비용은 2^N -1이다.

void func(int from, int to, int height){
    if(height==0){ //남은 원판이 0개이면
        cout<<Ans;
        return;
    }
    if(from != to){ //이동해야 하는 곳이 현재 위치가 아닌 경우
        //N-1개의 원판을 from과 to 이외의 장소로 옮기고, N번째 원판을 to에 위치시킨다.
        Ans += POW2[height-1]; //2^(height-1) -1 +1
        Ans %= MOD;
        func(6-from-to, V[height-1], height-1);
    }
    else{ //이동해야 하는 곳이 현재 위치인 경우
        //맨 아래 원판이 정위치에 있으므로 그 위 원판을 옮길 준비를 함
        func(from, V[height-1], height-1);
    }
}

int main(){
    fastio;
    int N, K; cin>>N>>K;
    V.resize(N+3);
    for(int i=1; i<=N; i++) cin>>V[i];

    POW2.resize(N+3);
    POW2[0] = 1;
    POW2[1] = 2;
    for(int i=2; i<=N; i++){
        POW2[i] = POW2[i-1] * 2;
        POW2[i] %= MOD;
    }

    //큰 원판부터 작은 원판 순서로 맞춰가는게 최적이므로 V[N]에서 V[1]로 내려가게 설계
    func(K, V[N], N);
    return 0;
}
