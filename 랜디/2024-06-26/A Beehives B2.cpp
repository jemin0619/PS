//N이 작아서 최적화시키지 않아도 겹치는 경우가 있어도 모두 탐색해도 시간초과가 생기지 않는다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);

int main(){
    fastio;
    while(true){
        double d; int N; cin>>d>>N;
        if(d==0 && N==0) break;
        d*=d;
        vector<pair<double,int>> Bee;
        for(int i=0;i<N;i++){
            double x,y; cin>>x>>y;
            Bee.push_back({x,y});
        }
        vector<int> ans(N,0); //0 떨어져있음, 1 붙어있음
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(i==j) continue;
                double pow2_dist = abs(Bee[i].first-Bee[j].first)*abs(Bee[i].first-Bee[j].first) + abs(Bee[i].second-Bee[j].second)*abs(Bee[i].second-Bee[j].second);
                if(pow2_dist <= d) ans[i] = ans[j] = 1;
            }
        }

        int sour=0, sweet=0;
        for(int val : ans){
            if(val==0) sweet++;
            if(val==1) sour++;
        }
        cout<<sour<<" sour, "<<sweet<<" sweet\n";
    }

    return 0;
}
