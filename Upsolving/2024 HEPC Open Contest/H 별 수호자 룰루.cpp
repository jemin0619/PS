//애드혹 / 해 구성하기
//에디토리얼을 기반으로 풀었습니다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int N,K; cin>>N>>K;
    int groups = N/K;
    vector<int> team[groups];
    for(int i=0; i<N; i++) team[i/K].push_back(i+1);

    if(K%2==0){ //팀이 짝수로 이뤄지면 번호순 배정이 가능함
        cout<<"YES\n";
        for(int i=0; i<groups; i++){
            for(int val : team[i]) cout<<val<<' ';
            cout<<'\n';
        }
        return 0;
    }

    if(groups==1 || K==1) {cout<<"NO"; return 0;} //이 위치에서 이 조건을 사용해야 AC를 받는다.
    
    if(groups%2==0){ //두 그룹씩 묶어서 처리하면 됨
        for(int i=0; i<groups; i+=2){
            int a,b; a=i, b=i+1;
            bool fin = false;
            for(int j=0; j<(int)team[a].size() && !fin; j++){
                for(int k=0; k<(int)team[b].size() && !fin; k++){
                    if(team[a][j]%K == team[b][k]%K) continue;
                    swap(team[a][j], team[b][k]);
                    fin = true;
                }
            }
        }
    }
    else{ //처음에 세 그룹 묶고, 다음부터 두 그룹씩 묶어서 처리하면 됨
        bool fin = false;
        for(int i=0; i<(int)team[0].size() && !fin; i++){
            for(int j=0; j<(int)team[1].size() && !fin; j++){
                for(int k=0; k<(int)team[2].size() && !fin; k++){
                    if((team[0][i]%K == team[1][j]%K) || (team[1][j]%K == team[2][k]%K) || (team[2][k]%K == team[0][i]%K)) continue;
                    int tmp = team[0][i];
                    team[0][i] = team[2][k];
                    team[2][k] = team[1][j];
                    team[1][j] = tmp;
                    fin = true;
                }
            }
        }
        for(int i=3; i<groups; i+=2){
            int a,b; a=i; b=i+1;
            fin = false;
            for(int j=0; j<(int)team[a].size() && !fin; j++){
                for(int k=0; k<(int)team[b].size() && !fin; k++){
                    if(team[a][j]%K == team[b][k]%K) continue;
                    swap(team[a][j], team[b][k]);
                    fin = true;
                }
            }
        }
    }

    cout<<"YES\n";
    for(int i=0; i<groups; i++){
        for(int val : team[i]) cout<<val<<' ';
        cout<<'\n';
    }

    return 0;
}
