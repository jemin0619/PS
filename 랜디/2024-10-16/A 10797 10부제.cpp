#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int ans = 0;
    for(int i=0; i<5; i++){
        int x; cin>>x;
        if(x==n) ans++;
    }
    cout<<ans;
    return 0;
}

