#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

bool get(char X){ //X가 짝수면 true
    if((X-'0')%2==0) return true;
    return false;
}

int main(){
    fastio;
    int N; string S;
    cin>>N>>S;
    int odd=0, even=0;
    for(char c : S){
        if(get(c)) even++;
        else odd++;
    }
    if(even==odd) cout<<-1;
    else if(even>odd) cout<<0;
    else cout<<1;
    return 0;
}

//00:08 AC
