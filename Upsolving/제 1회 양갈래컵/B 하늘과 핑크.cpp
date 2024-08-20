#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    int N; cin>>N;
    int A = 0, B = 0;
    for(int i=0; i<N; i++){
        int x; cin>>x;
        A += x;
    }
    for(int i=0; i<N; i++){
        int x; cin>>x;
        B += x;
    }
    cout<<B<<' '<<A;
    return 0;
}
