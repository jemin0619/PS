//생각보다 구현이 쉽지 않았다.
//문제 조건에서 꼭짓점마다 카페가 있다고 해서 그게 왜 필요한지 몰랐었는데 그 점을 활용하면 난이도가 많이 낮아진다.
//Y좌표를 기준으로 정렬했을때 첫 번재 값이 이전 Y좌표와 같게 만들어주고, 순서대로 인덱스를 매겨주면 해결할 수 있었다.

//Vscode의 CPH JUDGE에서 이상하게 Ypos를 그냥 vector<ll> Ypos[10'0003]으로 하면 안되길래 일단 map을 사용했다.
//다른 IDE에선 정상적으로 출력되는게 좀 이상했다.

//(수정) new를 통해 힙에 데이터를 동적으로 할당하며 문제를 해결했다.
//https://stackoverflow.com/questions/38842681/segmentation-fault-chkstk-ms-c
//문제 원인을 찾다 해당 글을 보았는데 도움이 되었다.
//스택은 빠른 접근이 가능하다는 장점이 있고, 힙은 큰 메모리를 사용할 수 있다는 장점이 있다.
//힙을 사용할 때 항상 delete을 통해 수동으로 메모리를 관리해줘야 한다는 것을 잊어선 안된다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

int main(){
    fastio;
    ll T; cin>>T;
    while(T--){
        ll n; cin>>n;
        vector<ll>* Ypos = new vector<ll>[100003];
        set<ll> Xpos;
        map<ll,pair<ll,ll>> Idx2Pos;
        ll preY = 0;
        ll cnt = 0;
        for(int i = 1; i <= n; i++){
            ll x, y; cin>>x>>y;
            Ypos[x].push_back(y);
            Xpos.insert(x);
        }

        for(ll x : Xpos){
            sort(Ypos[x].begin(), Ypos[x].end());
            if(Ypos[x][0] != preY) reverse(Ypos[x].begin(), Ypos[x].end());
            for(ll y : Ypos[x]){
                cnt++;
                Idx2Pos[cnt] = {x, y};
                preY = y;
            }
        }
        
        ll x; cin>>x;
        while(x--){
            ll q; cin>>q;
            cout << Idx2Pos[q].first << ' ' << Idx2Pos[q].second << '\n';
        }
        
        delete[] Ypos;
    }
    return 0;
}
