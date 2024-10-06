//그냥 크게 잡아주었다.

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int l,r,x; cin>>l>>r>>x;
    vector<int> vis(2048, false);
    for(int i=l; i<=r; i++){
        vis[x|i] = true;
    }
    for(int i=0; i<=2048; i++){
        if(!vis[i]){
            cout<<i; return 0;
        }
    }
	return 0;
}
