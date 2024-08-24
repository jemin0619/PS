//이게 돌아갈까 걱정했는데 너무 잘 돌아가줬다.
//각 라운드에서 패배한 사람들의 수와 정보를 매개변수로 넣어주었다.
//백트래킹 구현할 때 매번 실수가 있었는데, 이건 실수 없이 잘 짰다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N, M, K;
string A[53];
vector<bool> Loser(53, false);
string ans = "";
string tmp = "";
string dx = "RSP";
string dy = "PRS";

void func(int k, vector<bool>&lose, int loseNum){
    if(ans != "" && tmp.size()>ans.size()) return;
    if(N - loseNum <= 0) return;
    if(N - loseNum <= K){
        if(tmp.size()<ans.size() || ans == "") ans = tmp;
        return;
    }
    if(k==M) return;

    for(int i=0; i<3; i++){
        tmp += dx[i];
        vector<int> funcTmp;
        for(int j=0; j<N; j++){
            if(lose[j]) continue;
            if(A[j][k]!=dy[i]){
                lose[j] = true;
                funcTmp.push_back(j);
            }
        }
        func(k+1, lose, loseNum+funcTmp.size());

        tmp.pop_back();
        for(int idx : funcTmp){
            lose[idx] = false;
        }
    }
}

int main(){
    fastio;
    cin>>N>>M>>K;
    for(int i=0; i<N; i++) cin>>A[i];
    func(0, Loser, 0);
    if(ans=="") cout<<-1;
    else cout<<ans.size()<<'\n'<<ans;
    return 0;
}
