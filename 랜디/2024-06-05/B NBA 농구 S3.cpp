#include <bits/stdc++.h>
using namespace std;

int N;

int T[3];
int S[3];
int lteam;
string lTm;
int lminute;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0); cout.tie(0);
    cin>>N;

    N--;
    cin>>lteam>>lTm;
    lminute = ((lTm[0]-'0')*10 + lTm[1]-'0')*60 + (lTm[3]-'0')*10 + lTm[4]-'0';
    S[lteam]++;

    while(N--){
        int team; string Tm; cin>>team>>Tm;
        int minute = ((Tm[0]-'0')*10 + Tm[1]-'0')*60 + (Tm[3]-'0')*10 + Tm[4]-'0';
        if(S[1]>S[2]){
            T[1] += (minute-lminute);
        }
        if(S[1]<S[2]){
            T[2] += (minute-lminute);
        }
        S[team]++;
        lminute = minute;
    }
    if(S[1]>S[2]){
        T[1] += (48*60-lminute);
    }
    if(S[1]<S[2]){
        T[2] += (48*60-lminute);
    }
    printf("%02d:%02d\n",T[1]/60, T[1]%60);
    printf("%02d:%02d\n",T[2]/60, T[2]%60);
    return 0;
}
