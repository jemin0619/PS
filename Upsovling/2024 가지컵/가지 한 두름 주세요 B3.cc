#include <bits/stdc++.h>
using namespace std;

string board[11][11];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            cin>>board[i][j];
    for(int i=0;i<10;i++){
        bool check=true;
        string tmp=board[i][0];
        for(int j=1;j<10;j++){
            if(tmp!=board[i][j]) {check=false; break;}
        }
        if(check) {cout<<1; return 0;}
    }
    for(int i=0;i<10;i++){
        bool check=true;
        string tmp=board[0][i];
        for(int j=1;j<10;j++){
            if(tmp!=board[j][i]) {check=false; break;}
        }
        if(check) {cout<<1; return 0;}
    }
    cout<<0;
    return 0;
}
