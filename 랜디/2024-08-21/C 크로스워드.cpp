#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

int main(){
    fastio;
    int N,M; cin>>N>>M;
    string board[23];
    for(int i=0; i<N; i++) cin>>board[i];
    vector<string> V;
    for(int i=0; i<N; i++){
        string S = "";
        for(int j=0; j<M; j++){
            if(board[i][j]=='#'){
                if(S.size()>1) V.push_back(S);
                S = "";
            }
            else S += board[i][j];
        }
        if(S.size()>1) V.push_back(S);
    }

    for(int i=0; i<M; i++){
        string S = "";
        for(int j=0; j<N; j++){
            if(board[j][i]=='#'){
                if(S.size()>1) V.push_back(S);
                S = "";
            }
            else S += board[j][i];
        }
        if(S.size()>1) V.push_back(S);
    }

    sort(V.begin(), V.end());

    cout<<V.front();
    return 0;
}
