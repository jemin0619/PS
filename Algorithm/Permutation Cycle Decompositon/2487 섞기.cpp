//각 사이클의 길이를 모두 구하고, 그 길이의 최소공배수를 구해야 한다.
//한 사이클에 속한 수들은 그 사이클의 길이만큼 회전하면 제자리로 돌아오기 때문이다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}
int lcm(int a, int b){
    int g = gcd(a,b);
    return a/g * b/g * g;
}

int main(){
    fastio;
    int N; cin>>N;
    vector<int> V(N+1);
    vector<bool> vis(N+1);
    for(int i=1;i<=N;i++) cin>>V[i];
    int ans = 1;
    for(int i=1;i<=N;i++){
        if(vis[i]) continue;
        int cycle = 0;
        for(int nxt=i; !vis[nxt]; nxt=V[nxt]){
            vis[nxt]=true;
            cycle++;
        }
        ans = lcm(ans, cycle);
    }
    cout<<ans;
    return 0;
}
