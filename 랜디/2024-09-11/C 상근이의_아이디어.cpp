//기괴한 수학 애드혹
//다신 보고싶지 않다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int a,b; cin>>a>>b;
    int x = b-a+1;
    cout<<x*(x-1)/2;
    return 0;
}
