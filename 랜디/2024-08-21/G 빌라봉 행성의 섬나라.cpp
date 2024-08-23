//애드훅, 이분탐색

//그래프를 구성할 경우 메모리 초과가 뻔하다.
//V-E가 그 나라의 도시 집합 수라는 것을 감각적으로 알 수 있다.
//머리속이 제대로 정리되지 않아 증명을 따로 하긴 힘들다...

//그 후 각 정점 번호의 끝을 배열에 저장시킨다.
//이 코드에선 partial_sum으로 누적합 배열을 구성하는 방식으로 구현했다.

//그렇게 되면 이분탐색으로 2, 3번 쿼리에서 각 그 정점들이 어느 나라에 속하는지 O(log N)에 구할 수 있다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int main(){
    fastio;
    ll N; cin>>N;
    vector<ll> Arr(N+1);
    vector<ll> V;
    V.push_back(0);
    for(int i=1; i<=N; i++){
        ll v,e; cin>>v>>e;
        for(int j=0; j<e; j++){
            ll a,b; cin>>a>>b;
        }
        V.push_back(v);
        Arr[i] = v - e;
    }
    partial_sum(V.begin(), V.end(), V.begin());
    ll Q; cin>>Q;
    while(Q--){
        ll q; cin>>q;
        if(q==1){
            ll k; cin>>k;
            cout<<Arr[k]<<'\n';
        }
        else{
            ll u,v; cin>>u>>v;

            ll st = 0; ll en = N+1;
            while(st+1<en){
                int mid = st+en; mid/=2;
                if(V[mid]<u) st = mid;
                else en = mid;
            }

            if(q==2) Arr[en]++;
            else Arr[en]--;
        }
    }
    return 0;
}
