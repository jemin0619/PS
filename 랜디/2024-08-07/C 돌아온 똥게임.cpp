//그리디, 정렬
//ll으로 안되면 울면서 파이썬으로 바꾸려고 했는데 다행히 통과했다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int main(){
    fastio;
    ll N, Atk; cin>>N>>Atk;
    deque<ll> item;
    vector<ll> enemy;
    while(N--){
        int T; cin>>T;
        ll X; cin>>X;
        if(T==1) enemy.push_back(X);
        if(T==2) item.push_back(X);
    }
    sort(item.begin(), item.end());
    sort(enemy.begin(), enemy.end());
    ll Ans = 0;
    for(int i=0; i<enemy.size(); i++){
        if(Atk>enemy[i]){
            Atk += enemy[i];
            Ans++;
            //cout<<"적을 물리침 Atk: "<<Atk<<'\n';
        }
        else{
            while(!item.empty() && Atk<=enemy[i]){
                Atk *= item.front();
                item.pop_front();
                Ans++;
                //cout<<"아이템을 먹음 Atk: "<<Atk<<'\n';
            }
            if(Atk>enemy[i]){
                Atk += enemy[i];
                Ans++;
                //cout<<"적을 물리침 Atk: "<<Atk<<'\n';
            }
            else break;
        }
    }
    cout<<Ans+item.size();
    return 0;
}
