//가로방향 조합과 세로방향 조합을 각각 나누어 계산했습니다.
//경계에 걸쳐 포함되지 않는 문자열을 제외해야 했습니다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long
int N, M;

int main(){
    fastio;
    cin>>N;
    vector<vector<char>> board(N+1, vector<char>(N+1));
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            cin>>board[i][j];
    
    vector<vector<ll>> aa_R(N+1, vector<ll>(N+1));
    vector<vector<ll>> aa_D(N+1, vector<ll>(N+1));
    vector<vector<ll>> bb_R(N+1, vector<ll>(N+1));
    vector<vector<ll>> bb_D(N+1, vector<ll>(N+1));
    vector<vector<ll>> ab_R(N+1, vector<ll>(N+1));
    vector<vector<ll>> ab_D(N+1, vector<ll>(N+1));
    vector<vector<ll>> ba_R(N+1, vector<ll>(N+1));
    vector<vector<ll>> ba_D(N+1, vector<ll>(N+1));

    for(int i=1; i<=N; i++){ //세로
        for(int j=2; j<=N; j++){ //가로
            if(board[i][j-1]=='a' && board[i][j]=='a') aa_R[i][j]+=1;
            if(board[i][j-1]=='a' && board[i][j]=='b') ab_R[i][j]+=1;
            if(board[i][j-1]=='b' && board[i][j]=='a') ba_R[i][j]+=1;
            if(board[i][j-1]=='b' && board[i][j]=='b') bb_R[i][j]+=1;
        }
    }

    for(int j=1; j<=N; j++){ //가로
        for(int i=2; i<=N; i++){ //세로
            if(board[i-1][j]=='a' && board[i][j]=='a') aa_D[i][j]+=1;
            if(board[i-1][j]=='a' && board[i][j]=='b') ab_D[i][j]+=1;
            if(board[i-1][j]=='b' && board[i][j]=='a') ba_D[i][j]+=1;
            if(board[i-1][j]=='b' && board[i][j]=='b') bb_D[i][j]+=1;
        }
    }

    for(int i=1; i<=N; i++){ //세로
        for(int j=2; j<=N; j++){ //가로
            aa_R[i][j] += aa_R[i][j-1];
            ab_R[i][j] += ab_R[i][j-1];
            ba_R[i][j] += ba_R[i][j-1];
            bb_R[i][j] += bb_R[i][j-1];

            aa_D[i][j] += aa_D[i][j-1];
            ab_D[i][j] += ab_D[i][j-1];
            ba_D[i][j] += ba_D[i][j-1];
            bb_D[i][j] += bb_D[i][j-1];
        }
    }

    for(int j=1; j<=N; j++){ //가로
        for(int i=2; i<=N; i++){ //세로
            aa_R[i][j] += aa_R[i-1][j];
            ab_R[i][j] += ab_R[i-1][j];
            ba_R[i][j] += ba_R[i-1][j];
            bb_R[i][j] += bb_R[i-1][j];

            aa_D[i][j] += aa_D[i-1][j];
            ab_D[i][j] += ab_D[i-1][j];
            ba_D[i][j] += ba_D[i-1][j];
            bb_D[i][j] += bb_D[i-1][j];
        }
    }

    cin>>M;
    while(M--){
        int y1,x1,y2,x2; string S;
        cin>>y1>>x1>>y2>>x2>>S;
        ll ans = 0;
        if(S=="aa"){
            ans += (aa_R[y2][x2] + aa_R[y1-1][x1-1] - aa_R[y2][x1-1] - aa_R[y1-1][x2]);
            ans += (aa_D[y2][x2] + aa_D[y1-1][x1-1] - aa_D[y2][x1-1] - aa_D[y1-1][x2]);
            ans -= (aa_R[y2][x1] + aa_R[y1-1][x1-1] - aa_R[y2][x1-1] - aa_R[y1-1][x1]);
            ans -= (aa_D[y1][x2] + aa_D[y1-1][x1-1] - aa_D[y1][x1-1] - aa_D[y1-1][x2]);
        }
        if(S=="ab"){
            ans += (ab_R[y2][x2] + ab_R[y1-1][x1-1] - ab_R[y2][x1-1] - ab_R[y1-1][x2]);
            ans += (ab_D[y2][x2] + ab_D[y1-1][x1-1] - ab_D[y2][x1-1] - ab_D[y1-1][x2]);
            ans -= (ab_R[y2][x1] + ab_R[y1-1][x1-1] - ab_R[y2][x1-1] - ab_R[y1-1][x1]);
            ans -= (ab_D[y1][x2] + ab_D[y1-1][x1-1] - ab_D[y1][x1-1] - ab_D[y1-1][x2]);
        }
        if(S=="ba"){
            ans += (ba_R[y2][x2] + ba_R[y1-1][x1-1] - ba_R[y2][x1-1] - ba_R[y1-1][x2]);
            ans += (ba_D[y2][x2] + ba_D[y1-1][x1-1] - ba_D[y2][x1-1] - ba_D[y1-1][x2]);
            ans -= (ba_R[y2][x1] + ba_R[y1-1][x1-1] - ba_R[y2][x1-1] - ba_R[y1-1][x1]);
            ans -= (ba_D[y1][x2] + ba_D[y1-1][x1-1] - ba_D[y1][x1-1] - ba_D[y1-1][x2]);
        }
        if(S=="bb"){
            ans += (bb_R[y2][x2] + bb_R[y1-1][x1-1] - bb_R[y2][x1-1] - bb_R[y1-1][x2]);
            ans += (bb_D[y2][x2] + bb_D[y1-1][x1-1] - bb_D[y2][x1-1] - bb_D[y1-1][x2]);
            ans -= (bb_R[y2][x1] + bb_R[y1-1][x1-1] - bb_R[y2][x1-1] - bb_R[y1-1][x1]);
            ans -= (bb_D[y1][x2] + bb_D[y1-1][x1-1] - bb_D[y1][x1-1] - bb_D[y1-1][x2]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
