#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc=3;
    while(tc--){
        int a,b,c;
        cin>>a>>b>>c;
        int st = a*3600+b*60+c;
        cin>>a>>b>>c;
        int en = a*3600+b*60+c;
        int res = en-st;
        int H = res/3600; res%=3600;
        int M = res/60; res%=60;
        int S = res;
        cout<<H<<' '<<M<<' '<<S<<'\n';
    }
    return 0;
}
