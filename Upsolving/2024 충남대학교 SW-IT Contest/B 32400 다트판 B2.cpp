#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int main(){
    fastio;
    vector<int> V(20);
    double A=0.0, B=0.0;
    for(int i=0; i<20; i++) {cin>>V[i]; B+=V[i];}
    for(int i=0; i<20; i++){
        if(V[i]==20){
            double tmp = V[i];
            if(i-1<0) tmp += V[19];
            else tmp += V[i-1];
            if(i+1>=20) tmp += V[0];
            else tmp += V[i+1];
            A = tmp/3;
        }
    }
    B /= 20;
    if(A>B) cout<<"Alice";
    else if(A<B) cout<<"Bob";
    else cout<<"Tie";
    return 0;
}
