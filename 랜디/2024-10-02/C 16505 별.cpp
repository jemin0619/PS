#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

vector<vector<char>> V;

void solve(int y, int x, int sz){
    V[y][x] = '*';
    sz /= 2;
    if(sz==0) return;
    solve(y, x, sz);
    solve(y+sz, x, sz);
    solve(y, x+sz, sz);
}

int main(){
    fastio;
    int N; cin>>N;
    int SZ = 1<<N;
    V.resize(SZ+3, vector<char>(SZ+3, ' '));

    solve(0, 0, SZ);

    for(int i=0; i<SZ; i++){
        for(int j=0; j<SZ-i; j++){
            cout<<V[i][j];
        } cout<<'\n';
    }
    return 0;
}
