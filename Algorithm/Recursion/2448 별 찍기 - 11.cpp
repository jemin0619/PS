//벡터 초기값을 설정해주지 않으면 WA를 받는다.
//기본적으로 공백 문자가 아닌 다른 문자가 들어가 있는 것 같다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

vector<vector<char>> V;

void solve(int y, int x, int sz){
    if(sz==1){
        V[y][x] = V[y+1][x-1] = V[y+1][x+1] = '*';
        for(int i=x-2; i<=x+2; i++) V[y+2][i] = '*';
        return;
    }
    sz /= 2;
    solve(y, x, sz);
    solve(y+3*sz, x-3*sz, sz);
    solve(y+3*sz, x+3*sz, sz);
}

int main(){
    fastio;
    int N; cin>>N;
    V.resize(N, vector<char>(N*2-1, ' '));

    solve(0, 2+3*(N/3-1), N/3);

    for(int i=0; i<N; i++){
        for(int j=0; j<2*N-1; j++){
            cout<<V[i][j];
        } cout<<'\n';
    }
    return 0;
}
