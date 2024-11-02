//S1 문제인데 난이도가 좀 있다.
//덱을 써서 무지성으로 풀려다가 2WA를 받고 깔끔하게 짜보았다..

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define pii pair<int,int>
#define xx first 
#define yy second

int main(){
    fastio;
    int N, M; cin>>N>>M;
    stack<pii> Container;
    queue<pii> Rail;
    vector<int> chk(M+1);
    for(int i=0; i<N; i++){
        int a,b; cin>>a>>b;
        Rail.push({a,b});
        chk[a]++;
    }
    int priority = M;
    int ans = 0;
    while(!Rail.empty()){
        auto[curP, curW] = Rail.front(); Rail.pop();
        if(curP != priority){ //레일의 끝으로 다시 보냄
            Rail.push({curP, curW});
            ans += curW;
            continue;
        }
        else{
            stack<pii> stk; //바로 넣을 수 있게 빼줌
            while(!Container.empty() && Container.top().yy<curW && Container.top().xx==priority){
                ans += Container.top().yy;
                stk.push(Container.top());
                Container.pop();
            }

            ans += curW;
            Container.push({curP, curW});

            while(!stk.empty()){
                ans += stk.top().yy;
                Container.push(stk.top());
                stk.pop();
            }

            chk[priority]--; 
            if(chk[priority]==0) priority--;
        }
    }
    cout<<ans;
    return 0;
}
