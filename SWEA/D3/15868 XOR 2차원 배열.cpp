//https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AYTAurfKJDEDFARs

//Tag: Bruteforce
//처음엔 많조분 떠올렸는데 제한이 작아서 그냥 가능한 조합을 다 보면 된다.
//백트래킹으로 봐도 되는데, 비트마스킹이 편해서 이렇게 짜보았다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int n,m;
int board[5][5];

void solve(int tc){
    string ans = "no";
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c; cin>>c;
            board[i][j] = c-'0';
        }
    }
    for(int i=0; i<(1<<(n+m)); i++){
        vector<int> v(n+m);
        int x=i, idx=0;
        while(x) v[idx++]=x%2, x/=2;
        vector<int> a(v.begin(), v.begin()+n);
        vector<int> b(v.begin()+n, v.end());

        bool isSame = true;
        for(int c=0; c<n; c++){
            for(int r=0; r<m; r++){
                if(board[c][r] != a[c]^b[r]) 
                    isSame = false;
            }
        }

        if(isSame){
            ans = "yes";
            break;
        }
    }
    cout<<'#'<<tc<<' '<<ans<<'\n';
}

int main(){
    fastio;
    int tc; cin>>tc;
    for(int i=1; i<=tc; i++) solve(i);
    return 0;
}
