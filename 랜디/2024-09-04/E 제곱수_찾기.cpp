//8방향 이동이 아니라 등차수열로 이동하므로 경우의 수가 많아짐
//N, M이 작으므로 dy, dx를 2중 for문으로 설정 -> 5중 Loop으로 모든 문자열을 만들어냄
//그 문자열을 자르면서 완전제곱수인지 판단
//자르면서 길이 1의 문자열을 처리하지 않아서 96% WA

#include <bits/stdc++.h>
using namespace std;
#define fastio cin,tie(NULL)->sync_with_stdio(false)
#define ll long long

int main(){
    int N, M; cin>>N>>M;
    char board[12][12];
    map<string, bool> Mp;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin>>board[i][j];

    //모든 9자리 제곱수 전처리
    for(ll i=0; i*i<1e9; i++){
        string str = to_string(i*i);
        Mp[str] = true;
    }
    
    set<string> V;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            for(int dy=-10; dy<=10; dy++){
                for(int dx=-10; dx<=10; dx++){
                    if(dy==0 && dx==0) continue;
                    string S = "";
                    S += board[i][j];
                    int ny = i;
                    int nx = j;
                    while(true){
                        ny += dy;
                        nx += dx;
                        if(ny<0 || nx<0 || ny>=N || nx>=M){
                            V.insert(S);
                            break;
                        }
                        S += board[ny][nx];
                    }
                }
            }
        }
    }
    
    ll Ans = -1;

    for(string S : V){
        if(S.size()==1){
            if(Mp[S]) Ans = max(Ans, stoll(S));
            continue;
        }
        for(int gap=1; gap<S.size(); gap++){
            string str = "";
            for(int i=0; i<S.size(); i+=gap){
                str += S[i];
                if(Mp[str]){
                    ll tmp = stoll(str);
                    Ans = max(Ans ,tmp);
                }
            }
        }
    }

    cout<<Ans;
    return 0;
}
