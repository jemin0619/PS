//정말 창의적인 문제였다...
//map에는 각 노래가 등장하는 가장 빠른 위치가 어디인지를 저장하고, 이후에 vector에 넣고 sort한다.
//이후 조건에 따라 출력해줄지, 말지를 결정하면 된다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int N; cin>>N;
    map<string ,int> Mp;
    while(N--){
        int A, B;
        string od;
        cin>>A>>od>>B;
        while(A--){
            string x; cin>>x;
            if(Mp.find(x)==Mp.end()) Mp[x] = B;
            else Mp[x] = min(Mp[x], B);
        }
    }
    vector<pair<int, string>> V; 
    for(auto&[key, value] : Mp) V.push_back({value, key});
    sort(V.begin(), V.end());
    for(int i=0; i<V.size(); i++){
        if((i==0 || V[i].first!=V[i-1].first) && V[i].first==i+1) cout<<V[i].first<<' '<<V[i].second<<'\n';
    }
    return 0;
}
