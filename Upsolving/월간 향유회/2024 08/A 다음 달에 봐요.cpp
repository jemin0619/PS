#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int Q; cin>>Q;
    int p = 0;
    while(Q--){
        int x,y; cin>>x>>y;
        if(x==1) p+=y;
        if(x==2){
            p -= y;
            if(p<0){
                cout<<"Adios";
                return 0;
            }
        }
    }
    cout<<"See you next month";
    return 0;
}
